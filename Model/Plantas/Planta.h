#ifndef PROJETO_PLANTA_H
#define PROJETO_PLANTA_H

#include "../Beleza.h"


class Jardim;
class Posicao;

class Jardim;
class Posicao;

class Planta {
protected:
    bool morta;
    Beleza beleza;

    // protected porque só as classes derivadas da planta podem usar, se metesse aqui público podia ser acedido por todos, não é bom
    Planta(Beleza b);

public:
    virtual ~Planta() = default;

    bool estaMorta() const { return morta; }
    Beleza getBeleza() const { return beleza; }

    // Permite alterar a beleza da planta (usado pela planta exótica)
    void setBeleza(Beleza b) { beleza = b; }

    // Caracter para desenhar a planta na grelha (c, r, e, x...)
    virtual char getChar() const = 0;

    // Lógica de um instante de tempo para esta planta
    // linha e coluna onde se encontra a planta no jardim
    virtual void atualiza(Jardim& jardim, int linha, int coluna) = 0;
    // = 0 significa que Planta é uma classe Abstrata, ninguém pode criar uma "Planta" genérica.
    //É obrigatório criar um Cacto, uma ROseira, etc.
    //Polimorfismo todas as plantas têm o método atualiza. O Simulador não precisa de saber se é um cacto ou uma rosa.
    //Ele apenas chama planta->atualiza (....) e a planta sabe o que fazer.
};


#endif //PROJETO_PLANTA_H
