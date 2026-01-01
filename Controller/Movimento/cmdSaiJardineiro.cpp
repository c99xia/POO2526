#include "cmdSaiJardineiro.h"
void cmdSaiJardineiro::executa(Simulador& simulador) {
    simulador.sairJardineiro();
}

Comando* cmdSaiJardineiro::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'sai' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdSaiJardineiro();
}