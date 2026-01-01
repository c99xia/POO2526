#include "cmdPlantar.h"

void cmdPlantar::executa(Simulador& simulador) {
    simulador.plantar(this->linha, this->coluna, this->tipo_planta);
}

cmdPlantar::cmdPlantar(int linha, int coluna, char tipo_planta) :
    linha(linha), coluna(coluna), tipo_planta(tipo_planta)
{
}

Comando* cmdPlantar::criar(std::istringstream& iss) {
    std::string posicao;
    if (!(iss >> posicao)) {
        std::cout << "Erro: planta requer posicao e tipo (ex: aa c)." << std::endl;
        return nullptr;
    }

    if (posicao.length() != 2 || !islower(posicao[0]) || !islower(posicao[1])) {
        std::cout << "Erro: posicao invalida (use 2 letras minusculas)." << std::endl;
        return nullptr;
    }

    char tipoPlanta;
    if (!(iss >> tipoPlanta)) {
        std::cout << "Erro: tipo de planta nao especificado (c/r/e/x)." << std::endl;
        return nullptr;
    }

    if (tipoPlanta != 'c' && tipoPlanta != 'r' && tipoPlanta != 'e' && tipoPlanta != 'x') {
        std::cout << "Erro: tipo invalido (use c, r, e ou x)." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    int linha = posicao[0] - 'a';
    int coluna = posicao[1] - 'a';
    return new cmdPlantar(linha, coluna, tipoPlanta);
}
