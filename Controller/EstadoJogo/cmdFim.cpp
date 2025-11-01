//
// Created by xiaro on 10/24/2025.
//

#include "cmdFim.h"
#include "../../Model/Simulador.h"

void cmdFim::executa(Simulador &simulador) {
    simulador.terminarJogo();
}