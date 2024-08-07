// lePassageiro.h

#ifndef LEPASSAGEIRO_H
#define LEPASSAGEIRO_H

#include "../../headers/Passageiro.h"
#include <vector>
#include <functional>
using namespace std;

void salvarPassageiro(Passageiro *Passageiro);
vector<Passageiro>* carregarPassageiros(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade);

#endif //LEPASSAGEIRO_H