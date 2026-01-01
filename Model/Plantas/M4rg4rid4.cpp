#include "M4rg4rid4.h"
#include "../Posicao.h"
#include "../../Utils/Settings.h"

M4rg4rid4::M4rg4rid4()
    : Planta(Beleza::linda),   // ou neutra, como quiseres
      nutrientesAcumM4rg4rid4(0),
      aguaAcumM4rg4rid4(0),
      instantesVividos(0)
{
}

void M4rg4rid4::atualiza(Jardim &jardim, int linha, int coluna) {
    ++instantesVividos;

    Posicao &pos = jardim.getPosicao(linha, coluna);

    int aguaSolo = pos.getAgua();
    if (aguaSolo > 0) {
        int absorver = Settings::ErvaDaninha::absorcao_agua;
        if (absorver > aguaSolo) absorver = aguaSolo;
        pos.setAgua(aguaSolo - absorver);
        aguaAcumM4rg4rid4 += absorver;
    }

    int nutSolo = pos.getNutrientes();
    if (nutSolo > 0) {
        int absorver = Settings::ErvaDaninha::absorcao_nutrientes;
        if (absorver > nutSolo) absorver = nutSolo;
        pos.setNutrientes(nutSolo - absorver);
        nutrientesAcumM4rg4rid4 += absorver;
    }
}
