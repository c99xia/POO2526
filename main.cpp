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
            // Antes de criar o jardim, só são permitidos: jardim, executa, fim
            bool jardimExiste =
                simulador.getJardim().getLinhas() > 0 &&
                simulador.getJardim().getColunas() > 0;

            if (!jardimExiste) {
                const std::string n = comando->nome();
                if (n != "jardim" && n != "executa" && n != "fim") {
                    interface.mostrarMsg(
                        "Antes de criar o jardim, so sao permitidos: jardim, executa, fim."
                    );
                    delete comando;
                    continue;
                }
            }

            comando->executa(simulador);
            delete comando;

            interface.mostraJardim(simulador.getJardim(), simulador.getJardineiro());

        } else if (!input.empty()) {
            interface.mostrarMsg("Comando invalido.");
        }
    }

    interface.mostrarMsg("A fechar o simulador.");
    return 0;
}
