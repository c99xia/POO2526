//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDCOMPRARFERRAMENTA_H
#define PROJETO_CMDCOMPRARFERRAMENTA_H
#include "../Comando.h"


class cmdComprarFerramenta : public Comando {
    char ferramenta;

public:
    cmdComprarFerramenta(char ferramenta);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDCOMPRARFERRAMENTA_H
