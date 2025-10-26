//
// Created by xiaro on 10/24/2025.
//

#ifndef PROJETO_SIMULADOR_H
#define PROJETO_SIMULADOR_H
#include <string>

#include "Jardim.h"
#include "Jardineiro.h"



class Simulador {
    Jardim jardim;
    bool jogoAtivo;

    public:

    //Construtor
    Simulador();



    //Funções dos Comandos Carácter Geral
    void criarJardim (int linha, int coluna);
    void gravarEstadoJardim (std::string nome);
    void recuperarEstadoJardim (std::string nome);
    void apagarEstadoJardim (std::string nome);
    void executarComandoTeste (std::string nome);
    void fim ();

    //Funções para o movimento do jardineiro
    void moveEsquerda ();
    void moveDireita ();
    void moveCima();
    void entrarJardineiro (int linha, int coluna);
    void sairJardineiro (int linha, int coluna);

    //Funções para ações
    void colhePlanta (int linha, int coluna);
    void plantar (int linha, int coluna, char tipo);
    void largarFerramenta ();
    void pegarFerramenta (char tipo); //não sei;
    void comprarFerramenta (char tipo);

    //Funções listar informação
    void listarPlantasExistentesNoJardim ();
    void listarPropriedadesPlantaPosicao (int linha, int coluna);
    void listarArea ();
    void listarCertaArea (int linha, int coluna, int raio);
    void listarFerramenta ();

    //Função para avançar instante
    void avancaInstante (int n);

    //Funções para a Interface
    std::string getGrelhaVisual () const;
    bool isJogoAtivo () const;
    void terminarJogo ();
};


#endif //PROJETO_SIMULADOR_H