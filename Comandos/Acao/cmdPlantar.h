//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDPLANTAR_H
#define PROJETO_CMDPLANTAR_H
#include "../Comando.h"



class cmdPlantar : public Comando {
    char linha, coluna, tipo_planta;
    public:
    cmdPlantar(char linha, char coluna, char tipo_planta);
    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDPLANTAR_H
