//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_SIMULADOR_H
#define PROJETO_SIMULADOR_H
#include "Jardim.h"
#include "Jardineiro.h"
#include "../Interface/Interface.h"
#include "../Comandos/ProcessaCMD.h"


class Simulador {
    Jardim jardim;
    Jardineiro jardineiro;
    Interface interface;
    bool jogoAtivo;
    ProcessaCMD processaCMD;

    public:
    Simulador();
    void iniciarJogo();
};


#endif //PROJETO_SIMULADOR_H