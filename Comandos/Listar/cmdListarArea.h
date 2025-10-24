//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLISTARAREA_H
#define PROJETO_CMDLISTARAREA_H
#include "../Comando.h"


class cmdListarArea : public Comando {
public:
    cmdListarArea();

    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLISTARAREA_H
