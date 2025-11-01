//
// Created by xiaro on 10/24/2025.
//

#include "cmdCriarJardim.h"
#include "../../Model/Simulador.h"


cmdCriarJardim::cmdCriarJardim(int linha, int coluna) : linha(linha), coluna(coluna) {}

void cmdCriarJardim::executa(Simulador &simulador) {
    simulador.criarJardim(this->linha, this->coluna);
}