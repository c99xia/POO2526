//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDCOLHERPLANTA_H
#define PROJETO_CMDCOLHERPLANTA_H
#include "../Comando.h"


class cmdColherPlanta : public Comando {
    char linha, coluna;

public:
    cmdColherPlanta(char linha, char coluna);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDCOLHERPLANTA_H
