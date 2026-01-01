#include "cmdEntraJardineiro.h"
void cmdEntraJardineiro::executa(Simulador &simulador) {
    simulador.entrarJardineiro (this->linha, this->coluna);
}

cmdEntraJardineiro::cmdEntraJardineiro(int linha, int coluna) :
    linha(linha), coluna(coluna)

{

}

Comando *cmdEntraJardineiro::criar (std::istringstream &iss) {
    std::cout << "Comando entra" << std::endl;
    std::string posicao;
    if (iss >> posicao) {
        std::cout << "posicao lido" << std::endl;
        if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
            int linha = posicao[0] - 'a';
            int coluna = posicao[1] - 'a';
            std::cout << "Posicao valida" << std::endl;

            std::string invalido;
            if (!(iss >> invalido)) {
                std::cout << "A construir o comando cmdEntraJardineiro" << std::endl;
                return new cmdEntraJardineiro(linha, coluna);
            }
            std::cout << "Contem dados invalidos" << std::endl;
        }
        std::cout << "numero de caracteres invalido ou caracteres nao estao em minusculas" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}
