#include "cmdSaiJardineiro.h"
void cmdSaiJardineiro::executa(Simulador &simulador) {
    simulador.sairJardineiro();
}

Comando *cmdSaiJardineiro::criar (std::istringstream &iss) {
    std::cout << "Comando sai" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdSaiJardineiro" << std::endl;
        return new cmdSaiJardineiro();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}