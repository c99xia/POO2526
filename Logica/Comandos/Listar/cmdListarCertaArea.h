//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLISTARCERTAAREA_H
#define PROJETO_CMDLISTARCERTAAREA_H
#include "../Comando.h"


class cmdListarCertaArea : public Comando {
    char linha, coluna;
    int raio;

public:
    cmdListarCertaArea(char linha, char coluna, int raio);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLISTARCERTAAREA_H
