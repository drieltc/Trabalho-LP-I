#ifndef CCONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Passageiro.h"
#include "Trajeto.h"
// #include "Transporte.h"
// #include "Viagem.h"
using namespace std;

class Controlador {
private:
    vector<Cidade>* cidades;
    vector<Passageiro>* passageiros;
    vector<Trajeto>* trajetos;
    // vector<Transporte>* transportes;
    // vector<Viagem>* viagens;
public:
    Controlador();
    ~Controlador();
    void cadastrarCidade(string nome);
    Cidade* pesquisarCidade(string nome);
    void cadastrarPassageiro(string nome, string nomeCidade);
    void relatarPassageiros();
    void relatarCidades();
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia);
    // void cadastrarTransportes(string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescanso, int tempoDescanso, string localAtual);
    // void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    // void avancarHoras();
};

#endif // CCONTROLADOR_H