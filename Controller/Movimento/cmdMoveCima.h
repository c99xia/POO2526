#ifndef PROJETO_CMDMOVECIMA_H
#define PROJETO_CMDMOVECIMA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdMoveCima : public Comando {
public:
    cmdMoveCima() = default;
    std::string nome() const override { return "c"; }

    void executa(Simulador& simulador) override;
    static Comando* criar(std::istringstream& iss);
};
#endif //PROJETO_CMDMOVECIMA_H