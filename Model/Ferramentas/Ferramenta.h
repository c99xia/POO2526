#ifndef PROJETO_FERRAMENTA_H
#define PROJETO_FERRAMENTA_H

class Jardim;

class Ferramenta {
    static int proximoNumeroSerie;
    int numeroSerie;

protected:
    bool gasta; // ferramenta gasta deve ser removida

public:
    Ferramenta();
    virtual ~Ferramenta() = default;

    int getNumeroSerie() const { return numeroSerie; }
    bool estaGasta() const { return gasta; }

    // obter caracter
    virtual char getChar() const = 0;

    // Atua automaticamente a cada instante na posição do jardineiro
    // Retorna true se a ferramenta foi usada com sucesso
    virtual bool atua(Jardim& jardim, int linha, int coluna) = 0;
};

#endif //PROJETO_FERRAMENTA_H
