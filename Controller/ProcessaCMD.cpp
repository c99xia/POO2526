//
// Created by xiaro on 10/24/2025.
//

#include "ProcessaCMD.h"

#include <iostream>
#include <sstream>

#include "Acao/cmdColherPlanta.h"
#include "Acao/cmdComprarFerramenta.h"
#include "Acao/cmdLargarFerramenta.h"
#include "Acao/cmdPegarFerramenta.h"
#include "Acao/cmdPlantar.h"
#include "EstadoJogo/cmdApagarEstadoJardim.h"
#include "EstadoJogo/cmdCriarJardim.h"
#include "EstadoJogo/cmdExecutaCmdTeste.h"
#include "EstadoJogo/cmdFim.h"
#include "EstadoJogo/cmdGravarEstadoJardim.h"
#include "EstadoJogo/cmdRecuperarEstadoJardim.h"
#include "Instante/cmdAvancaInstante.h"
#include "Listar/cmdListarArea.h"
#include "Listar/cmdListarCertaArea.h"
#include "Listar/cmdListarFerramentas.h"
#include "Listar/cmdListarPlantasExistentesNoJardim.h"
#include "Listar/cmdListarPropriedadesPlantaPosicao.h"
#include "Movimento/cmdEntraJardineiro.h"
#include "Movimento/cmdMoveBaixo.h"
#include "Movimento/cmdMoveCima.h"
#include "Movimento/cmdMoveDireita.h"
#include "Movimento/cmdMoveEsquerda.h"
#include "Movimento/cmdSaiJardineiro.h"

Comando *ProcessaCMD::processa(std::string &inputUtilizador) {
    std::istringstream iss(inputUtilizador);
    std::string cmd;

    if (!(iss >> cmd)) {
        std::cout << "Utilizador so deu enter" << std::endl;
        return nullptr;
    }

    // Comandos para o tempo simulado
    if (cmd == "avanca") {
        return cmdAvancaInstante::criar(iss);
    }

    // Comandos para listar informação
    else if (cmd == "lplantas") {
        return cmdListarPlantasExistentesNoJardim::criar(iss);
    }
    else if (cmd == "lplanta") {
        return cmdListarPropriedadesPlantaPosicao::criar(iss);
    }
    else if (cmd == "larea") {
        return cmdListarArea::criar(iss);
    }
    else if (cmd == "lsolo") {
        return cmdListarCertaArea::criar(iss);
    }
    else if (cmd == "lferr") {
        return cmdListarFerramentas::criar(iss);
    }

    // Comandos de ação
    else if (cmd == "colhe") {
        return cmdColherPlanta::criar(iss);
    }
    else if (cmd == "planta") {
        return cmdPlantar::criar(iss);
    }
    else if (cmd == "larga") {
        return cmdLargarFerramenta::criar(iss);
    }
    else if (cmd == "pega") {
        return cmdPegarFerramenta::criar(iss);
    }
    else if (cmd == "compra") {
        return cmdComprarFerramenta::criar(iss);
    }

    // Comandos de movimento
    else if (cmd == "e") {
        return cmdMoveEsquerda::criar(iss);
    }
    else if (cmd == "d") {
        return cmdMoveDireita::criar(iss);
    }
    else if (cmd == "c") {
        return cmdMoveCima::criar(iss);
    }
    else if (cmd == "b") {
        return cmdMoveBaixo::criar(iss);
    }
    else if (cmd == "entra") {
        return cmdEntraJardineiro::criar(iss);
    }
    else if (cmd == "sai") {
        return cmdSaiJardineiro::criar(iss);
    }

    // Estado do jogo
    else if (cmd == "jardim") {
        return cmdCriarJardim::criar(iss);
    }
    else if (cmd == "grava") {
        return cmdGravarEstadoJardim::criar(iss);
    }
    else if (cmd == "recupera") {
        return cmdRecuperarEstadoJardim::criar(iss);
    }
    else if (cmd == "apaga") {
        return cmdApagarEstadoJardim::criar(iss);
    }
    else if (cmd == "executa") {
        return cmdExecutaCmdTeste::criar(iss);
    }

    // Fim
    else if (cmd == "fim") {
        return cmdFim::criar(iss);
    }

    std::cout << "Comando desconhecido: " << cmd << std::endl;
    return nullptr;
}


