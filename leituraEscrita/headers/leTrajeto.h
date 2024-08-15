// LETRAJETO.h

#ifndef LETRAJETO_H
#define LETRAJETO_H

#include "../../headers/Trajeto.h"
#include <vector>
#include <functional>
using namespace std;

void salvarTrajeto(Trajeto *Trajeto);
vector<Trajeto>* carregarTrajetos(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade);

#endif // LETRAJETO_H