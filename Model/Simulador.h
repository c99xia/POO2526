#ifndef PROJETO_SIMULADOR_H
#define PROJETO_SIMULADOR_H

#include <string>
#include <vector>

#include "Jardim.h"
#include "Jardineiro.h"
#include "../Utils/Tempo.h"
#include <map>
// Estrutura para guardar o estado de uma posição
struct EstadoPosicao {
    int agua;
    int nutrientes;
    char tipoPlanta;      // '\0' se não há planta
    char tipoFerramenta;  // '\0' se não há ferramenta
    int ferramentaSerie;  // número de série da ferramenta (se existir)
};

// Estrutura para guardar o estado completo do jogo
struct EstadoJogo {
    int linhas;
    int colunas;
    int instanteAtual;
    std::vector<EstadoPosicao> posicoes;

    // Estado do jardineiro
    bool jardineiroPresente;
    int jardineiroLinha;
    int jardineiroColuna;
};

//o Simulador é quem manda em tudo.
class Simulador {
    Jardim jardim;  //O simulador tem um jardim, e tem um jardineiro e tem tempo
    //Quando tempo avança ele avisa o jardim
    bool jardimCriado;
    Jardineiro jardineiro;
    Tempo tempo;
    bool jogoAtivo;
    // Ferramentas estao no solo (Posicao) ou na mao/inventario do Jardineiro

    // Map para guardar estados do jogo por nome
    std::map<std::string, EstadoJogo> estadosGuardados;

    //Funções auxiliares são todas private

    struct PlantaCoord {
        int linha;
        int coluna;
    };

    bool jardimValido() const { return jardim.getLinhas() > 0 && jardim.getColunas() > 0; }
    void avancaUmInstante();

    void recolherPlantasVivas(std::vector<PlantaCoord>& lista);
    void atualizarPlantas(const std::vector<PlantaCoord>& lista);
    void limparPlantasMortas();

    // Coloca uma ferramenta aleatória numa posição livre do jardim
    void colocarFerramentaAleatoria();

    // Coloca n ferramentas aleatórias no jardim
    void colocarFerramentasIniciais(int n);

public:
    Simulador();

    const Jardim& getJardim() const { return jardim; }
    const Jardineiro& getJardineiro() const { return jardineiro; }

    int getInstanteAtual() const { return tempo.getInstante(); }

    // Estado do jardim
    void criarJardim(int linha, int coluna);
    void gravarEstadoJardim(const std::string& nome);
    void recuperarEstadoJardim(const std::string& nome);
    void apagarEstadoJardim(const std::string& nome);
    void executarComandoTeste(const std::string& nome);

    // Movimento
    void moveEsquerda();
    void moveDireita();
    void moveCima();
    void moveBaixo();
    void entrarJardineiro(int linha, int coluna);
    void sairJardineiro();

    // Ações
    void colhePlanta(int linha, int coluna);
    void plantar(int linha, int coluna, char tipo);
    void largarFerramenta();
    void pegarFerramenta(int numeroSerie);
    void comprarFerramenta(char tipo);

    // Listagem
    void listarPlantasExistentesNoJardim();
    void listarPropriedadesPlantaPosicao(int linha, int coluna);
    void listarArea();
    void listarCertaArea(int linha, int coluna, int raio);
    void listarFerramenta();

    // Tempo
    void avancaInstante(int n);

    // Interface
    std::string getGrelhaVisual() const;

    bool isJogoAtivo() const;
    void terminarJogo();
};


#endif //PROJETO_SIMULADOR_H
