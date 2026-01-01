#include "Tesoura.h"
#include "../Jardim.h"
#include "../Posicao.h"
#include "../Plantas/Planta.h"
#include <iostream>
#include "../Beleza.h"

bool Tesoura::atua(Jardim& jardim, int linha, int coluna) {
    Posicao& pos = jardim.getPosicao(linha, coluna);
    Planta* planta = pos.getPlanta();

    if (planta == nullptr || planta->estaMorta()) {
        return false; // nada para cortar
    }

    if (planta->getBeleza() == Beleza::feia) {
        std::cout << "Tesoura eliminou planta feia ('" << planta->getChar()
                  << "') em " << char('a' + linha) << char('a' + coluna) << "\n";
        pos.removePlanta();
        return true;
    }

    return false; // planta nao e feia
}