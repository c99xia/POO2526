//
// Created by xiaro on 10/23/2025.
//

#ifndef PROJETO_M4RG4RID4_H
#define PROJETO_M4RG4RID4_H
#include "Planta.h"
#include "../Jardim.h"


// Planta Exótica (M4rg4rid4)
// Comportamento especial: "purifica" plantas feias vizinhas,
// transformando a beleza delas de feia para linda.
class M4rg4rid4 : public Planta {
    int nutrientesAcumM4rg4rid4;
    int aguaAcumM4rg4rid4;
    int instantesVividos;

    // Função auxiliar para purificar vizinhos feios
    void purificarVizinhos(Jardim& jardim, int linha, int coluna);

public:
    M4rg4rid4();

    char getChar() const override { return 'x'; }

    void atualiza(Jardim& jardim, int linha, int coluna) override;
};


#endif //PROJETO_M4RG4RID4_H
