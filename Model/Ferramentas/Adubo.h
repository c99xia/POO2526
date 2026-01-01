#ifndef PROJETO_ADUBO_H
#define PROJETO_ADUBO_H

#include "Ferramenta.h"
#include "../../Utils/Settings.h"
#include "../Jardim.h"

class Adubo : public Ferramenta {
    int capacidade;
    int aduboAtual;

public:
    Adubo()
        : capacidade(Settings::Adubo::capacidade),
        aduboAtual(Settings::Adubo::capacidade)
    {
    }

    char getChar() const override { return 'a'; }

    int getAduboAtual() const { return aduboAtual; }

    // Dá +10 nutrientes ao solo, consome adubo interno
    bool atua(Jardim& jardim, int linha, int coluna) override;
};


#endif //PROJETO_ADUBO_H
