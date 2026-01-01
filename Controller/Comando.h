#ifndef PROJETO_COMANDO_H
#define PROJETO_COMANDO_H

#include <string>

class Simulador;

class Comando {
public:
    virtual void executa(Simulador &simulador) = 0;

    // Identificador do comando (para regras do enunciado sem dynamic_cast)
    virtual std::string nome() const = 0;

    virtual ~Comando() = default;
};

#endif //PROJETO_COMANDO_H
