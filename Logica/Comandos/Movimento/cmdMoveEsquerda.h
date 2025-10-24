//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDMOVEESQUERDA_H
#define PROJETO_CMDMOVEESQUERDA_H
#include "../Comando.h"


class cmdMoveEsquerda : public Comando {
public:
    cmdMoveEsquerda();

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDMOVEESQUERDA_H
