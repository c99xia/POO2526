#include "Simulador.h"

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include "../Model/Posicao.h"
#include "../Model/Plantas/Planta.h"
#include "../Model/Plantas/Cacto.h"
#include "../Model/Plantas/Roseira.h"
#include "../Model/Plantas/Daninha.h"
#include "../Model/Plantas/Floribela.h"
#include "../Model/Beleza.h"
#include "../Model/Ferramentas/Ferramenta.h"
#include "../Model/Ferramentas/Adubo.h"
#include "../Model/Ferramentas/Regador.h"
#include "../Model/Ferramentas/Tesoura.h"
#include "../Model/Ferramentas/Trator.h"
#include "../Utils/Random.h"
#include "../Controller/ProcessaCMD.h"

// Função auxiliar apenas visível aqui
const static char* belezaToString(Beleza b) {
    switch (b) {
    case Beleza::linda: return "linda";
    case Beleza::feia: return "feia";
    case Beleza::neutra: return "neutra";
    }
    return "desconhecida";
}

Simulador::Simulador()
    : jogoAtivo(true), jardimCriado(false) {
}


// Funções auxiliares que é afetado pelo tempo

void Simulador::recolherPlantasVivas(std::vector<PlantaCoord>& lista) {
    lista.clear();

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao& pos = jardim.getPosicao(l, c);
            Planta* pl = pos.getPlanta();
            if (pl != nullptr && !pl->estaMorta()) {
                PlantaCoord coord;
                coord.linha = l;
                coord.coluna = c;
                lista.push_back(coord);
            }
        }
    }
}

void Simulador::atualizarPlantas(const std::vector<PlantaCoord>& lista) {
    for (std::size_t i = 0; i < lista.size(); ++i) {
        int l = lista[i].linha;
        int c = lista[i].coluna;

        Posicao& pos = jardim.getPosicao(l, c);
        Planta* pl = pos.getPlanta();

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
            Posicao& pos = jardim.getPosicao(l, c);
            Planta* pl = pos.getPlanta();
            if (pl != nullptr && pl->estaMorta()) {
                pos.removePlanta();
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

    // Ferramenta na mão do jardineiro atua automaticamente
    if (jardineiro.estaPresente()) {
        Ferramenta* f = jardineiro.getFerramentaNaMao();
        if (f != nullptr) {
            int l = jardineiro.getLinha();
            int c = jardineiro.getColuna();

            f->atua(jardim, l, c);

            // Se a ferramenta ficou gasta, remove-a
            if (f->estaGasta()) {
                jardineiro.largaFerramentaDaMao(); // unique_ptr limpa automaticamente
                std::cout << "Ferramenta gasta foi removida.\n";
            }
        }
    }

    // Resetar contadores do turno (sempre, mesmo que não esteja presente)
    // para permitir nova entrada no próximo turno
    jardineiro.resetContadoresTurno();
}

void Simulador::colocarFerramentaAleatoria() {
    if (!jardimValido()) return;

    // Escolher tipo aleatório (g, a, t, z)
    int tipo = Random::getRandom(0, 3);
    std::unique_ptr<Ferramenta> nova;

    switch (tipo) {
    case 0: nova = std::make_unique<Regador>(); break;
    case 1: nova = std::make_unique<Adubo>(); break;
    case 2: nova = std::make_unique<Tesoura>(); break;
    case 3: nova = std::make_unique<Trator>(); break;
    }

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    const int MAX_TENTATIVAS = 100;
    Ferramenta* ptr = nova.get();

    for (int tent = 0; tent < MAX_TENTATIVAS; ++tent) {
        int l = Random::getRandom(0, linhas - 1);
        int c = Random::getRandom(0, colunas - 1);

        Posicao& pos = jardim.getPosicao(l, c);
        if (!pos.temPlanta() && !pos.temFerramenta()) {
            pos.setFerramenta(std::move(nova));
            std::cout << "Ferramenta " << ptr->getChar()
                << " nSerie=" << ptr->getNumeroSerie()
                << " colocada em " << char('a' + l) << char('a' + c) << "\n";
            return;
        }
    }
}

void Simulador::colocarFerramentasIniciais(int n) {
    std::cout << "A colocar " << n << " ferramentas aleatorias no jardim...\n";
    for (int i = 0; i < n; ++i) {
        colocarFerramentaAleatoria();
    }
}

// Estado Jardim

void Simulador::criarJardim(int linha, int coluna) {
    if (jardimCriado) {
        std::cout << "O jardim ja foi criado e nao pode ser criado novamente.\n";
        return;
    }

    // Validar dimensão máxima (26x26 conforme enunciado)
    if (linha <= 0 || coluna <= 0) {
        std::cout << "Dimensoes do jardim devem ser positivas.\n";
        return;
    }

    if (linha > 26 || coluna > 26) {
        std::cout << "Dimensao maxima do jardim e 26x26.\n";
        return;
    }

    jardim.inicializar(linha, coluna);
    jardimCriado = true;

    std::cout << "Jardim criado com sucesso (" << linha << "x" << coluna << ").\n";

    // Colocar 3 ferramentas aleatórias no início (conforme enunciado)
    colocarFerramentasIniciais(3);
}


void Simulador::gravarEstadoJardim(const std::string& nome) {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado para gravar.\n";
        return;
    }

    EstadoJogo estado;
    estado.linhas = jardim.getLinhas();
    estado.colunas = jardim.getColunas();
    estado.instanteAtual = tempo.getInstante();

    // Guardar estado do jardineiro
    estado.jardineiroPresente = jardineiro.estaPresente();
    estado.jardineiroLinha = jardineiro.getLinha();
    estado.jardineiroColuna = jardineiro.getColuna();

    // Guardar estado de cada posição
    for (int l = 0; l < estado.linhas; ++l) {
        for (int c = 0; c < estado.colunas; ++c) {
            const Posicao& pos = jardim.getPosicao(l, c);
            EstadoPosicao ep;

            ep.agua = pos.getAgua();
            ep.nutrientes = pos.getNutrientes();

            // Guardar tipo de planta
            Planta* pl = pos.getPlanta();
            if (pl != nullptr && !pl->estaMorta()) {
                ep.tipoPlanta = pl->getChar();
            }
            else {
                ep.tipoPlanta = '\0';
            }

            // Guardar tipo de ferramenta
            Ferramenta* f = pos.getFerramenta();
            if (f != nullptr) {
                ep.tipoFerramenta = f->getChar();
                ep.ferramentaSerie = f->getNumeroSerie();
            }
            else {
                ep.tipoFerramenta = '\0';
                ep.ferramentaSerie = 0;
            }

            estado.posicoes.push_back(ep);
        }
    }

    // Guardar no map (sobrescreve se já existir)
    estadosGuardados[nome] = estado;

    std::cout << "Estado do jardim gravado com o nome '" << nome << "'.\n";
}

void Simulador::recuperarEstadoJardim(const std::string& nome) {
    // Procurar no map
    auto it = estadosGuardados.find(nome);
    if (it == estadosGuardados.end()) {
        std::cout << "Nao existe estado guardado com o nome '" << nome << "'.\n";
        return;
    }

    const EstadoJogo& estado = it->second;

    // Reinicializar o jardim com as dimensões guardadas
    jardim.inicializar(estado.linhas, estado.colunas);
    jardimCriado = true;

    // Restaurar estado de cada posição
    int idx = 0;
    for (int l = 0; l < estado.linhas; ++l) {
        for (int c = 0; c < estado.colunas; ++c) {
            const EstadoPosicao& ep = estado.posicoes[idx++];
            Posicao& pos = jardim.getPosicao(l, c);

            pos.setAgua(ep.agua);
            pos.setNutrientes(ep.nutrientes);

            // Restaurar planta
            pos.removePlanta();
            if (ep.tipoPlanta != '\0') {
                std::unique_ptr<Planta> nova;
                switch (ep.tipoPlanta) {
                case 'c': nova = std::make_unique<Cacto>(); break;
                case 'r': nova = std::make_unique<Roseira>(); break;
                case 'e': nova = std::make_unique<Daninha>(); break;
                case 'x': nova = std::make_unique<Floribela>(); break;
                }
                if (nova) {
                    pos.setPlanta(std::move(nova));
                }
            }

            // Restaurar ferramenta (nota: cria nova ferramenta, número de série será diferente)
            if (ep.tipoFerramenta != '\0') {
                std::unique_ptr<Ferramenta> nova;
                switch (ep.tipoFerramenta) {
                case 'g': nova = std::make_unique<Regador>(); break;
                case 'a': nova = std::make_unique<Adubo>(); break;
                case 't': nova = std::make_unique<Tesoura>(); break;
                case 'z': nova = std::make_unique<Trator>(); break;
                }
                if (nova) {
                    pos.setFerramenta(std::move(nova));
                }
            }
        }
    }

    // Restaurar jardineiro
    if (estado.jardineiroPresente) {
        jardineiro.entrar(estado.jardineiroLinha, estado.jardineiroColuna);
    }
    else {
        // Se o jardineiro estava fora, garantir que está fora
        if (jardineiro.estaPresente()) {
            jardineiro.sair();
        }
    }

    // Restaurar instante
    tempo.setInstante(estado.instanteAtual);

    std::cout << "Estado do jardim '" << nome << "' recuperado.\n";
    std::cout << "  Dimensao: " << estado.linhas << "x" << estado.colunas << "\n";
    std::cout << "  Instante: " << tempo.getInstante() << "\n";
}

void Simulador::apagarEstadoJardim(const std::string& nome) {
    auto it = estadosGuardados.find(nome);
    if (it == estadosGuardados.end()) {
        std::cout << "Nao existe estado guardado com o nome '" << nome << "'.\n";
        return;
    }

    estadosGuardados.erase(it);
    std::cout << "Estado '" << nome << "' apagado com sucesso.\n";
}

void Simulador::executarComandoTeste(const std::string& nomeFicheiro) {
    std::ifstream ficheiro(nomeFicheiro);

    if (!ficheiro.is_open()) {
        std::cout << "Erro: Nao foi possivel abrir o ficheiro '" << nomeFicheiro << "'.\n";
        return;
    }

    std::cout << "=== A executar comandos do ficheiro '" << nomeFicheiro << "' ===\n";

    ProcessaCMD processador;
    std::string linha;
    int numLinha = 0;

    while (std::getline(ficheiro, linha)) {
        ++numLinha;

        // Ignorar linhas vazias ou comentários (linhas que começam com #)
        if (linha.empty() || linha[0] == '#') {
            continue;
        }

        std::cout << "\n[Linha " << numLinha << "] Comando: " << linha << "\n";

        Comando* comando = processador.processa(linha);

        if (comando != nullptr) {
            // Verificar se o jardim existe (exceto para jardim, executa, fim)
            bool jardimExiste = jardimValido();

            if (!jardimExiste) {
                const std::string n = comando->nome();
                if (n != "jardim" && n != "executa" && n != "fim") {
                    std::cout << "  -> Ignorado: Jardim ainda nao foi criado.\n";
                    delete comando;
                    continue;
                }
            }

            comando->executa(*this);
            delete comando;

            // Se o comando foi "fim", parar a execução do ficheiro
            if (!jogoAtivo) {
                std::cout << "Comando 'fim' executado. A parar execucao do ficheiro.\n";
                break;
            }
        }
        else {
            std::cout << "  -> Comando invalido ignorado.\n";
        }
    }

    ficheiro.close();
    std::cout << "=== Fim da execucao do ficheiro '" << nomeFicheiro << "' ===\n";
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

    if (linha < 0 || linha >= jardim.getLinhas() ||
        coluna < 0 || coluna >= jardim.getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return;
    }

    // Verificar se pode entrar (máximo 1 entrada por turno)
    if (!jardineiro.podeEntrar()) {
        std::cout << "Ja usou a entrada neste turno (maximo 1 por turno).\n";
        return;
    }

    jardineiro.entrar(linha, coluna);

    char lChar = 'a' + linha;
    char cChar = 'a' + coluna;

    if (jardineiro.estaPresente()) {
        std::cout << "Jardineiro entrou/teletransportou para "
            << lChar << cChar << ".\n";
    }
}


void Simulador::sairJardineiro() {
    if (!jardineiro.estaPresente()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return;
    }

    // Verificar se pode sair (máximo 1 saída por turno)
    if (!jardineiro.podeSair()) {
        std::cout << "Ja usou a saida neste turno (maximo 1 por turno).\n";
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

    Posicao& pos = jardim.getPosicao(linha, coluna);
    Planta* pl = pos.getPlanta();

    if (pl == nullptr || pl->estaMorta()) {
        std::cout << "Nao existe planta viva para colher nessa posicao.\n";
        return;
    }


    pos.removePlanta();


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

    Posicao& pos = jardim.getPosicao(linha, coluna);

    if (pos.temPlanta()) {
        std::cout << "Ja existe uma planta nessa posicao.\n";
        return;
    }

    std::unique_ptr<Planta> nova;

    switch (tipo) {
    case 'c': nova = std::make_unique<Cacto>(); break;
    case 'r': nova = std::make_unique<Roseira>(); break;
    case 'e': nova = std::make_unique<Daninha>(); break;
    case 'x': nova = std::make_unique<Floribela>(); break;
    default:
        std::cout << "Tipo de planta invalido.\n";
        return;
    }

    pos.setPlanta(std::move(nova));

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

    Posicao& pos = jardim.getPosicao(l, c);

    if (pos.temFerramenta()) {
        std::cout << "Ja existe uma ferramenta nesta posicao.\n";
        return;
    }

    int nSerie = f->getNumeroSerie();

    // Mover ownership da mao para o solo
    pos.setFerramenta(jardineiro.largaFerramentaDaMao());

    char lChar = 'a' + l;
    char cChar = 'a' + c;

    std::cout << "Jardineiro largou ferramenta nSerie="
        << nSerie
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

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao& pos = jardim.getPosicao(l, c);
            Ferramenta* f = pos.getFerramenta();

            if (f != nullptr && f->getNumeroSerie() == numeroSerie) {
                // Encontrada no solo - mover ownership para o jardineiro
                jardineiro.pegaFerramenta(pos.retiraFerramenta());

                char lChar = 'a' + l;
                char cChar = 'a' + c;

                std::cout << "Jardineiro apanhou ferramenta nSerie="
                    << numeroSerie
                    << " em " << lChar << cChar << ".\n";

                // Sempre que uma ferramenta é apanhada, surge outra aleatória
                colocarFerramentaAleatoria();

                return;
            }
        }
    }

    std::cout << "Nao existe ferramenta com numero de serie " << numeroSerie << " no solo.\n";
}


void Simulador::comprarFerramenta(char tipo) {
    if (!jardimValido()) { std::cout << "Nao existe jardim criado.\n"; return; }

    std::unique_ptr<Ferramenta> nova;

    switch (tipo) {
    case 'g': nova = std::make_unique<Regador>(); break;
    case 'a': nova = std::make_unique<Adubo>(); break;
    case 't': nova = std::make_unique<Tesoura>(); break;
    case 'z': nova = std::make_unique<Trator>(); break;
    default:  std::cout << "Tipo de ferramenta invalido.\n"; return;
    }

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    const int MAX_TENTATIVAS = 100;
    bool colocado = false;
    int pl = 0, pc = 0;

    Ferramenta* ptr = nova.get(); // ponteiro não-dono para mensagens

    for (int tent = 0; tent < MAX_TENTATIVAS; ++tent) {
        int l = Random::getRandom(0, linhas - 1);
        int c = Random::getRandom(0, colunas - 1);

        Posicao& pos = jardim.getPosicao(l, c);
        if (!pos.temPlanta() && !pos.temFerramenta()) {
            pos.setFerramenta(std::move(nova));
            pl = l; pc = c;
            colocado = true;
            break;
        }
    }

    if (!colocado) {
        std::cout << "Nao foi possivel colocar a ferramenta no jardim.\n";
        return; // unique_ptr limpa sozinho
    }

    std::cout << "Ferramenta " << ptr->getChar()
        << " nSerie=" << ptr->getNumeroSerie()
        << " comprada e colocada em "
        << char('a' + pl) << char('a' + pc) << ".\n";
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
            Posicao& pos = jardim.getPosicao(l, c);
            Planta* pl = pos.getPlanta();

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

    Posicao& pos = jardim.getPosicao(linha, coluna);
    Planta* pl = pos.getPlanta();

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
            Posicao& pos = jardim.getPosicao(l, c);
            Planta* pl = pos.getPlanta();
            Ferramenta* f = pos.getFerramenta();

            char linhaChar = 'a' + l;
            char colunaChar = 'a' + c;

            std::cout << linhaChar << colunaChar
                << "  agua=" << pos.getAgua()
                << "  nutr=" << pos.getNutrientes();

            if (pl != nullptr) {
                std::cout << "  planta=" << pl->getChar()
                    << "  beleza=" << belezaToString(pl->getBeleza());
            }
            else {
                std::cout << "  planta=-";
            }

            if (f != nullptr) {
                std::cout << "  ferramenta = sim";
            }
            else {
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
            Posicao& pos = jardim.getPosicao(l, c);
            Planta* pl = pos.getPlanta();
            Ferramenta* f = pos.getFerramenta();

            char linhaChar = 'a' + l;
            char colunaChar = 'a' + c;

            std::cout << linhaChar << colunaChar
                << "  agua=" << pos.getAgua()
                << "  nutr=" << pos.getNutrientes();

            if (pl != nullptr) {
                std::cout << "  planta=" << pl->getChar()
                    << "  beleza=" << belezaToString(pl->getBeleza());
            }
            else {
                std::cout << "  planta=-";
            }

            if (f != nullptr) {
                std::cout << "  ferramenta=sim";
            }
            else {
                std::cout << "  ferramenta=nao";
            }

            std::cout << "\n";
        }
    }
}


void Simulador::listarFerramenta() {
    if (!jardimValido()) {
        std::cout << "Nao existe jardim criado.\n";
        return;
    }

    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    bool encontrou = false;

    // Listar ferramenta na mao do jardineiro
    if (jardineiro.estaPresente()) {
        Ferramenta* f = jardineiro.getFerramentaNaMao();
        if (f != nullptr) {
            std::cout << "nSerie=" << f->getNumeroSerie()
                << " tipo=" << f->getChar()
                << " local=mao_do_jardineiro\n";
            encontrou = true;
        }

        // Listar ferramentas no inventario do jardineiro
        const auto& inv = jardineiro.getInventario();
        for (const auto& ferr : inv) {
            if (ferr) {
                std::cout << "nSerie=" << ferr->getNumeroSerie()
                    << " tipo=" << ferr->getChar()
                    << " local=inventario_jardineiro\n";
                encontrou = true;
            }
        }
    }

    // Listar ferramentas no solo
    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            Posicao& pos = jardim.getPosicao(l, c);
            Ferramenta* f = pos.getFerramenta();
            if (f != nullptr) {
                char lChar = 'a' + l;
                char cChar = 'a' + c;

                std::cout << "nSerie=" << f->getNumeroSerie()
                    << " tipo=" << f->getChar()
                    << " local=" << lChar << cChar << "\n";
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        std::cout << "Nao existem ferramentas no jardim.\n";
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
