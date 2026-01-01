#include "cmdComprarFerramenta.h"

void cmdComprarFerramenta::executa(Simulador& simulador)
{
    simulador.comprarFerramenta(this->ferramenta);
}

cmdComprarFerramenta::cmdComprarFerramenta(char ferramenta) :
    ferramenta(ferramenta)
{

}

Comando* cmdComprarFerramenta::criar(std::istringstream& iss) {
    char ferramentaComprar;
    if (!(iss >> ferramentaComprar)) {
        std::cout << "Erro: compra requer tipo de ferramenta (g/a/t/z)." << std::endl;
        return nullptr;
    }

    if (ferramentaComprar != 'g' && ferramentaComprar != 'a' &&
        ferramentaComprar != 't' && ferramentaComprar != 'z') {
        std::cout << "Erro: tipo invalido (use g, a, t ou z)." << std::endl;
        return nullptr;
        }

    std::string invalido;
    if (iss >> invalido) {
        std::cout << "Erro: argumentos extra invalidos." << std::endl;
        return nullptr;
    }

    return new cmdComprarFerramenta(ferramentaComprar);
}
