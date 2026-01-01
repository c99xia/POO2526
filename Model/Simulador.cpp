#include "Simulador.h"

#include <iostream>

#include "../Model/Posicao.h"
#include "../Model/Plantas/Planta.h"
#include "../Model/Plantas/Cacto.h"
#include "../Model/Plantas/Roseira.h"
#include "../Model/Plantas/Daninha.h"
#include "../Model/Plantas/M4rg4rid4.h"
#include "../Model/Beleza.h"
#include "../Model/Ferramentas/Ferramenta.h"
#include "../Model/Ferramentas/Adubo.h"
#include "../Model/Ferramentas/Regador.h"
#include "../Model/Ferramentas/Tesoura.h"
#include "../Model/Ferramentas/Trator.h"
#include "../Utils/Random.h"



// Função auxiliar apenas visível aqui
const static char *belezaToString(Beleza b) {
    switch (b) {
        case Beleza::linda: return "linda";
        case Beleza::feia: return "feia";
        case Beleza::neutra: return "neutra";
    }
    return "desconhecida";
}

Simulador::Simulador()
    : jogoAtivo(true) {
}

// Funções auxiliares que é afetado pelo tempo

void Simulador::recolherPlantasVivas(std::vector<PlantaCoord> &lista) {
    lista.clear();

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao &pos = jardim.getPosicao(l, c);
            Planta *pl = pos.getPlanta();
            if (pl != nullptr && !pl->estaMorta()) {
                PlantaCoord coord;
                coord.linha = l;
                coord.coluna = c;
                lista.push_back(coord);
            }
        }
    }
}

void Simulador::atualizarPlantas(const std::vector<PlantaCoord> &lista) {
    for (std::size_t i = 0; i < lista.size(); ++i) {
        int l = lista[i].linha;
        int c = lista[i].coluna;

        Posicao &pos = jardim.getPosicao(l, c);
        Planta *pl = pos.getPlanta();

        // Pode já ter sido morta por outra planta entretanto
        if (pl != nullptr && !pl->estaMorta()) {
            pl->atualiza(jardim, l, c);
        }
    }
}

void Simulador::limparPlantasMortas() {
    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao &pos = jardim.getPosicao(l, c);
            Planta *pl = pos.getPlanta();
            if (pl != nullptr && pl->estaMorta()) {
                delete pl;
                pos.setPlanta(nullptr);
            }
        }
    }
}

void Simulador::avancaUmInstante() {
    tempo.avancaUm();
    std::cout << "\n--- Instante " << tempo.getInstante() << " ---\n";

    std::vector<PlantaCoord> listaPlantas;

    // Recolher Plantas vivas
    recolherPlantasVivas(listaPlantas);

    // Atualizar as plantas
    atualizarPlantas(listaPlantas);

    // Limpar Plantas que Morreram
    limparPlantasMortas();

    if (jardineiro.estaPresente()) {
        jardineiro.resetContadoresTurno();
    }
}

// Estado Jardim

void Simulador::criarJardim(int linha, int coluna) {
    jardim.inicializar(linha, coluna);
}

void Simulador::gravarEstadoJardim(const std::string &nome) {
    std::cout << "gravarEstadoJardim(\"" << nome << "\")\n";
}

void Simulador::recuperarEstadoJardim(const std::string &nome) {
    std::cout << "recuperarEstadoJardim(\"" << nome << "\")\n";
}

void Simulador::apagarEstadoJardim(const std::string &nome) {
    std::cout << "apagarEstadoJardim(\"" << nome << "\")\n";
}

void Simulador::executarComandoTeste(const std::string &nome) {
    std::cout << "executarComandoTeste(\"" << nome << "\")\n";
}

// Movimento
void Simulador::moveEsquerda() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (!jardineiro.podeMover()) {
        std::cout << "Sem movimentos restantes neste instante.\n";
        return;
    }

    int l = jardineiro.getLinha();
    int c = jardineiro.getColuna();

    if (c <= 0) {
        std::cout << "Movimento fora dos limites.\n";
        return;
    }

    jardineiro.movimentaPara(l, c - 1);
}

void Simulador::moveDireita() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (!jardineiro.podeMover()) {
        std::cout << "Sem movimentos restantes neste instante.\n";
        return;
    }

    int l = jardineiro.getLinha();
    int c = jardineiro.getColuna();

    if (c >= jardim.getColunas() - 1) {
        std::cout << "Movimento fora dos limites.\n";
        return;
    }

    jardineiro.movimentaPara(l, c + 1);
}

void Simulador::moveCima() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (!jardineiro.podeMover()) {
        std::cout << "Sem movimentos restantes neste instante.\n";
        return;
    }

    int l = jardineiro.getLinha();
    int c = jardineiro.getColuna();

    if (l <= 0) {
        std::cout << "Movimento fora dos limites.\n";
        return;
    }

    jardineiro.movimentaPara(l - 1, c);
}

void Simulador::moveBaixo() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (!jardineiro.podeMover()) {
        std::cout << "Sem movimentos restantes neste instante.\n";
        return;
    }

    int l = jardineiro.getLinha();
    int c = jardineiro.getColuna();

    if (l >= jardim.getLinhas() - 1) {
        std::cout << "Movimento fora dos limites.\n";
        return;
    }

    jardineiro.movimentaPara(l + 1, c);
}


void Simulador::entrarJardineiro(int linha, int coluna) {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    if (jardineiro.estaPresente()) {
        std::cout << "Jardineiro ja esta no jardim.\n";
        return;
    }

    if (linha < 0 || linha >= jardim.getLinhas() ||
        coluna < 0 || coluna >= jardim.getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return;
    }

    jardineiro.entrar(linha, coluna);

    char lChar = 'a' + linha;
    char cChar = 'a' + coluna;

    std::cout << "Jardineiro entrou no jardim em "
            << lChar << cChar << ".\n";
}


void Simulador::sairJardineiro() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    jardineiro.sair();
    std::cout << "Jardineiro saiu do jardim.\n";
}


// Ações
void Simulador::colhePlanta(int linha, int coluna) {
    std::cout << "colhePlanta(" << linha << "," << coluna << ")\n";

    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (!jardineiro.podeColher()) {
        std::cout << "Sem colheitas restantes neste instante.\n";
        return;
    }

    // (Opcional: obrigar a colher na posicao do jardineiro)
    if (linha != jardineiro.getLinha() || coluna != jardineiro.getColuna()) {
        std::cout << "So pode colher na posicao onde o jardineiro esta.\n";
        return;
    }

    if (linha < 0 || linha >= jardim.getLinhas() ||
        coluna < 0 || coluna >= jardim.getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return;
    }

    Posicao &pos = jardim.getPosicao(linha, coluna);
    Planta *pl = pos.getPlanta();

    if (pl == nullptr || pl->estaMorta()) {
        std::cout << "Nao existe planta viva para colher nessa posicao.\n";
        return;
    }


    delete pl;
    pos.setPlanta(nullptr);

    jardineiro.registaColheita();

    std::cout << "Planta colhida com sucesso.\n";
}


void Simulador::plantar(int linha, int coluna, char tipo) {
    std::cout << "plantar(" << linha << "," << coluna << "," << tipo << ")\n";

    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (!jardineiro.podePlantar()) {
        std::cout << "Sem plantacoes restantes neste instante.\n";
        return;
    }

    if (linha != jardineiro.getLinha() || coluna != jardineiro.getColuna()) {
        std::cout << "So pode plantar na posicao onde o jardineiro esta.\n";
        return;
    }

    if (linha < 0 || linha >= jardim.getLinhas() ||
        coluna < 0 || coluna >= jardim.getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return;
    }

    Posicao &pos = jardim.getPosicao(linha, coluna);

    if (pos.temPlanta()) {
        std::cout << "Ja existe uma planta nessa posicao.\n";
        return;
    }

    Planta *nova = nullptr;

    switch (tipo) {
        case 'c':
            nova = new Cacto();
            break;
        case 'r':
            nova = new Roseira();
            break;
        case 'e':
            nova = new Daninha();
            break;
        case 'x':
            nova = new M4rg4rid4();
            break;
        default:
            std::cout << "Tipo de planta invalido.\n";
            return;
    }

    pos.setPlanta(nova);
    jardineiro.registaPlantacao();
    std::cout << "Planta adicionada ao jardim.\n";
}


void Simulador::largarFerramenta() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    Ferramenta* f = jardineiro.getFerramentaNaMao();
    if (f == nullptr) {
        std::cout << "Jardineiro nao tem ferramenta na mao.\n";
        return;
    }

    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    int l = jardineiro.getLinha();
    int c = jardineiro.getColuna();

    Posicao &pos = jardim.getPosicao(l, c);

    if (pos.temFerramenta()) {
        std::cout << "Ja existe uma ferramenta nesta posicao.\n";
        return;
    }

    jardineiro.largaFerramentaDaMao();
    pos.setFerramenta(f);

    char lChar = 'a' + l;
    char cChar = 'a' + c;

    std::cout << "Jardineiro largou ferramenta nSerie="
              << f->getNumeroSerie()
              << " em " << lChar << cChar << ".\n";
}


void Simulador::pegarFerramenta(int numeroSerie) {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    if (jardineiro.getFerramentaNaMao() != nullptr) {
        std::cout << "Jardineiro ja tem uma ferramenta na mao.\n";
        return;
    }

    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    int linhas  = jardim.getLinhas();
    int colunas = jardim.getColunas();

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao &pos = jardim.getPosicao(l, c);
            Ferramenta* f = pos.getFerramenta();

            if (f != nullptr && f->getNumeroSerie() == numeroSerie) {
                // Encontrada no solo
                pos.setFerramenta(nullptr);
                jardineiro.pegaFerramenta(f);

                char lChar = 'a' + l;
                char cChar = 'a' + c;

                std::cout << "Jardineiro apanhou ferramenta nSerie="
                          << numeroSerie
                          << " em " << lChar << cChar << ".\n";
                return;
            }
        }
    }

    std::cout << "Nao existe ferramenta com numero de serie " << numeroSerie << " no solo.\n";
}


void Simulador::comprarFerramenta(char tipo) {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    // Limite de 3 ferramentas em jogo (como indicado nos comentários antigos)
    if (ferramentas.size() >= 3) {
        std::cout << "Ja existem 3 ferramentas em jogo.\n";
        return;
    }

    Ferramenta* nova = nullptr;

    switch (tipo) {
        case 'g': // regador
            nova = new Regador();
            break;
        case 'a': // adubo
            nova = new Adubo();
            break;
        case 't': // tesoura
            nova = new Tesoura();
            break;
        case 'z': // trator
            nova = new Trator();
            break;
        default:
            std::cout << "Tipo de ferramenta invalido.\n";
            return;
    }

    int linhas  = jardim.getLinhas();
    int colunas = jardim.getColunas();

    // Tentar encontrar posicao vazia aleatoria (sem planta e sem ferramenta)
    const int MAX_TENTATIVAS = 100;
    bool colocado = false;
    int pl = 0, pc = 0;

    for (int tent = 0; tent < MAX_TENTATIVAS; ++tent) {
        int l = Random::getRandom(0, linhas  - 1);
        int c = Random::getRandom(0, colunas - 1);

        Posicao &pos = jardim.getPosicao(l, c);
        if (!pos.temPlanta() && !pos.temFerramenta()) {
            pos.setFerramenta(nova);
            pl = l;
            pc = c;
            colocado = true;
            break;
        }
    }

    if (!colocado) {
        std::cout << "Nao foi possivel colocar a ferramenta no jardim.\n";
        delete nova;
        return;
    }

    ferramentas.push_back(nova);

    char linhaChar  = 'a' + pl;
    char colunaChar = 'a' + pc;

    std::cout << "Ferramenta " << nova->getChar()
              << " nSerie=" << nova->getNumeroSerie()
              << " comprada e colocada em "
              << linhaChar << colunaChar << ".\n";
}


//Listar
void Simulador::listarPlantasExistentesNoJardim() {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    bool encontrou = false;

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao &pos = jardim.getPosicao(l, c);
            Planta *pl = pos.getPlanta();

            if (pl != nullptr && !pl->estaMorta()) {
                encontrou = true;

                char linhaChar = 'a' + l;
                char colunaChar = 'a' + c;

                std::cout << linhaChar << colunaChar
                        << "  tipo=" << pl->getChar()
                        << "  beleza=" << belezaToString(pl->getBeleza())
                        << "\n";
            }
        }
    }

    if (!encontrou) {
        std::cout << "Nao existem plantas vivas no jardim.\n";
    }
}

void Simulador::listarPropriedadesPlantaPosicao(int linha, int coluna) {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    if (linha < 0 || linha >= jardim.getLinhas() ||
        coluna < 0 || coluna >= jardim.getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return;
    }

    Posicao &pos = jardim.getPosicao(linha, coluna);
    Planta *pl = pos.getPlanta();

    char linhaChar = 'a' + linha;
    char colunaChar = 'a' + coluna;

    if (pl == nullptr) {
        std::cout << "Nao existe planta na posicao "
                << linhaChar << colunaChar << ".\n";
        return;
    }

    std::cout << "Planta em " << linhaChar << colunaChar << ":\n";
    std::cout << "  tipo   = " << pl->getChar() << "\n";
    std::cout << "  beleza = " << belezaToString(pl->getBeleza()) << "\n";
    std::cout << "  estado = " << (pl->estaMorta() ? "MORTA" : "VIVA") << "\n";
}

void Simulador::listarArea() {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao &pos = jardim.getPosicao(l, c);
            Planta *pl = pos.getPlanta();
            Ferramenta *f = pos.getFerramenta();

            char linhaChar = 'a' + l;
            char colunaChar = 'a' + c;

            std::cout << linhaChar << colunaChar
                    << "  agua=" << pos.getAgua()
                    << "  nutr=" << pos.getNutrientes();

            if (pl != nullptr) {
                std::cout << "  planta=" << pl->getChar()
                        << "  beleza=" << belezaToString(pl->getBeleza());
            } else {
                std::cout << "  planta=-";
            }

            if (f != nullptr) {
                std::cout << "  ferramenta = sim";
            } else {
                std::cout << "  ferramenta = nao";
            }

            std::cout << "\n";
        }
    }
}


void Simulador::listarCertaArea(int linha, int coluna, int raio) {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    if (linha < 0 || linha >= linhas ||
        coluna < 0 || coluna >= colunas) {
        std::cout << "Posicao fora dos limites.\n";
        return;
    }

    if (raio < 0) {
        std::cout << "Raio invalido.\n";
        return;
    }

    int lMin = linha - raio;
    int lMax = linha + raio;
    int cMin = coluna - raio;
    int cMax = coluna + raio;

    if (lMin < 0) lMin = 0;
    if (cMin < 0) cMin = 0;
    if (lMax >= linhas) lMax = linhas - 1;
    if (cMax >= colunas) cMax = colunas - 1;

    for (int l = lMin; l <= lMax; ++l) {
        for (int c = cMin; c <= cMax; ++c) {
            Posicao &pos = jardim.getPosicao(l, c);
            Planta *pl = pos.getPlanta();
            Ferramenta *f = pos.getFerramenta();

            char linhaChar = 'a' + l;
            char colunaChar = 'a' + c;

            std::cout << linhaChar << colunaChar
                    << "  agua=" << pos.getAgua()
                    << "  nutr=" << pos.getNutrientes();

            if (pl != nullptr) {
                std::cout << "  planta=" << pl->getChar()
                        << "  beleza=" << belezaToString(pl->getBeleza());
            } else {
                std::cout << "  planta=-";
            }

            if (f != nullptr) {
                std::cout << "  ferramenta=sim";
            } else {
                std::cout << "  ferramenta=nao";
            }

            std::cout << "\n";
        }
    }
}


void Simulador::listarFerramenta() {
    if (ferramentas.empty()) {
        std::cout << "Nao existem ferramentas criadas.\n";
        return;
    }

    int linhas  = jardimValido() ? jardim.getLinhas()  : 0;
    int colunas = jardimValido() ? jardim.getColunas() : 0;

    for (Ferramenta* f : ferramentas) {
        if (f == nullptr) continue;

        // Ver se esta na mao do jardineiro
        if (jardineiro.getFerramentaNaMao() == f) {
            std::cout << "nSerie=" << f->getNumeroSerie()
                      << " tipo=" << f->getChar()
                      << " local=mao_do_jardineiro\n";
            continue;
        }

        // Ver se esta no solo
        bool encontradaNoSolo = false;
        if (jardimValido()) {
            for (int l = 0; l < linhas && !encontradaNoSolo; ++l) {
                for (int c = 0; c < colunas && !encontradaNoSolo; ++c) {
                    Posicao &pos = jardim.getPosicao(l, c);
                    if (pos.getFerramenta() == f) {
                        char lChar = 'a' + l;
                        char cChar = 'a' + c;

                        std::cout << "nSerie=" << f->getNumeroSerie()
                                  << " tipo=" << f->getChar()
                                  << " local=" << lChar << cChar << "\n";
                        encontradaNoSolo = true;
                    }
                }
            }
        }

        if (!encontradaNoSolo && jardineiro.getFerramentaNaMao() != f) {
            std::cout << "nSerie=" << f->getNumeroSerie()
                      << " tipo=" << f->getChar()
                      << " local=desconhecido\n";
        }
    }
}


//Tempo
void Simulador::avancaInstante(int n) {
    if (n <= 0) {
        std::cout << "Numero de instantes deve ser positivo.\n";
        return;
    }

    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        avancaUmInstante();
    }
}

//UI
std::string Simulador::getGrelhaVisual() const {
    return {};
}

bool Simulador::isJogoAtivo() const {
    return jogoAtivo;
}

void Simulador::terminarJogo() {
    jogoAtivo = false;
}
