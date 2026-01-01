#include "cmdLargarFerramenta.h"
void cmdLargarFerramenta::executa(Simulador& simulador)
{
    simulador.largarFerramenta();
}

Comando* cmdLargarFerramenta::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'larga' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdLargarFerramenta();
}