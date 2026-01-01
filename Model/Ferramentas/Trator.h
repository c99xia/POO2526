#ifndef PROJETO_TRATOR_H
#define PROJETO_TRATOR_H

#include "Ferramenta.h"

// FerramentaZ: Trator
// Comportamento especial: limpa todas as plantas da coluna onde está o jardineiro
class Trator : public Ferramenta {
    int usosRestantes; // número de vezes que pode ser usado

public:
    Trator();

    char getChar() const override { return 'z'; }

    int getUsosRestantes() const { return usosRestantes; }

    // Limpa todas as plantas da coluna atual
    bool atua(Jardim& jardim, int linha, int coluna) override;
};

#endif //PROJETO_TRATOR_H
