//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_SIMULADOR_H
#define PROJETO_SIMULADOR_H
#include "../Modelo/Jardim.h"
#include "../Modelo/Jardineiro.h"
#include "../Interface/Interface.h"


class Simulador {
    Jardim jardim;
    Jardineiro jardineiro;
    Interface interface;
    bool jogoAtivo;

    public:
    Simulador();
    void iniciarJogo();

};


#endif //PROJETO_SIMULADOR_H