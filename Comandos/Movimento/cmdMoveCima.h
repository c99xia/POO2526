//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDMOVECIMA_H
#define PROJETO_CMDMOVECIMA_H
#include "../Comando.h"


class cmdMoveCima : public Comando {
    char tecla;

public:
    cmdMoveCima(char tecla);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDMOVECIMA_H
