#include "cmdListarArea.h"

void cmdListarArea::executa(Simulador& simulador) {
    simulador.listarArea();
}

Comando* cmdListarArea::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'larea' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdListarArea();
}