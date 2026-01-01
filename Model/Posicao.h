#ifndef PROJETO_POSICAO_H
#define PROJETO_POSICAO_H

#include <memory>
class Ferramenta;
class Planta;

class Posicao {
    int agua;
    int nutrientes;

    std::unique_ptr<Planta> planta;
    std::unique_ptr<Ferramenta> ferramenta;

public:
    Posicao();
    ~Posicao();
    // Solo
    int getAgua() const { return agua; }
    int getNutrientes() const { return nutrientes; }

    void setAgua(int valor);
    void setNutrientes(int valor);

    void adicionaAgua(int quantidadeAgua);
    void adicionaNutrientes(int quantidadeNutriente);

    // Planta
    Planta* getPlanta() const { return planta.get(); }   // devolve ponteiro cru, sem ownership
    void setPlanta(std::unique_ptr<Planta> p);           // toma posse
    bool temPlanta() const { return planta != nullptr; }
    void removePlanta();         // opcional mas útil

    // Ferramenta
    Ferramenta* getFerramenta() const { return ferramenta.get(); }
    void setFerramenta(std::unique_ptr<Ferramenta> f);   // toma posse
    bool temFerramenta() const { return ferramenta != nullptr; }
    std::unique_ptr<Ferramenta> retiraFerramenta();      // para "pegar" (move)
};


#endif //PROJETO_POSICAO_H
