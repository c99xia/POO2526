#include <iostream>
#include <string>
#include "Model/Simulador.h"
#include "Controller/Comando.h"
#include "Controller/ProcessaCMD.h"
#include "View/Interface.h"

int main() {
    Simulador simulador;
    Interface interface;
    ProcessaCMD processador;

    interface.mostrarMsg("Bem vindo ao jogo");

    while (simulador.isJogoAtivo()) {
        std::string input = interface.lerComando();
        Comando* comando = processador.processa(input);

        if (comando != nullptr) {
            comando->executa(simulador);
            delete comando;


            interface.mostraJardim(simulador.getJardim());
        } else if (!input.empty()) {
            interface.mostrarMsg("Comando invalido.");
        }
    }

    interface.mostrarMsg("A fechar o simulador.");

    return 0;
}
