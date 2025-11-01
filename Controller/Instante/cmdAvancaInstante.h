//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDAVANCAINSTANTE_H
#define PROJETO_CMDAVANCAINSTANTE_H
#include "../Comando.h"


class cmdAvancaInstante : public Comando {
    int n;

public:
    cmdAvancaInstante(int n);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDAVANCAINSTANTE_H
