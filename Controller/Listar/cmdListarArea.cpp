#include "cmdListarArea.h"

void cmdListarArea::executa(Simulador &simulador) {
    simulador.listarArea();
}

Comando *cmdListarArea::criar (std::istringstream &iss) {
    std::cout << "Comando larea" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdListarArea" << std::endl;
        return new cmdListarArea();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}