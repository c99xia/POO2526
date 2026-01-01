#include "cmdMoveBaixo.h"

void cmdMoveBaixo::executa(Simulador& simulador) {
    simulador.moveBaixo();
}

Comando* cmdMoveBaixo::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'b' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdMoveBaixo();
}