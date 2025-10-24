//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
#define PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
#include "../Comando.h"


class cmdListarPropriedadesPlantaPosicao : public Comando {
    char linha, coluna;

public:
    cmdListarPropriedadesPlantaPosicao(char linha, char coluna);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLISTARPROPRIEDADESPLANTAPOSICAO_H
