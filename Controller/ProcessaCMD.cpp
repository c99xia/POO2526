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

    //Comandos para o tempo simulado
    if (cmd == "avanca") {
        std::cout << "Comando avanca" << std::endl;
        int instante = 1;
        if (iss.peek() != EOF) {
            std::cout << "Temos valor para ler" << std::endl;
            if (!(iss >> instante)) {
                std::cout << "Nao foi lido um numero" << std::endl;
                return nullptr;
            }
        }
        std::string invalido;
        if (!(iss >> invalido)) {
            if (instante > 0) {
                std::cout << "A construir o comando cmdAvancaInstante" << std::endl;
                return new cmdAvancaInstante(instante);
            }
            std::cout << "O valor deve ser positivo" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    //Comandos para listar informação
    else if (cmd == "lplantas") {
        std::cout << "Comando lplantas" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdListarPlantasExistentesNoJardim" << std::endl;
            return new cmdListarPlantasExistentesNoJardim();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "lplanta") {
        std::cout << "Comando lplanta posicoes" << std::endl;
        std::string posicao;
        if (iss >> posicao) {
            std::cout << "posicao lido" << std::endl;
            if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
                std::cout << "posicao valida" << std::endl;
                std::string invalido;
                if (!(iss >> invalido)) {
                    int linhaInt = posicao[0] - 'a';
                    int colunaInt = posicao[1] - 'a';
                    std::cout << "A construir o comando cmdListarPropriedadesPlantaPosicao" << std::endl;
                    return new cmdListarPropriedadesPlantaPosicao(linhaInt, colunaInt);
                }
                std::cout << "Contem dados invalidos" << std::endl;
                return nullptr;
            }
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "larea") {
        std::cout << "Comando larea" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdListarArea" << std::endl;
            return new cmdListarArea();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "lsolo") {
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

    else if (cmd == "lferr") {
        std::cout << "Comando lferr" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdListarFerramentas" << std::endl;
            return new cmdListarFerramentas();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    //Comandos para ações
    else if (cmd == "colhe") {
        std::cout << "Comando colhe" << std::endl;
        std::string posicao;
        if (iss >> posicao) {
            std::cout << "posicao lido" << std::endl;
            if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
                int linha = posicao[0] - 'a';
                int coluna = posicao[1] - 'a';
                std::cout << "Posicao valida" << std::endl;

                std::string invalido;
                if (!(iss >> invalido)) {
                    std::cout << "A construir o comando cmdColherPlanta" << std::endl;
                    return new cmdColherPlanta(linha, coluna);
                }
                std::cout << "Contem dados invalidos" << std::endl;
            }
            std::cout << "numero de caracteres invalido ou caracteres nao estao em minusculas" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "planta") {
        std::cout << "Comando planta" << std::endl;
        std::string posicao;
        if (iss >> posicao) {
            std::cout << "posicao lido" << std::endl;
            if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
                std::cout << "posicao valida" << std::endl;

                char tipoPlanta;
                if (iss >> tipoPlanta) {
                    if (tipoPlanta == 'c' || tipoPlanta == 'r' || tipoPlanta == 'e' || tipoPlanta == 'x') {
                        std::string invalido;
                        if (!(iss >> invalido)) {
                            int linha = posicao[0] - 'a';
                            int coluna = posicao[1] - 'a';

                            std::cout << "A construir o comando cmdPlantar" << std::endl;
                            return new cmdPlantar(linha, coluna, tipoPlanta);
                        }
                        std::cout << "Contem dados invalidos" << std::endl;
                        return nullptr;
                    }
                    std::cout << "Nao existe esse tipo de planta" << std::endl;
                    return nullptr;
                }
                std::cout << "Nao foi lido tipoPlanta" << std::endl;
                return nullptr;
            }
            std::cout << "posicao invalida" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "larga") {
        std::cout << "Comando larga" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdLargarFerramenta" << std::endl;
            return new cmdLargarFerramenta();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "pega") {
        std::cout << "Comando pega" << std::endl;
        int numeroSerie;
        if (iss >> numeroSerie) {
            std::cout << "numero de serie lido" << std::endl;
            std::string invalido;
            if (!(iss >> invalido)) {
                if (numeroSerie > 0) {
                    std::cout << "numero de serie valido" << std::endl;
                    return new cmdPegarFerramenta(numeroSerie);
                }
                std::cout << "numero de serie tem que ser positivo" << std::endl;
                return nullptr;
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto" << std::endl;
        return nullptr;
    }

    else if (cmd == "compra") {
        std::cout << "Comando compra" << std::endl;
        char ferramentaComprar;
        if (iss>>ferramentaComprar) {
            std::cout << "Ferramenta a comprar lido" << std::endl;
            if (ferramentaComprar == 'g' || ferramentaComprar == 'a' || ferramentaComprar == 't' || ferramentaComprar == 'z') {
                std::string invalido;
                if (!(iss>>invalido)) {
                    std::cout << "A construir o comando cmdComprarFerramentas" << std::endl;
                    return new cmdComprarFerramenta(ferramentaComprar);
                }
                std::cout << "Contem dados invalidos" << std::endl;
                return nullptr;
            }
            std::cout<< "Nao existe tal ferramenta" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto" << std::endl;
        return nullptr;
    }

    //Comandos para o movimento do jardineiro
    else if (cmd == "e") {
        std::cout << "Comando e" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdMoveEsquerda" << std::endl;
            return new cmdMoveEsquerda();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "d") {
        std::cout << "Comando d" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdMoveDireita" << std::endl;
            return new cmdMoveDireita();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "c") {
        std::cout << "Comando c" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdMoveCima" << std::endl;
            return new cmdMoveCima();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "b") {
        std::cout << "Comando b" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdMoveBaixo" << std::endl;
            return new cmdMoveBaixo();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "entra") {
        std::cout << "Comando entra" << std::endl;
        std::string posicao;
        if (iss >> posicao) {
            std::cout << "posicao lido" << std::endl;
            if (posicao.length() == 2 && islower(posicao[0]) && islower(posicao[1])) {
                int linha = posicao[0] - 'a';
                int coluna = posicao[1] - 'a';
                std::cout << "Posicao valida" << std::endl;

                std::string invalido;
                if (!(iss >> invalido)) {
                    std::cout << "A construir o comando cmdEntraJardineiro" << std::endl;
                    return new cmdEntraJardineiro(linha, coluna);
                }
                std::cout << "Contem dados invalidos" << std::endl;
            }
            std::cout << "numero de caracteres invalido ou caracteres nao estao em minusculas" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    else if (cmd == "sai") {
        std::cout << "Comando sai" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdSaiJardineiro" << std::endl;
            return new cmdSaiJardineiro();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }

    //Comandos adicionais de carácter geral
    else if (cmd == "jardim") {
        std::cout << "Comando jardim" << std::endl;
        int linha, coluna;
        if (iss >> linha) {
            std::cout << "Linha lido com sucesso" << std::endl;
            if (iss >> coluna) {
                std::cout << "Coluna lido com sucesso" << std::endl;
                std::string invalido;
                if (!(iss >> invalido)) {
                    std::cout << "Nao ha dados invalidos" << std::endl;
                    if (linha > 0 && linha <= 26 && coluna > 0 && coluna <= 26) {
                        std::cout << "A construir o comando cmdCriarJardim" << std::endl;
                        return new cmdCriarJardim(linha, coluna);
                    }
                    std::cout << "Os valores das linhas/colunas estao fora dos limites." << std::endl;
                    return nullptr;
                }
                std::cout << "Contem dados invalidos" << std::endl;
                return nullptr;
            }
            std::cout << "Linha valido, mas coluna invalido" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto" << std::endl;
        return nullptr;
    }

    else if (cmd== "grava") {
        std::cout << "Comando grava" << std::endl;
        std::string nome;
        if (iss>>nome) {
            std::cout << "nome lido" << std::endl;
            std::string invalido;
            if (!(iss>>invalido)) {
                std::cout << "A construir o comando cmdGravaEstadoJardim" << std::endl;
                return new cmdGravarEstadoJardim(nome);
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto" << std::endl;
        return  nullptr;
    }

    else if (cmd== "recupera") {
        std::cout << "Comando recupera" << std::endl;
        std::string nome;
        if (iss>>nome) {
            std::cout << "nome lido" << std::endl;
            std::string invalido;
            if (!(iss>>invalido)) {
                std::cout << "A construir o comando cmdRecuperarEstadoJardim" << std::endl;
                return new cmdRecuperarEstadoJardim(nome);
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto" << std::endl;
        return  nullptr;
    }

    else if (cmd== "apaga") {
        std::cout << "Comando apaga" << std::endl;
        std::string nome;
        if (iss>>nome) {
            std::cout << "nome lido" << std::endl;
            std::string invalido;
            if (!(iss>>invalido)) {
                std::cout << "A construir o comando cmdApagarEstadoJardim" << std::endl;
                return new cmdApagarEstadoJardim(nome);
            }
            std::cout << "Contem dados invalidos" << std::endl;
            return nullptr;
        }
        std::cout << "comando incorreto" << std::endl;
        return  nullptr;
    }

    else if (cmd == "executa") {
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
    }
    //a

    else if (cmd == "fim") {
        std::cout << "Comando fim" << std::endl;
        std::string invalido;
        if (!(iss >> invalido)) {
            std::cout << "A construir o comando cmdFim" << std::endl;
            return new cmdFim();
        }
        std::cout << "comando incorreto'" << std::endl;
        return nullptr;
    }
}
