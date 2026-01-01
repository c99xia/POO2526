//
// Created by xiaro on 10/23/2025.
//

#ifndef PROJETO_M4RG4RID4_H
#define PROJETO_M4RG4RID4_H
#include "Planta.h"
#include "../Jardim.h"


class M4rg4rid4 : public Planta {
    int nutrientesAcumM4rg4rid4, aguaAcumM4rg4rid4, instantesVividos;

public:
    M4rg4rid4();

    char getChar() const override { return 'x'; }

    void atualiza(Jardim &jardim, int linha, int coluna) override;
};


#endif //PROJETO_M4RG4RID4_H
