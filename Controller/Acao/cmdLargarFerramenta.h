#ifndef PROJETO_CMDLARGARFERRAMENTA_H
#define PROJETO_CMDLARGARFERRAMENTA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdLargarFerramenta : public Comando {
public:
    cmdLargarFerramenta() = default;

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDLARGARFERRAMENTA_H