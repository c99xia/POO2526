//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLISTARCERTAAREA_H
#define PROJETO_CMDLISTARCERTAAREA_H
#include "../Comando.h"


class cmdListarCertaArea : public Comando {
    int linha, coluna, raio;

public:
    cmdListarCertaArea(int linha, int coluna, int raio);

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLISTARCERTAAREA_H
