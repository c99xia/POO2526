#ifndef PROJETO_ADUBO_H
#define PROJETO_ADUBO_H

#include "Ferramenta.h"
#include "../../Utils/Settings.h"

class Adubo : public Ferramenta {
    int capacidade;
    int aduboAtual;

public:
    Adubo()
        : capacidade(Settings::Adubo::capacidade),
          aduboAtual(Settings::Adubo::capacidade)
    {}

    char getChar() const override { return 'a'; }

    int getAduboAtual() const { return aduboAtual; }
    void gastarAdubo(int dose) {
        if (dose > aduboAtual) dose = aduboAtual;
        aduboAtual -= dose;
    }
};

#endif //PROJETO_ADUBO_H
