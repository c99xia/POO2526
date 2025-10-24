//
// Created by xiaro on 10/23/2025.
//

#ifndef PROJETO_JARDINEIRO_H
#define PROJETO_JARDINEIRO_H
#include <vector>

#include "Ferramentas/Ferramenta.h"


class Jardineiro {
    int linha, coluna;
    Ferramenta *FerramentaNaMao;
    std::vector<Ferramenta *> ferramentas;
    int contadorMovimentosRestantes;
    int contadorPlantacoesRestantes;
    int contadorColheitasRestantes;
};


#endif //PROJETO_JARDINEIRO_H