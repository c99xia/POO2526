#ifndef PROJETO_CMDLISTARAREA_H
#define PROJETO_CMDLISTARAREA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdListarArea : public Comando {
public:
    cmdListarArea() = default;
    std::string nome() const override { return "larea"; }

    void executa(Simulador& simulador) override;
    static Comando* criar(std::istringstream& iss);
};
#endif //PROJETO_CMDLISTARAREA_H