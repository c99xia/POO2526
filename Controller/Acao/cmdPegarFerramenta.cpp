#include "cmdPegarFerramenta.h"
void cmdPegarFerramenta::executa(Simulador& simulador) {
    simulador.pegarFerramenta(this->numeroSerie);
}

cmdPegarFerramenta::cmdPegarFerramenta(int numeroSerie) :
    numeroSerie(numeroSerie)
{

}

Comando* cmdPegarFerramenta::criar(std::istringstream& iss) {
    std::cout << "Comando pega" << std::endl;
    int numeroSerie;
    if (iss >> numeroSerie) {
        std::cout << "numero de serie lido" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            if (numeroSerie > 0) {
                std::cout << "numero de serie valido" << std::endl;
                return new cmdPegarFerramenta(numeroSerie);
            }
            std::cout << "numero de serie tem que ser positivo" << std::endl;
            return nullptr;
        }
        std::cout << "Contem dados invalidos" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return nullptr;

}