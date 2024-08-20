#ifndef TRAJETO_H
#define TRAJETO_H

#include <string>
#include "Cidade.h"
using namespace std;

class Trajeto {
private:
    Cidade* origem;
    Cidade* destino;
    char tipo; //'A' para aquático, 'T' para terrestre
    int distancia;
public:
    Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia);
    
    Cidade* getOrigem() const;
    Cidade* getDestino() const;
    char getTipo() const;
    int getDistancia() const;

    void setOrigem(Cidade* origem);
    void setDestino(Cidade* destino);
    void setTipo(char tipo);
    void setDistancia(int distancia);
};

#endif
