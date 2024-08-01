#ifndef CCONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
using namespace std;

class Controlador {
private:
    vector<Cidade*> cidades;
    vector<Trajeto*> trajetos;
    vector<Transporte*> transportes;
    vector<Passageiro*> passageiros;
    vector<Viagem*> viagens;
public:
    void cadastrarCidade(string nome);
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescanso, int tempoDescanso, string localAtual);
    void cadastrarPassageiro(string nome, string localAtual);
    void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    void avancarHoras();
    void relatarEstado();
};

#endif