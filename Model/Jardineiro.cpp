#include "Jardineiro.h"
#include "../Utils/Settings.h"

Jardineiro::Jardineiro()
    : linha(0),
      coluna(0),
      presente(false),
      ferramentaNaMao(nullptr),
      movimentosRestantes(0),
      plantacoesRestantes(0),
      colheitasRestantes(0) {
}

void Jardineiro::entrar(int l, int c) {
    linha = l;
    coluna = c;
    presente = true;
    resetContadoresTurno();
}

void Jardineiro::sair() {
    presente = false;
    ferramentaNaMao=nullptr;
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

void Jardineiro::pegaFerramenta(Ferramenta* f) {
    ferramentaNaMao = f;
}

Ferramenta* Jardineiro::largaFerramentaDaMao() {
    Ferramenta* tmp = ferramentaNaMao;
    ferramentaNaMao = nullptr;
    return tmp;
}

