#include "Roseira.h"
#include "../Jardim.h"
#include "../Posicao.h"
#include "../../Utils/Settings.h"
#include "../../Utils/Random.h"

Roseira::Roseira()
    : Planta(Beleza::linda),
    nutrientesAcumRoseira(Settings::Roseira::inicial_nutrientes),
    aguaAcumRoseira(Settings::Roseira::inicial_agua),
    instantesVividos(0)
{
}

void Roseira::atualiza(Jardim& jardim, int linha, int coluna) {
    if (morta)
        return;

    ++instantesVividos;

    Posicao& pos = jardim.getPosicao(linha, coluna);

    // 1) Perdas naturais de reservas
    if (aguaAcumRoseira > 0) {
        int perda = Settings::Roseira::perda_agua;
        if (perda > aguaAcumRoseira)
            perda = aguaAcumRoseira;
        aguaAcumRoseira -= perda;
    }

    if (nutrientesAcumRoseira > 0) {
        int perda = Settings::Roseira::perda_nutrientes;
        if (perda > nutrientesAcumRoseira)
            perda = nutrientesAcumRoseira;
        nutrientesAcumRoseira -= perda;
    }

    // 2) Absorver do solo
    int aguaSolo = pos.getAgua();
    if (aguaSolo > 0) {
        int absorver = Settings::Roseira::absorcao_agua;
        if (absorver > aguaSolo)
            absorver = aguaSolo;
        pos.setAgua(aguaSolo - absorver);
        aguaAcumRoseira += absorver;
    }

    int nutSolo = pos.getNutrientes();
    if (nutSolo > 0) {
        int absorver = Settings::Roseira::absorcao_nutrientes;
        if (absorver > nutSolo)
            absorver = nutSolo;
        pos.setNutrientes(nutSolo - absorver);
        nutrientesAcumRoseira += absorver;
    }

    // 3) Verificar morte
    // Morre se:  gua = 0, nutrientes = 0, nutrientes = 200
    if (aguaAcumRoseira < Settings::Roseira::morre_agua_menor ||
        nutrientesAcumRoseira < Settings::Roseira::morre_nutrientes_menor ||
        nutrientesAcumRoseira > Settings::Roseira::morre_nutrientes_maior) {

        // morre: devolve parte dos nutrientes ao solo
        pos.adicionaNutrientes(nutrientesAcumRoseira / 2);
        morta = true;
        return;
    }

    // Verificar se todas as posi  es vizinhas est o ocupadas (tamb m causa morte)
    int linhas = jardim.getLinhas();
    int colunas = jardim.getColunas();

    int dl[8] = { -1,-1,-1, 0,0, 1,1,1 };
    int dc[8] = { -1, 0, 1,-1,1,-1,0,1 };

    int vizinhosOcupados = 0;
    int vizinhosValidos = 0;  // vizinhos dentro dos limites do jardim

    for (int i = 0; i < 8; ++i) {
        int nl = linha + dl[i];
        int nc = coluna + dc[i];

        if (nl < 0 || nl >= linhas || nc < 0 || nc >= colunas)
            continue;

        ++vizinhosValidos;
        Posicao& viz = jardim.getPosicao(nl, nc);
        if (viz.temPlanta()) {
            ++vizinhosOcupados;
        }
    }

    // Se TODAS as posi  es vizinhas v lidas est o ocupadas, morre por "asfixia"
    if (vizinhosValidos > 0 && vizinhosOcupados == vizinhosValidos) {
        pos.adicionaNutrientes(nutrientesAcumRoseira / 2);
        morta = true;
        return;
    }

    // 4) Tentar multiplicar se solo muito f rtil
    if (pos.getNutrientes() <= Settings::Roseira::multiplica_nutrientes_maior)
        return;

    struct Coord {
        int l;
        int c;
    };

    Coord livres[8];
    int nLivres = 0;

    for (int i = 0; i < 8; ++i) {
        int nl = linha + dl[i];
        int nc = coluna + dc[i];

        if (nl < 0 || nl >= linhas || nc < 0 || nc >= colunas)
            continue;

        Posicao& viz = jardim.getPosicao(nl, nc);
        if (!viz.temPlanta()) {
            livres[nLivres].l = nl;
            livres[nLivres].c = nc;
            ++nLivres;
        }
    }

    if (nLivres == 0)
        return; // sem espa o para nova roseira

    int idx = Random::getRandom(0, nLivres - 1);
    Coord escolhido = livres[idx];

    Posicao& dest = jardim.getPosicao(escolhido.l, escolhido.c);

    // Nutrientes para a nova roseira
    int nutrientesSolo = pos.getNutrientes();
    int nutrientesNova = Settings::Roseira::nova_nutrientes;
    if (nutrientesNova > nutrientesSolo)
        nutrientesNova = nutrientesSolo;

    pos.setNutrientes(nutrientesSolo - nutrientesNova);

    auto nova = std::make_unique<Roseira>();
    // Ajustar reservas de acordo com os Settings
    nova->nutrientesAcumRoseira = nutrientesNova;
    int aguaSoloAntes = pos.getAgua();
    int aguaNova = aguaSoloAntes * Settings::Roseira::nova_agua_percentagem / 100;
    nova->aguaAcumRoseira = aguaNova;

    // Atualizar solo e roseira original
    pos.setAgua(aguaSoloAntes - aguaNova);
    nutrientesAcumRoseira = Settings::Roseira::original_nutrientes;
    aguaAcumRoseira = pos.getAgua() * Settings::Roseira::original_agua_percentagem / 100;

    dest.setPlanta(std::move(nova));
}

