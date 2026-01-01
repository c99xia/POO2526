#include "cmdGravarEstadoJardim.h"

void cmdGravarEstadoJardim::executa(Simulador& simulador) {
    simulador.gravarEstadoJardim(this->nomeF);
}

cmdGravarEstadoJardim::cmdGravarEstadoJardim(const std::string& nome) :
    nomeF(nome)
{

}

Comando* cmdGravarEstadoJardim::criar(std::istringstream& iss) {
    std::cout << "Comando grava" << std::endl;
    std::string nome;
    if (iss >> nome) {
        std::cout << "nome lido" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdGravaEstadoJardim" << std::endl;
            return new cmdGravarEstadoJardim(nome);
        }
        std::cout << "Contem dados invalidos" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return nullptr;
}
