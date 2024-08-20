// leViagem.h

#ifndef LEViagem_H
#define LEViagem_H

#include "../../headers/Viagem.h"
#include <vector>
#include <functional>
using namespace std;

void salvarViagem(Viagem *viagem);
vector<Viagem>* carregarViagens(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade);

#endif // LEViagem_H