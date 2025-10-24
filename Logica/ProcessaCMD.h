//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_PROCESSACMD_H
#define PROJETO_PROCESSACMD_H
#include "Comandos/Comando.h"
#include <string>

class ProcessaCMD {
public:
    ProcessaCMD() = default;

    Comando *processa(std::string &inputUtilizador);

};


#endif //PROJETO_PROCESSACMD_H
