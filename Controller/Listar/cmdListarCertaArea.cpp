#include "cmdListarCertaArea.h"
void cmdListarCertaArea::executa(Simulador &simulador) {
    simulador.listarCertaArea (this->linha, this->coluna, this->raio);
}
cmdListarCertaArea::cmdListarCertaArea(int linha, int coluna, int raio)
    : linha(linha), coluna(coluna), raio(raio)
{

}

Comando *cmdListarCertaArea::criar (std::istringstream &iss) {
    std::cout << "Comando lsolo" << std::endl;
    std::string posicao;
    if (iss >> posicao) {
        std::cout << "posicao lido" << std::endl;
        if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
            int linha = posicao[0] - 'a';
            int coluna = posicao[1] - 'a';
            std::cout << "posicao valida" << std::endl;

            int raio = 0;
            if (iss.peek() != EOF) {
                if (!(iss >> raio)) {
                    std::cout << "Raio tem que ser um numero" << std::endl;
                    return nullptr;
                }
            }
            std::string invalido;
            if (!(iss >> invalido)) {
                if (raio>=0) {
                    std::cout << "A construir o comando cmdListarCertaArea" << std::endl;
                    return new cmdListarCertaArea(linha, coluna, raio);
                }
                std::cout << "Raio invalido" << std::endl;
                return nullptr;
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
        std::cout << "numero de caracteres invalido ou caracteres nao estao em minusculas" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto'" << std::endl;
    return nullptr;
}