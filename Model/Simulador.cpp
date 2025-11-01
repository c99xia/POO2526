//
// Created by xiaro on 10/24/2025.
//

#include "Simulador.h"


Simulador::Simulador() : jogoAtivo(true) {}

const Jardim& Simulador::getJardim() const {
    return this->jardim;
}

bool Simulador::isJogoAtivo() const {
    return this->jogoAtivo;
}

void Simulador::criarJardim(int linha, int coluna) {
    jardim.inicializar(linha, coluna);
}

void Simulador::terminarJogo() {
    this->jogoAtivo = false;
}
