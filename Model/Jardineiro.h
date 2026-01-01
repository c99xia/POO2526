#ifndef PROJETO_JARDINEIRO_H
#define PROJETO_JARDINEIRO_H

#include <vector>
#include "Ferramentas/Ferramenta.h"

class Jardineiro {
    int linha;
    int coluna;
    bool presente;

    Ferramenta *ferramentaNaMao;
    std::vector<Ferramenta *> ferramentas;

    int movimentosRestantes;
    int plantacoesRestantes;
    int colheitasRestantes;

public:
    Jardineiro();

    bool estaPresente() const { return presente; }
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }

    int getMovimentosRestantes() const { return movimentosRestantes; }
    int getPlantacoesRestantes() const { return plantacoesRestantes; }
    int getColheitasRestantes() const { return colheitasRestantes; }

    Ferramenta *getFerramentaNaMao() const { return ferramentaNaMao; }

    void entrar(int l, int c);

    void sair();

    bool podeMover() const;

    void movimentaPara(int novaLinha, int novaColuna);

    void resetContadoresTurno();

    bool podePlantar() const;

    void registaPlantacao();

    bool podeColher() const;

    void registaColheita();


    void pegaFerramenta(Ferramenta *f);

    Ferramenta *largaFerramentaDaMao();
};

#endif //PROJETO_JARDINEIRO_H
