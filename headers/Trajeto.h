#ifndef TRAJETO_H
#define TRAJETO_H

#include <string>
#include "Cidade.h"
using namespace std;

class Trajeto {
private:
    Cidade origem;
    Cidade destino;
    string tipo;
    float distancia;
public:
    Trajeto(Cidade origem, Cidade destino, string tipo, float distancia);
    
    Cidade getOrigem();
    Cidade getDestino();
    string getTipo();
    float getDistancia();

    void setOrigem(Cidade origem);
    void setDestino(Cidade destino);
    void setTipo(string tipo);
    void setDistancia(float distancia);
};

#endif
