#ifndef PROJETO_CMDCOMPRARFERRAMENTA_H
#define PROJETO_CMDCOMPRARFERRAMENTA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdComprarFerramenta : public Comando {
    char ferramenta;

public:
    cmdComprarFerramenta(char ferramenta);
    std::string nome() const override { return "compra"; }
    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDCOMPRARFERRAMENTA_H