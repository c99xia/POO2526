#include "cmdCriarJardim.h"
#include "../../Model/Simulador.h"

cmdCriarJardim::cmdCriarJardim(int linha, int coluna) : linha(linha), coluna(coluna) {}

void cmdCriarJardim::executa(Simulador &simulador) {
    simulador.criarJardim(this->linha, this->coluna);
}

Comando *cmdCriarJardim::criar (std::istringstream &iss) {
    std::cout << "Comando jardim" << std::endl;
    int linha, coluna;
    if (iss >> linha) {
        std::cout << "Linha lido com sucesso" << std::endl;
        if (iss >> coluna) {
            std::cout << "Coluna lido com sucesso" << std::endl;
            std::string invalido;
            if (!(iss >> invalido)) {
                std::cout << "Nao ha dados invalidos" << std::endl;
                if (linha > 0 && linha <= 26 && coluna > 0 && coluna <= 26) {
                    std::cout << "A construir o comando cmdCriarJardim" << std::endl;
                    return new cmdCriarJardim(linha, coluna);
                }
                std::cout << "Os valores das linhas/colunas estao fora dos limites." << std::endl;
                return nullptr;
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
        std::cout << "Linha valido, mas coluna invalido" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return nullptr;
}