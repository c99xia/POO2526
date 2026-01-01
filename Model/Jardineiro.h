#ifndef PROJETO_JARDINEIRO_H
#define PROJETO_JARDINEIRO_H

#include <vector>
#include "Ferramentas/Ferramenta.h"
#include <memory>

class Jardineiro {
    int linha;
    int coluna;
    bool presente;

    std::unique_ptr<Ferramenta> ferramentaNaMao;
    std::vector<std::unique_ptr<Ferramenta>> ferramentas; // inventario

    int movimentosRestantes;
    int plantacoesRestantes;
    int colheitasRestantes;
    int entradasRestantes;  // máximo 1 entrada por turno
    int saidasRestantes;    // máximo 1 saída por turno

public:
    Jardineiro();

    bool estaPresente() const { return presente; }
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }

    int getMovimentosRestantes() const { return movimentosRestantes; }
    int getPlantacoesRestantes() const { return plantacoesRestantes; }
    int getColheitasRestantes() const { return colheitasRestantes; }
    int getEntradasRestantes() const { return entradasRestantes; }
    int getSaidasRestantes() const { return saidasRestantes; }

    Ferramenta* getFerramentaNaMao() const { return ferramentaNaMao.get(); }
    const std::vector<std::unique_ptr<Ferramenta>>& getInventario() const { return ferramentas; }

    // Verificações de ações permitidas
    bool podeEntrar() const;
    bool podeSair() const;
    bool podeMover() const;
    bool podePlantar() const;
    bool podeColher() const;

    // Ações
    void entrar(int l, int c);
    void sair();
    void movimentaPara(int novaLinha, int novaColuna);

    void resetContadoresTurno();

    void registaPlantacao();
    void registaColheita();

    // Pegar ferramenta do solo (recebe ownership)
    void pegaFerramenta(std::unique_ptr<Ferramenta> f);

    // Largar ferramenta da mao (devolve ownership)
    std::unique_ptr<Ferramenta> largaFerramentaDaMao();
};


#endif //PROJETO_JARDINEIRO_H
