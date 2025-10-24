//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDMOVEBAIXO_H
#define PROJETO_CMDMOVEBAIXO_H
#include "../Comando.h"


class cmdMoveBaixo : public Comando {
    char tecla;

public:
    cmdMoveBaixo(char tecla);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDMOVEBAIXO_H
