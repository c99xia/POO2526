#include "Adubo.h"
#include "../Jardim.h"
#include "../Posicao.h"
#include "../../Utils/Settings.h"
#include <iostream>

bool Adubo::atua(Jardim& jardim, int linha, int coluna) {
    if (aduboAtual <= 0) {
        gasta = true;
        return false;
    }

    Posicao& pos = jardim.getPosicao(linha, coluna);

    int dose = Settings::Adubo::dose;
    if (dose > aduboAtual) dose = aduboAtual;

    pos.adicionaNutrientes(dose);
    aduboAtual -= dose;

    std::cout << "Adubo adicionou " << dose << " nutrientes ao solo em "
              << char('a' + linha) << char('a' + coluna)
              << " (restam " << aduboAtual << ")\n";

    if (aduboAtual <= 0) {
        gasta = true;
        std::cout << "Adubo acabou e sera removido.\n";
    }

    return true;
}
