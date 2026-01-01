#ifndef PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
#define PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdListarPropriedadesPlantaPosicao : public Comando {
    int linha, coluna;

public:
    std::string nome() const override { return "lplanta"; }

    cmdListarPropriedadesPlantaPosicao(int linha, int coluna);

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};

#endif //PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H