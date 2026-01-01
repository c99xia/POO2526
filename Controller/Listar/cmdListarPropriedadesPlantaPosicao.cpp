#include "cmdListarPropriedadesPlantaPosicao.h"

void cmdListarPropriedadesPlantaPosicao::executa(Simulador& simulador) {
    simulador.listarPropriedadesPlantaPosicao(this->linha, this->coluna);
}
cmdListarPropriedadesPlantaPosicao::cmdListarPropriedadesPlantaPosicao(int linha, int coluna) :
    linha(linha), coluna(coluna)
{

}

Comando* cmdListarPropriedadesPlantaPosicao::criar(std::istringstream& iss) {
    std::string posicao;
    if (!(iss >> posicao)) {
        std::cout << "Erro: lplanta requer posicao (ex: aa)." << std::endl;
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

    int linhaInt = posicao[0] - 'a';
    int colunaInt = posicao[1] - 'a';
    return new cmdListarPropriedadesPlantaPosicao(linhaInt, colunaInt);
}