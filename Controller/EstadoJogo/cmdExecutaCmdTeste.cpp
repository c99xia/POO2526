#include "cmdExecutaCmdTeste.h"
void cmdExecutaCmdTeste::executa(Simulador& simulador) {
    simulador.executarComandoTeste(this->nome_do_ficheiro);
}

cmdExecutaCmdTeste::cmdExecutaCmdTeste(const std::string& nome_do_ficheiro) :
    nome_do_ficheiro(nome_do_ficheiro)
{

}

Comando* cmdExecutaCmdTeste::criar(std::istringstream& iss) {
    std::string nomeFicheiro;
    if (!(iss >> nomeFicheiro)) {
        std::cout << "Erro: executa requer nome do ficheiro." << std::endl;
        return nullptr;
    }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdExecutaCmdTeste(nomeFicheiro);
}