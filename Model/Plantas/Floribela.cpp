#include "Floribela.h"
#include "../Posicao.h"
#include "../Jardim.h"


Floribela::Floribela()
    : Planta(Beleza::linda),   // Planta exótica é linda/bonita
    nutrientesAcumFloribela(10),
    aguaAcumFloribela(10),
    instantesVividos(0)
{
}

void Floribela::purificarVizinhos(Jardim& jardim, int linha, int coluna) {
    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    // 8 direções vizinhas (raio 1)
    int dl[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int dc[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; ++i) {
        int nl = linha + dl[i];
        int nc = coluna + dc[i];

        // Verificar limites
        if (nl < 0 || nl >= linhas || nc < 0 || nc >= colunas)
            continue;

        Posicao& vizinha = jardim.getPosicao(nl, nc);
        Planta* plantaVizinha = vizinha.getPlanta();

        // Se existe planta vizinha viva e é feia, transforma em linda
        if (plantaVizinha != nullptr &&
            !plantaVizinha->estaMorta() &&
            plantaVizinha->getBeleza() == Beleza::feia) {

            plantaVizinha->setBeleza(Beleza::linda);
        }
    }
}

void Floribela::atualiza(Jardim& jardim, int linha, int coluna) {
    if (morta)
        return;

    ++instantesVividos;

    Posicao& pos = jardim.getPosicao(linha, coluna);

    // 1) Absorver água e nutrientes do solo (comportamento básico)
    int aguaSolo = pos.getAgua();
    if (aguaSolo > 0) {
        int absorver = 2; // absorve pouco
        if (absorver > aguaSolo) absorver = aguaSolo;
        pos.setAgua(aguaSolo - absorver);
        aguaAcumFloribela += absorver;
    }

    int nutSolo = pos.getNutrientes();
    if (nutSolo > 0) {
        int absorver = 2; // absorve pouco
        if (absorver > nutSolo) absorver = nutSolo;
        pos.setNutrientes(nutSolo - absorver);
        nutrientesAcumFloribela += absorver;
    }

    // 2) Verificar morte: morre se ficar sem água ou nutrientes internos
    if (aguaAcumFloribela <= 0 || nutrientesAcumFloribela <= 0) {
        // Ao morrer devolve metade dos nutrientes ao solo
        pos.adicionaNutrientes(nutrientesAcumFloribela / 2);
        morta = true;
        return;
    }

    // 3) Efeito especial: "purificar" plantas feias vizinhas (transformar em lindas)
    purificarVizinhos(jardim, linha, coluna);

    // 4) Perda natural de recursos (gasta energia a purificar)
    aguaAcumFloribela -= 1;
    nutrientesAcumFloribela -= 1;
}
