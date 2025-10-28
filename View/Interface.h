//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_INTERFACE_H
#define PROJETO_INTERFACE_H
#include <string>

class Jardineiro;
class Jardim;

class Interface {
public:
    void mostraJardim(const std::string& jardim);

    std::string lerComando() const;

    void mostrarMsg(const std::string &msg) const;
};


#endif //PROJETO_INTERFACE_H
