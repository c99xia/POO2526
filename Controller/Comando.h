#ifndef PROJETO_COMANDO_H
#define PROJETO_COMANDO_H

#include <string>

class Simulador;

class Comando {
public:
    virtual void executa(Simulador& simulador) = 0;

    // Regra do jardim
    virtual std::string nome() const = 0;

    virtual ~Comando() = default;
};

#endif
