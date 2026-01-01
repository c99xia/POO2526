#include "cmdMoveDireita.h"
void cmdMoveDireita::executa(Simulador& simulador) {
    simulador.moveDireita();
}

Comando* cmdMoveDireita::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'd' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdMoveDireita();
}