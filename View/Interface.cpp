#include "Interface.h"
#include "../Model/Jardim.h"
#include "../Model/Posicao.h"
#include "../Model/Plantas/Planta.h"
#include <iostream>
#include "../Model/Jardineiro.h"

void Interface::mostraJardim(const Jardim& jardim, const Jardineiro& jardineiro) {
    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    if (linhas == 0 || colunas == 0) {
        return;
    }

    bool temJardineiro = jardineiro.estaPresente();
    int jardineiroLinha = jardineiro.getLinha();
    int jardineiroColuna = jardineiro.getColuna();

    std::cout << "\n";

    // Cabeçalho das colunas (A, B, C, ...)
    std::cout << "   ";
    for (int c = 0; c < colunas; ++c) {
        std::cout << static_cast<char>('A' + c) << " ";
    }
    std::cout << "\n";

    for (int l = 0; l < linhas; ++l) {
        // Letra da linha à esquerda
        std::cout << static_cast<char>('A' + l) << "  ";

        for (int c = 0; c < colunas; ++c) {
            const Posicao& pos = jardim.getPosicao(l, c);
            char ch = ' '; // vazio

            // prioridade: jardineiro > planta > ferramenta > vazio
            if (temJardineiro && l == jardineiroLinha && c == jardineiroColuna) {
                ch = '*';
            }
            else if (pos.getPlanta() != nullptr) {
                ch = pos.getPlanta()->getChar();
            }
            else if (pos.getFerramenta() != nullptr) {
                ch = pos.getFerramenta()->getChar();
            }

            std::cout << ch << " ";
        }

        // Letra da linha à direita
        std::cout << " " << static_cast<char>('A' + l) << "\n";
    }

    // Cabeçalho das colunas em baixo
    std::cout << "   ";
    for (int c = 0; c < colunas; ++c) {
        std::cout << static_cast<char>('A' + c) << " ";
    }
    std::cout << "\n";
}

std::string Interface::lerComando() const {
    std::string linha;
    std::cout << "Comando: ";
    std::getline(std::cin, linha);
    return linha;
}

void Interface::mostrarMsg(const std::string& msg) const {
    std::cout << "Mensagem: " << msg << std::endl;
}

