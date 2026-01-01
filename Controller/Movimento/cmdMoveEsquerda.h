#ifndef PROJETO_CMDMOVEESQUERDA_H
#define PROJETO_CMDMOVEESQUERDA_H
#include "../Comando.h"
#include <sstream>
#include <string>


class cmdMoveEsquerda : public Comando {
public:
    cmdMoveEsquerda() = default;
    std::string nome() const override { return "e"; }

    void executa(Simulador& simulador) override;
    static Comando* criar(std::istringstream& iss);
};
#endif //PROJETO_CMDMOVEESQUERDA_H