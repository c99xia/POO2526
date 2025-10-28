//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
#define PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
#include "../Comando.h"


class cmdListarPropriedadesPlantaPosicao : public Comando {
    int linha, coluna;

public:
    cmdListarPropriedadesPlantaPosicao(int linha, int coluna);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
