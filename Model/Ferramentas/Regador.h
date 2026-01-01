#ifndef PROJETO_REGADOR_H
#define PROJETO_REGADOR_H

#include "Ferramenta.h"
#include "../../Utils/Settings.h"

class Regador : public Ferramenta {
    int capacidade;
    int aguaAtual;

public:
    Regador()
        : capacidade(Settings::Regador::capacidade),
        aguaAtual(Settings::Regador::capacidade)
    {
    }

    char getChar() const override { return 'g'; }

    int getAguaAtual() const { return aguaAtual; }

    // Dá +10 água ao solo, consome água interna
    bool atua(Jardim& jardim, int linha, int coluna) override;
};

#endif //PROJETO_REGADOR_H
