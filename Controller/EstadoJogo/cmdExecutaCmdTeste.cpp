#include "cmdExecutaCmdTeste.h"
void cmdExecutaCmdTeste::executa(Simulador &simulador) {
    simulador.executarComandoTeste (this->nome_do_ficheiro);
}

cmdExecutaCmdTeste::cmdExecutaCmdTeste(const std::string &nome_do_ficheiro):
 nome_do_ficheiro (nome_do_ficheiro)
{

}

Comando *cmdExecutaCmdTeste::criar (std::istringstream &iss) {
    std::cout << "Comando executa" << std::endl;
    std::string nomeFicheiro;
    if (iss>>nomeFicheiro) {
        std::cout << "nome do ficheiro lido" << std::endl;
        std::string invalido;
        if (!(iss>>invalido)) {
            std::cout << "A construir o comando cmdExecutaCmdTeste" << std::endl;
            return new cmdExecutaCmdTeste(nomeFicheiro);
        }
        std::cout << "Contem dados invalidos" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return nullptr;
}