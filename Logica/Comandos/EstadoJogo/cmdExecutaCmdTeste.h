//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDEXECUTACMDTESTE_H
#define PROJETO_CMDEXECUTACMDTESTE_H
#include <string>

#include "../Comando.h"


class cmdExecutaCmdTeste : public Comando {
    std::string nome_do_ficheiro;

public:
    cmdExecutaCmdTeste(const std::string& nome_do_ficheiro);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDEXECUTACMDTESTE_H
