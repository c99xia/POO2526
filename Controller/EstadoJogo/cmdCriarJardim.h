#ifndef PROJETO_CMDCRIARJARDIM_H
#define PROJETO_CMDCRIARJARDIM_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdCriarJardim : public Comando {
    int linha, coluna;

public:
    cmdCriarJardim(int linha, int coluna);

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDCRIARJARDIM_H