//
// Created by xiaro on 10/23/2025.
//

#include "Jardim.h"
#include "Posicao.h"
#include "../Utils/Settings.h"
#include "../Utils/Random.h"

Jardim::Jardim()
    : Tabuleiro(nullptr),
      linhas(0),
      colunas(0)
{

}

Jardim::~Jardim() {
    delete[] Tabuleiro; //Como alocamos memória dinamicamente no heap com new [] temos que eliminar
}

void Jardim::inicializar(int l, int c) {
    // Apagar o tabuleiro caso exista
    delete[] Tabuleiro;
    Tabuleiro = nullptr;

    linhas = l;
    colunas = c;

    if (linhas <= 0 || colunas <= 0) {
        // linhas e colunas negativas então não há tabela
        return;
    }

    // Criar o tabuleiro
    Tabuleiro = new Posicao[linhas * colunas]; //O jardim é guardado num array único e contínuo na memória
    //

    // Iniciar os valores de água e de nutrientes em cada posição com valores aleatórios definidos no ficheiro do professor settings.h
    for (int i = 0; i < linhas * colunas; ++i) {
        int agua = Random::getRandom(Settings::Jardim::agua_min,
                                     Settings::Jardim::agua_max);
        int nutrientes = Random::getRandom(Settings::Jardim::nutrientes_min,
                                           Settings::Jardim::nutrientes_max);

        Tabuleiro[i].setAgua(agua); //por cada posição fazemos um set do valor da água
        Tabuleiro[i].setNutrientes(nutrientes); // e também fazemos um set do valor de nutrientes
    }

    // Mais tarde aqui também poderás:
    // - colocar as 3 ferramentas iniciais em posições aleatórias
    // - eventualmente colocar plantas iniciais, se decidires
}

