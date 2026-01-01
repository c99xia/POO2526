#ifndef PROJETO_DANINHA_H
#define PROJETO_DANINHA_H

#include "Planta.h"
#include "../Jardim.h"


class Daninha : public Planta {
    int nutrientesAcumDaninha;
    int aguaAcumDaninha;
    int instantesVividos;  // quantos instantes já viveu

public:
    Daninha();

    char getChar() const override { return 'e'; }
    void atualiza(Jardim &jardim, int linha, int coluna) override;
};

#endif // PROJETO_DANINHA_H
