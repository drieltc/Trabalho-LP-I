#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string>
#include "Cidade.h"
using namespace std;

class Transporte {
private:
    string nome;
    char tipo; //'A' para aquatico, 'T' para terrestre 
    int capacidade; //numero de passageiros
    int velocidade; //em km/h
    int distanciaEntreDescanso; //em km
    int tempoDescanso; //em horas
    int tempoDescansoAtual; //em horas
    Cidade* localAtual;
    public:
    Transporte(string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescanso, int tempoDescanso, Cidade* localAtual);
    string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescanso();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();

    void aumentarTempoDescansoAtual(); //aumenta o tempo de descanso atual em 1
    void setLocalAtual(Cidade* novoLocal);
};

#endif
