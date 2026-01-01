#ifndef PROJETO_CMDMOVEBAIXO_H
#define PROJETO_CMDMOVEBAIXO_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdMoveBaixo : public Comando {
public:
    cmdMoveBaixo() = default;

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};

#endif //PROJETO_CMDMOVEBAIXO_H