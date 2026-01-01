#ifndef PROJETO_CMDLISTARFERRAMENTAS_H
#define PROJETO_CMDLISTARFERRAMENTAS_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdListarFerramentas : public Comando {
public:
    cmdListarFerramentas() = default;

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};


#endif //PROJETO_CMDLISTARFERRAMENTAS_H
