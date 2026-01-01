#include "cmdComprarFerramenta.h"

void cmdComprarFerramenta::executa(Simulador &simulador)
{
    simulador.comprarFerramenta(this->ferramenta);
}

cmdComprarFerramenta::cmdComprarFerramenta(char ferramenta) :
    ferramenta(ferramenta)
{

}

Comando *cmdComprarFerramenta::criar (std::istringstream &iss) {
    std::cout << "Comando compra" << std::endl;
    char ferramentaComprar;
    if (iss >> ferramentaComprar) {
        std::cout << "Ferramenta a comprar lido" << std::endl;
        if (ferramentaComprar == 'g' || ferramentaComprar == 'a' || ferramentaComprar == 't' || ferramentaComprar ==
            'z') {
            std::string invalido;
            if (!(iss >> invalido)) {
                std::cout << "A construir o comando cmdComprarFerramentas" << std::endl;
                return new cmdComprarFerramenta(ferramentaComprar);
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
            }
        std::cout << "Nao existe tal ferramenta" << std::endl;
        return nullptr;
    }
    std::cout << "comando incorreto" << std::endl;
    return nullptr;
}
