#include "cmdPlantar.h"

void cmdPlantar::executa(Simulador &simulador) {
    simulador.plantar(this->linha, this->coluna, this->tipo_planta);
}

cmdPlantar::cmdPlantar(int linha, int coluna, char tipo_planta) :
    linha (linha), coluna (coluna), tipo_planta(tipo_planta)
{
}

Comando *cmdPlantar::criar (std::istringstream &iss) {
    std::cout << "Comando planta" << std::endl;
    std::string posicao;
    if (iss >> posicao) {
        std::cout << "posicao lido" << std::endl;
        if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
            std::cout << "posicao valida" << std::endl;

            char tipoPlanta;
            if (iss >> tipoPlanta) {
                if (tipoPlanta == 'c' || tipoPlanta == 'r' || tipoPlanta == 'e' || tipoPlanta == 'x') {
                    std::string invalido;
                    if (!(iss >> invalido)) {
                        int linha = posicao[0] - 'a';
                        int coluna = posicao[1] - 'a';

                        std::cout << "A construir o comando cmdPlantar" << std::endl;
                        return new cmdPlantar(linha, coluna, tipoPlanta);
                    }
                    std::cout << "Contem dados invalidos" << std::endl;
                    return nullptr;
                }
                std::cout << "Nao existe esse tipo de planta" << std::endl;
                return nullptr;
            }
            std::cout << "Nao foi lido tipoPlanta" << std::endl;
            return nullptr;
        }
        std::cout << "posicao invalida" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}
