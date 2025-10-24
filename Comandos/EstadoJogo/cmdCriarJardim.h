//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDCRIARJARDIM_H
#define PROJETO_CMDCRIARJARDIM_H
#include "../Comando.h"


class cmdCriarJardim : public Comando {
    int linha, coluna;

public:
    cmdCriarJardim(int linha, int coluna);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDCRIARJARDIM_H
