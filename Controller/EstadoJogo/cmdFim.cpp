#include "cmdFim.h"
#include "../../Model/Simulador.h"

void cmdFim::executa(Simulador& simulador) {
    simulador.terminarJogo();
}

Comando* cmdFim::criar(std::istringstream& iss) {
    std::cout << "Comando fim" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdFim" << std::endl;
        return new cmdFim();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}