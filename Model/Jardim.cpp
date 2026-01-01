#include "Jardim.h"
#include "../Utils/Settings.h"
#include "../Utils/Random.h"

Jardim::Jardim()
    : Tabuleiro(nullptr),
    linhas(0),
    colunas(0)
{
}

void Jardim::inicializar(int l, int c) {
    linhas = l;
    colunas = c;

    if (linhas <= 0 || colunas <= 0) {
        Tabuleiro.reset();
        linhas = 0;
        colunas = 0;
        return;
    }

    Tabuleiro = std::make_unique<Posicao[]>(linhas * colunas);

    // inicializar água e nutrientes
    for (int i = 0; i < linhas * colunas; ++i) {
        int agua = Random::getRandom(Settings::Jardim::agua_min,
            Settings::Jardim::agua_max);
        int nutrientes = Random::getRandom(Settings::Jardim::nutrientes_min,
            Settings::Jardim::nutrientes_max);

        Tabuleiro[i].setAgua(agua);
        Tabuleiro[i].setNutrientes(nutrientes);
    }
}

