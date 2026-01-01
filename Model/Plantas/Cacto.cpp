#include "Cacto.h"
#include "../Jardim.h"
#include "../Posicao.h"
#include "../../Utils/Settings.h"

Cacto::Cacto()
    : Planta(Beleza::neutra),
      nutrientesAcumCacto(0),
      aguaAcumCacto(0),
      contAguaSoloAlta(0),
      contNutrientesSoloZero(0) {
}

Cacto::Cacto(int nutrientes, int agua)
    : Planta(Beleza::neutra),
      nutrientesAcumCacto(nutrientes),
      aguaAcumCacto(agua),
      contAguaSoloAlta(0),
      contNutrientesSoloZero(0) {
}

//Absorção
/*
 *
 *
 *
 */
void Cacto::absorveAguaDoSolo(Posicao &pos) {
    int aguaSolo = pos.getAgua();
    if (aguaSolo <= 0)
        return;

    int absorverAgua =
            aguaSolo * Settings::Cacto::absorcao_agua_percentagem / 100;

    if (absorverAgua <= 0)
        return;

    pos.setAgua(aguaSolo - absorverAgua);
    aguaAcumCacto += absorverAgua;
}

void Cacto::absorveNutrientesDoSolo(Posicao &pos) {
    int nutrientesSolo = pos.getNutrientes();
    if (nutrientesSolo <= 0)
        return;

    int absorverNutrientes = Settings::Cacto::absorcao_nutrientes;
    if (absorverNutrientes > nutrientesSolo)
        absorverNutrientes = nutrientesSolo;

    pos.setNutrientes(nutrientesSolo - absorverNutrientes);
    nutrientesAcumCacto += absorverNutrientes;
}


//Morte do cacto
void Cacto::atualizaContadoresMorte(const Posicao &pos) {
    // água do solo demasiado alta
    if (pos.getAgua() > Settings::Cacto::morre_agua_solo_maior)
        ++contAguaSoloAlta;
    else
        contAguaSoloAlta = 0;

    // nutrientes do solo abaixo do limiar
    if (pos.getNutrientes() < Settings::Cacto::morre_nutrientes_solo_menor)
        ++contNutrientesSoloZero;
    else
        contNutrientesSoloZero = 0;
}

bool Cacto::deveMorrer() const {
    if (contAguaSoloAlta >= Settings::Cacto::morre_agua_solo_instantes)
        return true;

    if (contNutrientesSoloZero >
        Settings::Cacto::morre_nutrientes_solo_instantes)
        return true;

    return false;
}

void Cacto::morre(Posicao &pos) {
    // Ao morrer deixa no solo todos os nutrientes que absorveu
    pos.adicionaNutrientes(nutrientesAcumCacto);
    nutrientesAcumCacto = 0;
    morta = true;
}

//Cacto a multiplicar
bool Cacto::podeMultiplicar() const {
    return nutrientesAcumCacto > Settings::Cacto::multiplica_nutrientes_maior &&
           aguaAcumCacto > Settings::Cacto::multiplica_agua_maior;
}

//Aqui nasce um outro cacto
bool Cacto::tentaMultiplicarParaVizinhoLivre(Jardim &jardim, int linha, int coluna) {
    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    // Posições que ele pode assumir
    int direcaoLinha[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int direcaoColuna[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int nlinha = linha + direcaoLinha[i];
        int ncoluna = coluna + direcaoColuna[i];

        if (nlinha < 0 || nlinha >= linhas || ncoluna < 0 || ncoluna >= colunas)
            continue;

        Posicao &vizinha = jardim.getPosicao(nlinha, ncoluna);
        if (!vizinha.temPlanta()) {
            // dividir reservas com o "filho"
            int aguaFilho = aguaAcumCacto / 2;
            int nutrientesFilho = nutrientesAcumCacto / 2;

            aguaAcumCacto = aguaAcumCacto - aguaFilho;
            nutrientesAcumCacto = nutrientesAcumCacto - nutrientesFilho;

            Cacto *novo = new Cacto(nutrientesFilho, aguaFilho);
            vizinha.setPlanta(novo);

            return true;
        }
    }

    return false;
}

// Atualização para cada instante quando avança um instante essa função é chamada.
void Cacto::atualiza(Jardim &jardim, int linha, int coluna) {
    if (morta)
        return;

    Posicao &pos = jardim.getPosicao(linha, coluna); //Obtém a posição do cacto

    //Absorver do solo
    absorveAguaDoSolo(pos); //absorve a água da posição em questão
    absorveNutrientesDoSolo(pos); //absorve os nutrientes e água da posiçãpo em questão

    //Atualizar contadores de morte e verificar se deve morrer
    atualizaContadoresMorte(pos); //Se houver água a mais no solo, incrementa um contador.
    //Se o contador chegar a 3, deveMorrer() devolve true.
    if (deveMorrer()) {
        morre(pos);
        return;
    }

    // Tentar multiplicação para vizinho livre
    if (podeMultiplicar()) {
        tentaMultiplicarParaVizinhoLivre(jardim, linha, coluna);
        /*
         * Verifica as 8 posições à volta. Se achar uma Posicao onde !vizinha.temPlanta(),
         * cria um new Cacto e coloca-o lá.
         *
         *
         */
    }
}
