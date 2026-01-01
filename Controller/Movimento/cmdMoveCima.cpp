#include "cmdMoveCima.h"
void cmdMoveCima::executa(Simulador &simulador) {
    simulador.moveCima();
}

Comando *cmdMoveCima::criar (std::istringstream &iss) {
    std::cout << "Comando c" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdMoveCima" << std::endl;
        return new cmdMoveCima();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;

}