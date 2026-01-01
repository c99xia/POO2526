#include "cmdListarPropriedadesPlantaPosicao.h"

void cmdListarPropriedadesPlantaPosicao::executa(Simulador& simulador) {
    simulador.listarPropriedadesPlantaPosicao(this->linha, this->coluna);
}
cmdListarPropriedadesPlantaPosicao::cmdListarPropriedadesPlantaPosicao(int linha, int coluna) :
    linha(linha), coluna(coluna)
{

}

Comando* cmdListarPropriedadesPlantaPosicao::criar(std::istringstream& iss) {
    std::cout << "Comando lplanta posicoes" << std::endl;
    std::string posicao;
    if (iss >> posicao) {
        std::cout << "posicao lido" << std::endl;
        if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
            std::cout << "posicao valida" << std::endl;
            std::string invalido;
            if (!(iss >> invalido)) {
                int linhaInt = posicao[0] - 'a';
                int colunaInt = posicao[1] - 'a';
                std::cout << "A construir o comando cmdListarPropriedadesPlantaPosicao" << std::endl;
                return new cmdListarPropriedadesPlantaPosicao(linhaInt, colunaInt);
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;

}