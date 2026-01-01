#ifndef PROJETO_CMDLISTARPLANTASEXISTENTESNOJARDIM_H
#define PROJETO_CMDLISTARPLANTASEXISTENTESNOJARDIM_H
#include "../Comando.h"
#include <sstream>
#include <iostream>
#include <string>
#include "../../Model/Simulador.h"

class cmdListarPlantasExistentesNoJardim : public Comando {
public:
    cmdListarPlantasExistentesNoJardim() = default;

public:
    void executa(Simulador &simulador) override;
    static Comando* criar(std::istringstream &iss);
};
#endif //PROJETO_CMDLISTARPLANTASEXISTENTESNOJARDIM_H
