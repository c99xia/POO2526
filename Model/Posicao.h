#ifndef PROJETO_POSICAO_H
#define PROJETO_POSICAO_H

#include "Ferramentas/Ferramenta.h"
#include "Plantas/Planta.h"

class Posicao {
    int agua;
    int nutrientes;
    Planta *planta; //usam-se ponteiros * e não objetos diretos Planta planta, porque a posição pode estar vazia.
    //planta == nullptr (não há planta)
    //planta != nullptr (existe planta) permite saber facilmente se o espaço está ocupado ou não
    Ferramenta *ferramenta;

public:
    Posicao();

    // O solo tem água e nutrientes, logo podemos ter aqui um getter e um setter
    int getAgua() const {return agua;}
    int getNutrientes() const {return nutrientes;}

    void setAgua(int valor);
    void setNutrientes(int valor);

    void adicionaAgua(int quantidadeAgua);
    void adicionaNutrientes(int quantidadeNutriente);

    // O solo também pode ter planta
    Planta* getPlanta() const {return planta;}
    void setPlanta(Planta *p);
    bool temPlanta() const;

    // O solo também pode ter ferramenta
    Ferramenta* getFerramenta() const {return ferramenta;}
    void setFerramenta(Ferramenta *f);
    bool temFerramenta() const;
};

#endif //PROJETO_POSICAO_H
