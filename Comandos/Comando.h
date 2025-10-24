//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_COMANDO_H
#define PROJETO_COMANDO_H

class Simulador;

class Comando {
public:
    virtual void executa(Simulador &simulador);
    virtual ~Comando() = default;
};


#endif //PROJETO_COMANDO_H
