#include "cmdCriarJardim.h"
#include "../../Model/Simulador.h"

cmdCriarJardim::cmdCriarJardim(int linha, int coluna) : linha(linha), coluna(coluna) {}

void cmdCriarJardim::executa(Simulador& simulador) {
    simulador.criarJardim(this->linha, this->coluna);
}

Comando* cmdCriarJardim::criar(std::istringstream& iss) {
    int linha, coluna;
    if (!(iss >> linha >> coluna)) {
        std::cout << "Erro: jardim requer 2 argumentos (linhas colunas)." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    if (linha <= 0 || linha > 26 || coluna <= 0 || coluna > 26) {
        std::cout << "Erro: dimensoes devem estar entre 1 e 26." << std::endl;
        return nullptr;
    }

    return new cmdCriarJardim(linha, coluna);
}