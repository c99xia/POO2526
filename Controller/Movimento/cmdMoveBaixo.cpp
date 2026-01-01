#include "cmdMoveBaixo.h"

void cmdMoveBaixo::executa(Simulador &simulador) {
    simulador.moveBaixo();
}

Comando *cmdMoveBaixo::criar (std::istringstream &iss) {
    std::cout << "Comando b" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdMoveBaixo" << std::endl;
        return new cmdMoveBaixo();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}