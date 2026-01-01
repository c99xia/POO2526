#ifndef PROJETO_CMDFIM_H
#define PROJETO_CMDFIM_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdFim : public Comando {
public:
    cmdFim()=default;
    std::string nome() const override { return "fim"; }
    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDFIM_H