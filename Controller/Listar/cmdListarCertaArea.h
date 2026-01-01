#ifndef PROJETO_CMDLISTARCERTAAREA_H
#define PROJETO_CMDLISTARCERTAAREA_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"
#include <cctype>

class cmdListarCertaArea : public Comando {
    int linha, coluna, raio;

public:
    cmdListarCertaArea(int linha, int coluna, int raio);

    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDLISTARCERTAAREA_H