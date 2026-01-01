#ifndef PROJETO_CMDGRAVARESTADOJARDIM_H
#define PROJETO_CMDGRAVARESTADOJARDIM_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdGravarEstadoJardim : public Comando {
    std::string nomeF;

public:
    cmdGravarEstadoJardim(const std::string& nome);
    std::string nome() const override { return "grava"; }
    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDGRAVARESTADOJARDIM_H