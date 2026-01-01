#include "cmdMoveDireita.h"
void cmdMoveDireita::executa(Simulador &simulador) {
	simulador.moveDireita();
}

Comando *cmdMoveDireita::criar (std::istringstream &iss) {
    std::cout << "Comando d" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdMoveDireita" << std::endl;
        return new cmdMoveDireita();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}