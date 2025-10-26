//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLARGARFERRAMENTA_H
#define PROJETO_CMDLARGARFERRAMENTA_H
#include "../Comando.h"


class cmdLargarFerramenta : public Comando {
public:
    cmdLargarFerramenta();

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLARGARFERRAMENTA_H
