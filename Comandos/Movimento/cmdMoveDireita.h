//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDMOVEDIREITA_H
#define PROJETO_CMDMOVEDIREITA_H
#include "../Comando.h"


class cmdMoveDireita : public Comando {
    char tecla;

public:
    cmdMoveDireita(char tecla);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDMOVEDIREITA_H
