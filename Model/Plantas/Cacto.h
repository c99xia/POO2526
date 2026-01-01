#ifndef PROJETO_CACTO_H
#define PROJETO_CACTO_H

#include "Planta.h"

class Jardim;

class Cacto : public Planta {
    int nutrientesAcumCacto;
    int aguaAcumCacto;

    int contAguaSoloAlta;        // instantes seg. com agua_solo > limite
    int contNutrientesSoloZero;  // instantes seg. com nutrientes_solo < limite


    // Criei aqui funções auxiliares apenas usada nesta classe e mais nada

    //Absorção
    void absorveAguaDoSolo(class Posicao &pos);
    void absorveNutrientesDoSolo(class Posicao &pos);

    //Morte do cacto
    void atualizaContadoresMorte(const class Posicao &pos);
    bool deveMorrer() const;
    void morre(class Posicao &pos);

    //Multiplicação
    bool podeMultiplicar() const;
    bool tentaMultiplicarParaVizinhoLivre(Jardim &jardim, int linha, int coluna);

public:
    Cacto();
    Cacto(int nutrientes, int agua);

    char getChar() const override {return 'c';}
    void atualiza(Jardim &jardim, int linha, int coluna) override;
};

#endif //PROJETO_CACTO_H
