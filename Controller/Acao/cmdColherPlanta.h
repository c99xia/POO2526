//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDCOLHERPLANTA_H
#define PROJETO_CMDCOLHERPLANTA_H
#include "..\Comando.h"


class cmdColherPlanta : public Comando {
    int linha, coluna;

public:
    cmdColherPlanta(int linha, int coluna);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDCOLHERPLANTA_H
