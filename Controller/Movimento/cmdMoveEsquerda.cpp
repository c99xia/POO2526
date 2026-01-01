#include "cmdMoveEsquerda.h"
#include "../../Model/Simulador.h"
#include <iostream>
void cmdMoveEsquerda::executa(Simulador& simulador) {
    simulador.moveEsquerda();
}

Comando* cmdMoveEsquerda::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'e' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdMoveEsquerda();
}