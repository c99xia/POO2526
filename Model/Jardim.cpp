//
// Created by xiaro on 10/23/2025.
//

#include "Jardim.h"
#include "Posicao.h" // Inclua aqui se precisar de aceder a membros de Posicao

Jardim::Jardim() : Tabuleiro(nullptr), linhas(0), colunas(0) {}

Jardim::~Jardim() {
    delete[] Tabuleiro;
}

void Jardim::inicializar(int l, int c) {
    delete[] Tabuleiro;
    this->linhas = l;
    this->colunas = c;
    // Apenas aloca. Não precisa de inicializar cada posição para a Meta 1.
    this->Tabuleiro = new Posicao[linhas * colunas];
}

int Jardim::getLinhas() const { return linhas; }
int Jardim::getColunas() const { return colunas; }
