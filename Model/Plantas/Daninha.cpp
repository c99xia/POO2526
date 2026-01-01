#include "Daninha.h"
#include "../Jardim.h"
#include "../Posicao.h"
#include "../../Utils/Settings.h"
#include "../../Utils/Random.h"
#include <memory>

Daninha::Daninha()
    : Planta(Beleza::feia),
    nutrientesAcumDaninha(Settings::ErvaDaninha::inicial_nutrientes),
    aguaAcumDaninha(Settings::ErvaDaninha::inicial_agua),
    instantesVividos(0)
{
}

void Daninha::atualiza(Jardim& jardim, int linha, int coluna) {
    if (morta)
        return;

    ++instantesVividos;

    Posicao& pos = jardim.getPosicao(linha, coluna);

    // 1) Absorve um bocadinho do solo
    int aguaSolo = pos.getAgua();
    if (aguaSolo > 0) {
        int absorver = Settings::ErvaDaninha::absorcao_agua;
        if (absorver > aguaSolo)
            absorver = aguaSolo;
        pos.setAgua(aguaSolo - absorver);
        aguaAcumDaninha += absorver;
    }

    int nutSolo = pos.getNutrientes();
    if (nutSolo > 0) {
        int absorver = Settings::ErvaDaninha::absorcao_nutrientes;
        if (absorver > nutSolo)
            absorver = nutSolo;
        pos.setNutrientes(nutSolo - absorver);
        nutrientesAcumDaninha += absorver;
    }

    // 2) Morre ao fim de N instantes
    if (instantesVividos >= Settings::ErvaDaninha::morre_instantes) {
        // Ao morrer devolve tudo ao solo
        pos.adicionaAgua(aguaAcumDaninha);
        pos.adicionaNutrientes(nutrientesAcumDaninha);

        aguaAcumDaninha = 0;
        nutrientesAcumDaninha = 0;
        morta = true;
        return;
    }

    // 3) Tentar multiplicar de X em X instantes
    if (instantesVividos % Settings::ErvaDaninha::multiplica_instantes != 0)
        return; // ainda n o   altura de multiplicar

    // CORRIGIDO: Verificar nutrientes INTERNOS da planta (n o do solo)
    // Enunciado: "Multiplica-se a cada 5 instantes se nutrientes > 30"
    if (nutrientesAcumDaninha <= Settings::ErvaDaninha::multiplica_nutrientes_maior)
        return; // n o tem nutrientes internos suficientes

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    int dl[8] = { -1,-1,-1, 0,0, 1,1,1 };
    int dc[8] = { -1, 0, 1,-1,1,-1,0,1 };

    // PRIMEIRO: Matar todas as plantas vizinhas (conforme enunciado)
    // "Mata plantas vizinhas ao multiplicar"
    for (int i = 0; i < 8; ++i) {
        int nl = linha + dl[i];
        int nc = coluna + dc[i];

        if (nl < 0 || nl >= linhas || nc < 0 || nc >= colunas)
            continue;

        Posicao& viz = jardim.getPosicao(nl, nc);
        Planta* plantaVizinha = viz.getPlanta();

        if (plantaVizinha != nullptr && !plantaVizinha->estaMorta()) {
            viz.removePlanta();
        }
    }

    // DEPOIS: Recolher vizinhos livres (8 dire  es) para colocar nova daninha
    struct Coord {
        int l;
        int c;
    };

    Coord livres[8];
    int nLivres = 0;

    for (int i = 0; i < 8; ++i) {
        int nl = linha + dl[i];
        int nc = coluna + dc[i];

        if (nl < 0 || nl >= linhas || nc < 0 || nc >= colunas)
            continue;

        Posicao& viz = jardim.getPosicao(nl, nc);
        if (!viz.temPlanta()) {
            livres[nLivres].l = nl;
            livres[nLivres].c = nc;
            ++nLivres;
        }
    }

    if (nLivres == 0)
        return; // n o h  espa o para multiplicar

    // Escolher uma posi  o livre aleat ria
    int idx = Random::getRandom(0, nLivres - 1);
    Coord escolhido = livres[idx];

    Posicao& dest = jardim.getPosicao(escolhido.l, escolhido.c);

    // Nutrientes para a nova daninha (v m da planta m e)
    int nutrientesNovo = Settings::ErvaDaninha::nova_nutrientes;
    if (nutrientesNovo > nutrientesAcumDaninha)
        nutrientesNovo = nutrientesAcumDaninha;

    nutrientesAcumDaninha -= nutrientesNovo;

    auto nova = std::make_unique<Daninha>();
    nova->nutrientesAcumDaninha = nutrientesNovo;
    nova->aguaAcumDaninha = Settings::ErvaDaninha::inicial_agua;

    dest.setPlanta(std::move(nova));
}

