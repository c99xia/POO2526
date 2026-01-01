#ifndef PROJETO_ROSEIRA_H
#define PROJETO_ROSEIRA_H

#include "Planta.h"
#include "../Jardim.h"

class Roseira : public Planta {
    int nutrientesAcumRoseira;
    int aguaAcumRoseira;
    int instantesVividos;

public:
    Roseira();

    char getChar() const override { return 'r'; }
    void atualiza(Jardim& jardim, int linha, int coluna) override;
};

#endif //PROJETO_ROSEIRA_H
