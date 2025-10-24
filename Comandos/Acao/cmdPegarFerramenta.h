//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDPEGARFERRAMENTA_H
#define PROJETO_CMDPEGARFERRAMENTA_H
#include "../Comando.h"


class cmdPegarFerramenta : public Comando {
    int numeroSerie;

public:
    cmdPegarFerramenta(int numeroSeria);

    void executa(Simulador &simulador) override;;

};


#endif //PROJETO_CMDPEGARFERRAMENTA_H
