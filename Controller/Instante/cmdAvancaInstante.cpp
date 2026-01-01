#include "cmdAvancaInstante.h"
cmdAvancaInstante::cmdAvancaInstante(int instante) :
    instante(instante)
{

}

void cmdAvancaInstante::executa(Simulador& simulador) {
    simulador.avancaInstante(this->instante);
}

Comando* cmdAvancaInstante::criar(std::istringstream& iss) {
    int instante = 1;

    if (iss.peek() != EOF) {
        if (!(iss >> instante)) {
            std::cout << "Erro: argumento deve ser um numero inteiro." << std::endl;
            return nullptr;
        }
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    if (instante <= 0) {
        std::cout << "Erro: numero de instantes deve ser positivo." << std::endl;
        return nullptr;
    }

    return new cmdAvancaInstante(instante);
}