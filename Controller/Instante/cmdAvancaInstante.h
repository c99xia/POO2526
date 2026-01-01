#ifndef PROJETO_CMDAVANCAINSTANTE_H
#define PROJETO_CMDAVANCAINSTANTE_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdAvancaInstante : public Comando {
    int instante;

public:
    cmdAvancaInstante(int instante);
    void executa(Simulador &sim) override;
    std::string nome() const override { return "planta"; }
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDAVANCAINSTANTE_H