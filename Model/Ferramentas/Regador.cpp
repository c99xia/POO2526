#include "Regador.h"
#include "../../Utils/Settings.h"
#include "../Jardim.h"
#include <iostream>
#include "../Posicao.h"

bool Regador::atua(Jardim& jardim, int linha, int coluna) {
    if (aguaAtual <= 0) {
        gasta = true;
        return false;
    }

    Posicao& pos = jardim.getPosicao(linha, coluna);

    int dose = Settings::Regador::dose;
    if (dose > aguaAtual) dose = aguaAtual;

    pos.adicionaAgua(dose);
    aguaAtual -= dose;

    std::cout << "Regador adicionou " << dose << " agua ao solo em "
              << char('a' + linha) << char('a' + coluna)
              << " (restam " << aguaAtual << ")\n";

    if (aguaAtual <= 0) {
        gasta = true;
        std::cout << "Regador ficou vazio e sera removido.\n";
    }

    return true;
}