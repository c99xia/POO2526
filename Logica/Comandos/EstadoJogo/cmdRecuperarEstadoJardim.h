//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDRECUPERARESTADOJARDIM_H
#define PROJETO_CMDRECUPERARESTADOJARDIM_H
#include <string>

#include "../Comando.h"


class cmdRecuperarEstadoJardim : public Comando {
    std::string nome;

public:
    cmdRecuperarEstadoJardim(const std::string& nome);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDRECUPERARESTADOJARDIM_H
