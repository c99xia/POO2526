//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDGRAVARESTADOJARDIM_H
#define PROJETO_CMDGRAVARESTADOJARDIM_H
#include <string>

#include "../Comando.h"


class cmdGravarEstadoJardim : public Comando {
    std::string nome;

public:
    cmdGravarEstadoJardim(std::string nome);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDGRAVARESTADOJARDIM_H
