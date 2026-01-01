#include "Posicao.h"

Posicao::Posicao()
    : agua(0),
      nutrientes(0),
      planta(nullptr),
      ferramenta(nullptr) {
}

// Aqui vai o solo, os getters foram feitos inline no posicao.h

//setter
void Posicao::setAgua(int valor) {
    agua = valor;
}

void Posicao::setNutrientes(int valor) {
    nutrientes = valor;
}

void Posicao::adicionaAgua(int quantidadeAgua) {
    agua = agua + quantidadeAgua;
}

void Posicao::adicionaNutrientes(int quantidadeNutriente) {
    nutrientes = nutrientes + quantidadeNutriente;
}

//Planta
//Getter foi feito no posicao.h
void Posicao::setPlanta(Planta *planta) {
    this->planta = planta;
}

bool Posicao::temPlanta() const {
    return planta != nullptr;
}

//Ferramenta
//Getter foi feito no posicao.h
void Posicao::setFerramenta(Ferramenta *ferramenta) {
    this->ferramenta = ferramenta;
}

bool Posicao::temFerramenta() const {
    return ferramenta != nullptr;
}
