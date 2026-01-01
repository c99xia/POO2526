#include "cmdListarFerramentas.h"
void cmdListarFerramentas::executa(Simulador& simulador) {
    simulador.listarFerramenta();
}

Comando* cmdListarFerramentas::criar(std::istringstream& iss) {
    std::cout << "Comando lferr" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdListarFerramentas" << std::endl;
        return new cmdListarFerramentas();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}