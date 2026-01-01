#ifndef PROJETO_JARDIM_H
#define PROJETO_JARDIM_H

#include "Posicao.h"
#include <memory>

class Jardim {
    std::unique_ptr<Posicao[]> Tabuleiro;
    int linhas;
    int colunas;

public:
    Jardim();
    ~Jardim() = default;

    void inicializar(int l, int c);

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }

    Posicao& getPosicao(int linha, int coluna) {
        return Tabuleiro[linha * colunas + coluna];
    }

    const Posicao& getPosicao(int linha, int coluna) const {
        return Tabuleiro[linha * colunas + coluna];
    }
};

#endif // PROJETO_JARDIM_H
