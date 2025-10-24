//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDSAIJARDINEIRO_H
#define PROJETO_CMDSAIJARDINEIRO_H
#include "../Comando.h"


class cmdSaiJardineiro : public Comando {
public:
    cmdSaiJardineiro() = default;

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDSAIJARDINEIRO_H
