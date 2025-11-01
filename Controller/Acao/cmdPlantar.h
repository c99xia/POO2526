//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDPLANTAR_H
#define PROJETO_CMDPLANTAR_H
#include "../Comando.h"


class cmdPlantar : public Comando {
    int linha, coluna;
    char tipo_planta;

public:
    cmdPlantar(int linha, int coluna, char tipo_planta);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDPLANTAR_H
