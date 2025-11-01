#include "Interface.h"
#include "../Model/Jardim.h"
#include <iostream>



void Interface::mostraJardim(const Jardim &jardim) {
    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    if (linhas == 0 || colunas == 0) {
        return;
    }

    std::cout << std::endl;

    std::cout << "   ";
    for (int c = 0; c < colunas; ++c) {
        std::cout << static_cast<char>('A' + c) << " ";
    }
    std::cout << std::endl;

    for (int l = 0; l < linhas; ++l) {
        std::cout << static_cast<char>('A' + l) << "  ";

        for (int c = 0; c < colunas; ++c) {
            std::cout << "_ ";
        }

        std::cout << " " << static_cast<char>('A' + l);

        std::cout << std::endl;
    }

    std::cout << "   ";
    for (int c = 0; c < colunas; ++c) {
        std::cout << static_cast<char>('A' + c) << " ";
    }
    std::cout << std::endl;
}

std::string Interface::lerComando() const {
    std::string linha;
    std::cout << "Comando: ";
    std::getline(std::cin, linha);
    return linha;
}

void Interface::mostrarMsg(const std::string &msg) const {
    std::cout << "Mensagem: " << msg << std::endl;
}
