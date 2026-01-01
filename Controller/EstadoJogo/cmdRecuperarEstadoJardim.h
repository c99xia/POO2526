#ifndef PROJETO_CMDRECUPERARESTADOJARDIM_H
#define PROJETO_CMDRECUPERARESTADOJARDIM_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdRecuperarEstadoJardim : public Comando {
    std::string nomeF;

public:
    cmdRecuperarEstadoJardim(const std::string& nome);
    std::string nome() const override { return "recupera"; }
    void executa(Simulador& simulador) override;
    static Comando* criar(std::istringstream& iss);
};
#endif //PROJETO_CMDRECUPERARESTADOJARDIM_H
