#include "cmdListarPlantasExistentesNoJardim.h"

void cmdListarPlantasExistentesNoJardim::executa(Simulador& simulador) {
    simulador.listarPlantasExistentesNoJardim();
}

Comando* cmdListarPlantasExistentesNoJardim::criar(std::istringstream& iss) {
    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: comando 'lplantas' nao aceita argumentos." << std::endl;
        return nullptr;
    }
    return new cmdListarPlantasExistentesNoJardim();
}