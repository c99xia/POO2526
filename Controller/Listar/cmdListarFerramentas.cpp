#include "cmdListarFerramentas.h"
void cmdListarFerramentas::executa(Simulador& simulador) {
    simulador.listarFerramenta();
}

Comando* cmdListarFerramentas::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'lferr' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdListarFerramentas();
}