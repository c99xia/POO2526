#ifndef PROJETO_FERRAMENTA_H
#define PROJETO_FERRAMENTA_H

class Ferramenta {
    static int proximoNumeroSerie;
    int numeroSerie;

public:
    Ferramenta();
    virtual ~Ferramenta() = default;

    int getNumeroSerie() const { return numeroSerie; }

    // obter caracter
    virtual char getChar() const = 0;
};

#endif //PROJETO_FERRAMENTA_H
