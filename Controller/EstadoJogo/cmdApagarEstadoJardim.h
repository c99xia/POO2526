#ifndef PROJETO_CMDAPAGARESTADOJARDIM_H
#define PROJETO_CMDAPAGARESTADOJARDIM_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdApagarEstadoJardim : public Comando {
    std::string nome;

public:
    cmdApagarEstadoJardim(const std::string& nome);

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDAPAGARESTADOJARDIM_H