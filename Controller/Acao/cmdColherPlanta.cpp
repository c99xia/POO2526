#include "cmdColherPlanta.h"

void cmdColherPlanta::executa(Simulador& simulador)
{
    simulador.colhePlanta(this->linha, this->coluna);
}

cmdColherPlanta::cmdColherPlanta(int linha, int coluna) :
    linha(linha), coluna(coluna)
{

}

Comando* cmdColherPlanta::criar(std::istringstream& iss) {
    std::cout << "Comando colhe" << std::endl;
    std::string posicao;
    if (iss >> posicao) {
        std::cout << "posicao lido" << std::endl;
        if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
            int linha = posicao[0] - 'a';
            int coluna = posicao[1] - 'a';
            std::cout << "Posicao valida" << std::endl;

            std::string invalido;
            if (!(iss >> invalido)) {
                std::cout << "A construir o comando cmdColherPlanta" << std::endl;
                return new cmdColherPlanta(linha, coluna);
            }
            std::cout << "Contem dados invalidos" << std::endl;
        }
        std::cout << "numero de caracteres invalido ou caracteres nao estao em minusculas" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}
