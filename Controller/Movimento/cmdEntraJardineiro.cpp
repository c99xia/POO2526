#include "cmdEntraJardineiro.h"
void cmdEntraJardineiro::executa(Simulador& simulador) {
    simulador.entrarJardineiro(this->linha, this->coluna);
}

cmdEntraJardineiro::cmdEntraJardineiro(int linha, int coluna) :
    linha(linha), coluna(coluna)

{

}

Comando* cmdEntraJardineiro::criar(std::istringstream& iss) {
    std::string posicao;
    if (!(iss >> posicao)) {
        std::cout << "Erro: entra requer posicao (ex: aa)." << std::endl;
        return nullptr;
    }

    if (posicao.length() != 2 || !islower(posicao[0]) || !islower(posicao[1])) {
        std::cout << "Erro: posicao invalida (use 2 letras minusculas)." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    int linha = posicao[0] - 'a';
    int coluna = posicao[1] - 'a';
    return new cmdEntraJardineiro(linha, coluna);
}
