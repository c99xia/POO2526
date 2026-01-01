#ifndef PROJETO_TESOURA_H
#define PROJETO_TESOURA_H

#include "Ferramenta.h"

class Tesoura : public Ferramenta {
public:
    Tesoura() = default;

    char getChar() const override { return 't'; }
};

#endif //PROJETO_TESOURA_H
