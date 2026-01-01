#include "cmdApagarEstadoJardim.h"

void cmdApagarEstadoJardim::executa(Simulador& simulador) {
    simulador.apagarEstadoJardim(this->nomeF);
}

cmdApagarEstadoJardim::cmdApagarEstadoJardim(const std::string& nome) :
    nomeF(nome)
{

}

Comando* cmdApagarEstadoJardim::criar(std::istringstream& iss) {
    std::cout << "Comando apaga" << std::endl;
    std::string nome;
    if (iss >> nome) {
        std::cout << "nome lido" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdApagarEstadoJardim" << std::endl;
            return new cmdApagarEstadoJardim(nome);
        }
        std::cout << "Contem dados invalidos" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return  nullptr;
}