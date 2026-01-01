#include "cmdRecuperarEstadoJardim.h"

void cmdRecuperarEstadoJardim::executa(Simulador& simulador) {
    simulador.recuperarEstadoJardim(this->nomeF);
}
cmdRecuperarEstadoJardim::cmdRecuperarEstadoJardim(const std::string& nome) :
    nomeF(nome)
{

}

Comando* cmdRecuperarEstadoJardim::criar(std::istringstream& iss) {
    std::string nome;
    if (!(iss >> nome)) {
        std::cout << "Erro: recupera requer um nome." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdRecuperarEstadoJardim(nome);
}