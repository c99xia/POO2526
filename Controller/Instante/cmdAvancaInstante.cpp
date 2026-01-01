#include "cmdAvancaInstante.h"
cmdAvancaInstante::cmdAvancaInstante(int instante) :
    instante (instante)
{

}

void cmdAvancaInstante::executa(Simulador &simulador) {
    simulador.avancaInstante(this->instante);
}

Comando* cmdAvancaInstante::criar(std::istringstream &iss) {
    std::cout << "Comando avanca" << std::endl;
    int instante = 1;
    if (iss.peek() != EOF) {
        std::cout << "Temos valor para ler" << std::endl;
        if (!(iss >> instante)) {
            std::cout << "Nao foi lido um numero" << std::endl;
            return nullptr;
        }
    }
    std::string invalido;
    if (!(iss >> invalido)) {
        if (instante > 0) {
            std::cout << "A construir o comando cmdAvancaInstante" << std::endl;
            return new cmdAvancaInstante(instante);
        }
        std::cout << "O valor deve ser positivo" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}