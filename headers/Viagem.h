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
    bool emAndamento;
public:
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);

    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, Viagem* proxima);

    bool isEmAndamento();
    int getHorasEmTransito();

    void iniciarViagem();
    void finalizarViagem();
    void avancarHoras();
    void relatarEstado();

};

#endif
