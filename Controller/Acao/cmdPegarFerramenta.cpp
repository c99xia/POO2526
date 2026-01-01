#include "cmdPegarFerramenta.h"
void cmdPegarFerramenta::executa(Simulador& simulador) {
    simulador.pegarFerramenta(this->numeroSerie);
}

cmdPegarFerramenta::cmdPegarFerramenta(int numeroSerie) :
    numeroSerie(numeroSerie)
{

}

Comando* cmdPegarFerramenta::criar(std::istringstream& iss) {
    int numeroSerie;
    if (!(iss >> numeroSerie)) {
        std::cout << "Erro: pega requer numero de serie." << std::endl;
        return nullptr;
    }

    if (numeroSerie <= 0) {
        std::cout << "Erro: numero de serie deve ser positivo." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdPegarFerramenta(numeroSerie);
}