// leViagem.h

#ifndef LEViagem_H
#define LEViagem_H

#include "../../headers/Viagem.h"
#include <vector>
#include <functional>
using namespace std;

void salvarViagem(Viagem *viagem);
vector<Viagem>* carregarViagens(
    vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade,
    vector<Passageiro>* passageiros, function<Passageiro*(const string&)> pesquisarPassageiro,
    vector<Transporte>* transportes, function<Transporte*(const string&)> pesquisarTransporte,
    vector<Trajeto>* trajetos, function<Trajeto*(const string&, const string&, const char&)> pesquisarTrajeto
);

#endif // LEViagem_H