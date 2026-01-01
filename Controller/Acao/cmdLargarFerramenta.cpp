#include "cmdLargarFerramenta.h"
void cmdLargarFerramenta::executa(Simulador& simulador)
{
    simulador.largarFerramenta();
}

Comando* cmdLargarFerramenta::criar(std::istringstream& iss) {
    std::cout << "Comando larga" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdLargarFerramenta" << std::endl;
        return new cmdLargarFerramenta();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;

}