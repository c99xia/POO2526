#include "cmdMoveCima.h"
void cmdMoveCima::executa(Simulador& simulador) {
    simulador.moveCima();
}

Comando* cmdMoveCima::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'c' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdMoveCima();
}