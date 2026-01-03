//
// Created by xiaro on 10/23/2025.
//

#ifndef PROJETO_FLORIBELA_H
#define PROJETO_FLORIBELA_H
#include "Planta.h"

// Planta Exótica (Floribela)
// Comportamento especial: "purifica" plantas feias vizinhas,
// transformando a beleza delas de feia para linda.
class Floribela : public Planta {
    int nutrientesAcumFloribela;
    int aguaAcumFloribela;
    int instantesVividos;

    // Função auxiliar para purificar vizinhos feios
    void purificarVizinhos(Jardim& jardim, int linha, int coluna);

public:
    Floribela();

    char getChar() const override { return 'x'; }

    void atualiza(Jardim& jardim, int linha, int coluna) override;
};


#endif //PROJETO_FLORIBELA_H
