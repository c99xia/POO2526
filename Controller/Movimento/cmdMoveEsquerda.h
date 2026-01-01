#ifndef PROJETO_CMDMOVEESQUERDA_H
#define PROJETO_CMDMOVEESQUERDA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdMoveEsquerda : public Comando {
public:
    cmdMoveEsquerda() = default;

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDMOVEESQUERDA_H