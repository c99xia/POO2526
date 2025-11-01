//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDENTRAJARDINEIRO_H
#define PROJETO_CMDENTRAJARDINEIRO_H
#include "../Comando.h"

class cmdEntraJardineiro : public Comando {
    int linha, coluna;

public:
    cmdEntraJardineiro(int linha, int coluna);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDENTRAJARDINEIRO_H
