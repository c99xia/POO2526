#include "Ferramenta.h"

int Ferramenta::proximoNumeroSerie = 1;

Ferramenta::Ferramenta()
    : numeroSerie(proximoNumeroSerie++)
{
}
