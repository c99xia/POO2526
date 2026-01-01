#include "Trator.h"
#include "../Jardim.h"
#include "../Plantas/Planta.h"
#include "../Posicao.h"
#include <iostream>

Trator::Trator()
: usosRestantes(3) // pode ser usado 3 vezes
{
}

bool Trator::atua(Jardim& jardim, int linha, int coluna) {
    if (usosRestantes <= 0) {
        gasta = true;
        return false;
    }

    int linhas = jardim.getLinhas();
    int plantasRemovidas = 0;

    // Limpa todas as plantas na coluna atual
    for (int l = 0; l < linhas; ++l) {
        Posicao& pos = jardim.getPosicao(l, coluna);
        Planta* planta = pos.getPlanta();

        if (planta != nullptr && !planta->estaMorta()) {
            std::cout << "Trator removeu planta ('" << planta->getChar()
                      << "') em " << char('a' + l) << char('a' + coluna) << "\n";
            pos.removePlanta();
            ++plantasRemovidas;
        }
    }

    --usosRestantes;

    std::cout << "Trator limpou coluna " << char('A' + coluna)
              << " - " << plantasRemovidas << " plantas removidas"
              << " (usos restantes: " << usosRestantes << ")\n";

    if (usosRestantes <= 0) {
        gasta = true;
        std::cout << "Trator ficou sem combustivel e sera removido.\n";
    }

    return plantasRemovidas > 0;
}