#ifndef PROJETO_CMDPEGARFERRAMENTA_H
#define PROJETO_CMDPEGARFERRAMENTA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdPegarFerramenta : public Comando {
    int numeroSerie;

public:
    cmdPegarFerramenta(int numeroSerie);
    std::string nome() const override { return "pega"; }

    void executa(Simulador& simulador) override;;

    static Comando* criar(std::istringstream& iss);
};
#endif //PROJETO_CMDPEGARFERRAMENTA_H