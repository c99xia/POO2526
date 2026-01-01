#include "Posicao.h"
#include <utility> // std::move
#include "Plantas/Planta.h"
#include "Ferramentas/Ferramenta.h"

Posicao::Posicao()
    : agua(0),
    nutrientes(0),
    planta(nullptr),
    ferramenta(nullptr)
{
}

Posicao::~Posicao() = default;

void Posicao::setAgua(int valor) {
    agua = valor;
}

void Posicao::setNutrientes(int valor) {
    nutrientes = valor;
}

void Posicao::adicionaAgua(int quantidadeAgua) {
    agua += quantidadeAgua;
}

void Posicao::adicionaNutrientes(int quantidadeNutriente) {
    nutrientes += quantidadeNutriente;
}

// Planta
void Posicao::setPlanta(std::unique_ptr<Planta> p) {
    planta = std::move(p);
}

// Ferramenta
void Posicao::setFerramenta(std::unique_ptr<Ferramenta> f) {
    ferramenta = std::move(f);
}

std::unique_ptr<Ferramenta> Posicao::retiraFerramenta() {
    return std::move(ferramenta); // devolve e fica a nullptr
}

void Posicao::removePlanta() {
    planta.reset();
}
