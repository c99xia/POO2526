#ifndef PROJETO_TRATOR_H
#define PROJETO_TRATOR_H

#include "Ferramenta.h"

class Trator : public Ferramenta {
public:
    Trator() = default;

    char getChar() const override { return 'z'; }
};

#endif //PROJETO_TRATOR_H
