#ifndef PROJETO_CMDENTRAJARDINEIRO_H
#define PROJETO_CMDENTRAJARDINEIRO_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"
#include <cctype>

class cmdEntraJardineiro : public Comando {
    int linha, coluna;

public:
    cmdEntraJardineiro(int linha, int coluna);
    std::string nome() const override { return "entra"; }
    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDENTRAJARDINEIRO_H