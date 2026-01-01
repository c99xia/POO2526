#ifndef PROJETO_CMDSAIJARDINEIRO_H
#define PROJETO_CMDSAIJARDINEIRO_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdSaiJardineiro : public Comando {
public:
    cmdSaiJardineiro() = default;

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};


#endif //PROJETO_CMDSAIJARDINEIRO_H
