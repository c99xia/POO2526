#include "cmdMoveEsquerda.h"
void cmdMoveEsquerda::executa(Simulador &simulador) {
    simulador.moveEsquerda();
}

Comando *cmdMoveEsquerda::criar (std::istringstream &iss) {
    std::cout << "Comando e" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdMoveEsquerda" << std::endl;
        return new cmdMoveEsquerda();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}