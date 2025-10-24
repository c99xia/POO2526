//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDFIM_H
#define PROJETO_CMDFIM_H
#include "../Comando.h"


class cmdFim : public Comando {
public:
    cmdFim();

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDFIM_H
