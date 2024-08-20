#ifndef ROTA_H
#define ROTA_H

#include <vector>
#include "Trajeto.h"
#include "Cidade.h"

using namespace std;

class Rota {
public:
    static vector<Trajeto> calcularMelhorRota(vector<Trajeto>* trajetos, Cidade* origem, Cidade* destino, char tipoTransporte);
};

#endif
