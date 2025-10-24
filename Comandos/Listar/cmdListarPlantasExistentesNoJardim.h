//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_CMDLISTARPLANTASEXISTENTESNOJARDIM_H
#define PROJETO_CMDLISTARPLANTASEXISTENTESNOJARDIM_H
#include "../Comando.h"


class cmdListarPlantasExistentesNoJardim : public Comando {
public:
    cmdListarPlantasExistentesNoJardim();

public:
    void executa(Simulador &simulador) override;
};


#endif //PROJETO_CMDLISTARPLANTASEXISTENTESNOJARDIM_H
