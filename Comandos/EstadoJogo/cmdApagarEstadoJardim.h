//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDAPAGARESTADOJARDIM_H
#define PROJETO_CMDAPAGARESTADOJARDIM_H
#include "../Comando.h"


class cmdApagarEstadoJardim : public Comando {
    std::string nome;

public:
    cmdApagarEstadoJardim(std::string nome);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDAPAGARESTADOJARDIM_H
