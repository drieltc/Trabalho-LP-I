#ifndef VIAGEM_H
#define VIAGEM_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Passageiro.h"
#include "Transporte.h"
using namespace std;

class Viagem {
private:
    Transporte* transporte;
    vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    Viagem* proxima;
    int horasEmTransito;
    int distanciaPercorrida;
    bool emAndamento;
public:
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);

    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, Viagem* proxima);

    bool isEmAndamento();
    int getHorasEmTransito();

    Transporte* getTransporte();
    vector<Passageiro*> getPassageiros();
    Cidade* getOrigem();
    Cidade* getDestino();
    Viagem* getProxima();

    void iniciarViagem(Cidade* emTransito);
    void finalizarViagem();
    void avancarHoras();
    void relatarEstado();

};

#endif
