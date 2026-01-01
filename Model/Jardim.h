#ifndef PROJETO_JARDIM_H
#define PROJETO_JARDIM_H

#include "Posicao.h"

class Posicao;

class Jardim {
    Posicao* Tabuleiro; //Um ponteiro simples, não um vetor
    int linhas;
    int colunas;

public:
    Jardim();
    ~Jardim();

    void inicializar(int l, int c);

    int getLinhas() const {return linhas;}
    int getColunas() const {return colunas;}

    // Acesso a uma posição (não const e const) porquê temos isso de const e um não const?
    // Como é getPosição não poderia ser só const já que não iremos alterar o estado? Apenas de acesso?
    Posicao& getPosicao(int linha, int coluna) {return Tabuleiro[linha * colunas + coluna];} //ao multiplicar-se a linha atual pela largura do jardim e soma-se a coluna.
    //É assim que se mapeia 2D para 1D.
    const Posicao& getPosicao(int linha, int coluna) const {return Tabuleiro[linha * colunas + coluna];}
};

#endif //PROJETO_JARDIM_H
