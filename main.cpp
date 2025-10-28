#include <iostream>
#include <string>
#include "Model/Simulador.h"
#include "Controller/Comando.h"
#include "Controller/ProcessaCMD.h"
#include "View/Interface.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Simulador simulador;
    Interface interface;
    ProcessaCMD processaCMD;

    interface.mostrarMsg("Ola");
    while (simulador.isJogoAtivo()) {
        std::string comandoUtilizador = interface.lerComando();

        Comando *comando = processaCMD.processa(comandoUtilizador);

        if (comando != nullptr) {
            comando->executa(simulador);
        } else {
            interface.mostrarMsg("Comando invalido");
        }

        interface.mostraJardim(simulador.getGrelhaVisual());
    }
    interface.mostrarMsg("Jogo Terminado!\n");


    return 0;
}
