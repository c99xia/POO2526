#include "cmdGravarEstadoJardim.h"

void cmdGravarEstadoJardim::executa(Simulador& simulador) {
    simulador.gravarEstadoJardim(this->nomeF);
}

cmdGravarEstadoJardim::cmdGravarEstadoJardim(const std::string& nome) :
    nomeF(nome)
{

}

Comando* cmdGravarEstadoJardim::criar(std::istringstream& iss) {
    std::string nome;
    if (!(iss >> nome)) {
        std::cout << "Erro: grava requer um nome." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdGravarEstadoJardim(nome);
}
