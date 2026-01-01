#ifndef PROJETO_CMDPLANTAR_H
#define PROJETO_CMDPLANTAR_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdPlantar : public Comando {
    int linha, coluna;
    char tipo_planta;

public:
    cmdPlantar(int linha, int coluna, char tipo_planta);

    void executa(Simulador &simulador) override;

    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDPLANTAR_H