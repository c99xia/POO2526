#include "cmdFim.h"
#include "../../Model/Simulador.h"

void cmdFim::executa(Simulador& simulador) {
    simulador.terminarJogo();
}

Comando* cmdFim::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'fim' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdFim();
}