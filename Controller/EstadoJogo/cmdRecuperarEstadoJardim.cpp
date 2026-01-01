#include "cmdRecuperarEstadoJardim.h"

#include <iostream>
#include <sstream>

void cmdRecuperarEstadoJardim::executa(Simulador& simulador) {
    simulador.recuperarEstadoJardim(this->nomeF);
}
cmdRecuperarEstadoJardim::cmdRecuperarEstadoJardim(const std::string& nome) :
    nomeF(nome)
{

}

Comando* cmdRecuperarEstadoJardim::criar(std::istringstream& iss) {
    std::cout << "Comando recupera" << std::endl;
    std::string nome;
    if (iss >> nome) {
        std::cout << "nome lido" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdRecuperarEstadoJardim" << std::endl;
            return new cmdRecuperarEstadoJardim(nome);
        }
        std::cout << "Contem dados invalidos" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return  nullptr;
}