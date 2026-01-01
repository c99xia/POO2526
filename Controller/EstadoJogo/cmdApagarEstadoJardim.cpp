#include "cmdApagarEstadoJardim.h"

void cmdApagarEstadoJardim::executa(Simulador& simulador) {
    simulador.apagarEstadoJardim(this->nomeF);
}

cmdApagarEstadoJardim::cmdApagarEstadoJardim(const std::string& nome) :
    nomeF(nome)
{

}

Comando* cmdApagarEstadoJardim::criar(std::istringstream& iss) {
    std::string nome;
    if (!(iss >> nome)) {
        std::cout << "Erro: apaga requer um nome." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdApagarEstadoJardim(nome);
}