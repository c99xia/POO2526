#ifndef PROJETO_CMDEXECUTACMDTESTE_H
#define PROJETO_CMDEXECUTACMDTESTE_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"


class cmdExecutaCmdTeste : public Comando {
    std::string nome_do_ficheiro;

public:
    cmdExecutaCmdTeste(const std::string& nome_do_ficheiro);

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDEXECUTACMDTESTE_H