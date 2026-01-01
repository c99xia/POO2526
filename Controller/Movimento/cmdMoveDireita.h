#ifndef PROJETO_CMDMOVEDIREITA_H
#define PROJETO_CMDMOVEDIREITA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdMoveDireita : public Comando {
public:
    cmdMoveDireita() = default;

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDMOVEDIREITA_H