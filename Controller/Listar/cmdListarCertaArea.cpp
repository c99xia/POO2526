#include "cmdListarCertaArea.h"
void cmdListarCertaArea::executa(Simulador& simulador) {
    simulador.listarCertaArea(this->linha, this->coluna, this->raio);
}
cmdListarCertaArea::cmdListarCertaArea(int linha, int coluna, int raio)
    : linha(linha), coluna(coluna), raio(raio)
{

}

Comando* cmdListarCertaArea::criar(std::istringstream& iss) {
    std::string posicao;
    if (!(iss >> posicao)) {
        std::cout << "Erro: lsolo requer posicao (ex: aa [raio])." << std::endl;
        return nullptr;
    }

    if (posicao.length() != 2 || !islower(posicao[0]) || !islower(posicao[1])) {
        std::cout << "Erro: posicao invalida (use 2 letras minusculas)." << std::endl;
        return nullptr;
    }

    int linha = posicao[0] - 'a';
    int coluna = posicao[1] - 'a';

    int raio = 0;
    if (iss.peek() != EOF) {
        if (!(iss >> raio) || raio < 0) {
            std::cout << "Erro: raio deve ser um numero positivo." << std::endl;
            return nullptr;
        }
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdListarCertaArea(linha, coluna, raio);
}