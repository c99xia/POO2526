//
// Created by xiaro on 10/23/2025.
//

#ifndef PROJETO_JARDIM_H
#define PROJETO_JARDIM_H
#include "Posicao.h"


class Posicao;

class Jardim {
private:
    Posicao* Tabuleiro;
    int linhas;
    int colunas;

public:
    Jardim();
    ~Jardim();
    void inicializar(int l, int c);
    int getLinhas() const;
    int getColunas() const;
};


#endif //PROJETO_JARDIM_H
