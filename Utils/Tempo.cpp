#include "Tempo.h"

Tempo::Tempo()
    : instanteAtual(0)
{
}

int Tempo::getInstante() const {
    return instanteAtual;
}

void Tempo::reset() {
    instanteAtual = 0;
}

void Tempo::setInstante(int valor) {
    if (valor >= 0) {
        instanteAtual = valor;
    }
}

void Tempo::avancaUm() {
    ++instanteAtual;
}

void Tempo::avancaN(int n) {
    if (n > 0)
        instanteAtual += n;
}
