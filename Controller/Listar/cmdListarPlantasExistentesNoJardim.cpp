#include "cmdListarPlantasExistentesNoJardim.h"

void cmdListarPlantasExistentesNoJardim::executa(Simulador &simulador) {
    simulador.listarPlantasExistentesNoJardim();
}

Comando *cmdListarPlantasExistentesNoJardim::criar (std::istringstream &iss) {
    std::cout << "Comando lplantas" << std::endl;
    std::string invalido;
    if (!(iss >> invalido)) {
        std::cout << "A construir o comando cmdListarPlantasExistentesNoJardim" << std::endl;
        return new cmdListarPlantasExistentesNoJardim();
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}