#ifndef PROJETO_CMDCOLHERPLANTA_H
#define PROJETO_CMDCOLHERPLANTA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"
#include <cctype>


class cmdColherPlanta : public Comando {
    int linha, coluna;

public:
    cmdColherPlanta(int linha, int coluna);
    std::string nome() const override { return "colhe"; }
    void executa(Simulador& simulador) override;
    static Comando* criar(std::istringstream& iss);
};
#endif //PROJETO_CMDCOLHERPLANTA_H