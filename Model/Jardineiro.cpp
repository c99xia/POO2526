#include "Jardineiro.h"
#include "../Utils/Settings.h"

Jardineiro::Jardineiro()
    : linha(0),
    coluna(0),
    presente(false),
    ferramentaNaMao(nullptr),
    movimentosRestantes(0),
    plantacoesRestantes(0),
    colheitasRestantes(0),
    entradasRestantes(1),
    saidasRestantes(1) {
}

bool Jardineiro::podeEntrar() const {
    return entradasRestantes > 0;
}

bool Jardineiro::podeSair() const {
    return presente && saidasRestantes > 0;
}

void Jardineiro::entrar(int l, int c) {
    linha = l;
    coluna = c;
    presente = true;
    --entradasRestantes;

    // Se não estava presente antes, inicializa os contadores
    // (exceto entradas que já foi decrementado)
    if (movimentosRestantes == 0) {
        movimentosRestantes = Settings::Jardineiro::max_movimentos;
        plantacoesRestantes = Settings::Jardineiro::max_plantacoes;
        colheitasRestantes = Settings::Jardineiro::max_colheitas;
    }
}

void Jardineiro::sair() {
    presente = false;
    --saidasRestantes;

    // Ao sair, guarda a ferramenta no inventário
    if (ferramentaNaMao) {
        ferramentas.push_back(std::move(ferramentaNaMao));
    }
}

void Jardineiro::movimentaPara(int novaLinha, int novaColuna) {
    if (!podeMover())
        return;

    linha = novaLinha;
    coluna = novaColuna;
    --movimentosRestantes;
}

void Jardineiro::resetContadoresTurno() {
    movimentosRestantes = Settings::Jardineiro::max_movimentos;
    plantacoesRestantes = Settings::Jardineiro::max_plantacoes;
    colheitasRestantes = Settings::Jardineiro::max_colheitas;
    entradasRestantes = 1;  // máximo 1 entrada por turno
    saidasRestantes = 1;    // máximo 1 saída por turno
}

bool Jardineiro::podeMover() const {
    return presente && movimentosRestantes > 0;
}

bool Jardineiro::podePlantar() const {
    return presente && plantacoesRestantes > 0;
}

void Jardineiro::registaPlantacao() {
    if (plantacoesRestantes > 0) --plantacoesRestantes;
}

bool Jardineiro::podeColher() const {
    return presente && colheitasRestantes > 0;
}

void Jardineiro::registaColheita() {
    if (colheitasRestantes > 0) --colheitasRestantes;
}

void Jardineiro::pegaFerramenta(std::unique_ptr<Ferramenta> f) {
    if (ferramentaNaMao) {
        // Se ja tem uma na mao, guarda no inventario
        ferramentas.push_back(std::move(ferramentaNaMao));
    }
    ferramentaNaMao = std::move(f);
}

std::unique_ptr<Ferramenta> Jardineiro::largaFerramentaDaMao() {
    return std::move(ferramentaNaMao);
}



