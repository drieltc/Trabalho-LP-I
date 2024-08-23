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
    bool descansando;
    public:
    Transporte(string nome, char tipo, int capacidade, int velocidade,  Cidade* localAtual, int distanciaEntreDescanso, int tempoDescanso, int tempoDescansoAtual=0, bool descansando = false);
    string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();
    bool getDescansando();

    void aumentarTempoDescansoAtual(); //aumenta o tempo de descanso atual em 1
    void setLocalAtual(Cidade* novoLocal);
    void setDescansando(bool descansando);
};

#endif
