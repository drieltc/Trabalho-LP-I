#ifndef VIAGEM_H
#define VIAGEM_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Passageiro.h"
#include "Transporte.h"
#include "Trajeto.h"
using namespace std;

class Viagem {
private:
    Transporte* transporte;
    vector<Passageiro*> passageiros;
    Cidade* origem;
    Trajeto* trajeto;
    Viagem* proxima;
    int horasEmTransito;
    int distanciaPercorrida;
    bool emAndamento;
    bool hasProxima;
public:
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima);

    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima, Viagem* proxima);

    bool isEmAndamento();
    bool getHasProxima();
    int getHorasEmTransito();
    int getDistanciaPercorrida();

    Transporte* getTransporte();
    vector<Passageiro*> getPassageiros();
    Trajeto* getTrajeto();
    Viagem* getProxima();

    void setDistanciaPercorrida(int distancia);
    void iniciarViagem(Cidade* emTransito);
    void finalizarViagem(Cidade* emTransito);
    void avancarHoras(Cidade* emTransito);
    void relatarEstado();

};

#endif
