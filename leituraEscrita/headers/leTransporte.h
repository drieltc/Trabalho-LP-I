// LETRANSPORTE.h

#ifndef LETRANSPORTE_H
#define LETRANSPORTE_H

#include "../../headers/Transporte.h"
#include <vector>
#include <functional>
using namespace std;

void salvarTransporte(Transporte *Transporte);
vector<Transporte>* carregarTransportes(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade);

#endif // LETRANSPORTE_H