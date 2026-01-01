//
// Created by Xia on 12/10/2025.
//

#ifndef POO2526_TEMPO_H
#define POO2526_TEMPO_H


class Tempo {
    int instanteAtual;

public:
    Tempo();

    int getInstante() const;
    void setInstante(int valor);
    void reset();

    void avancaUm();
    void avancaN(int n);
};



#endif //POO2526_TEMPO_H