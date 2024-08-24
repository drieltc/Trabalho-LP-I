#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Passageiro.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Viagem.h"
using namespace std;

class Controlador {
private:
    vector<Cidade>* cidades;
    vector<Passageiro>* passageiros;
    vector<Trajeto>* trajetos;
    vector<Transporte>* transportes;
    vector<Viagem>* viagens;
public:
    Controlador();
    ~Controlador();
    void cadastrarCidade(string nome);
    Cidade* pesquisarCidade(string nome);
    void relatarCidades();
    void cadastrarPassageiro(string nome, string nomeCidade);
    Passageiro* pesquisarPassageiro(string nome);
    void relatarPassageiros();
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia);
    Trajeto* pesquisarTrajeto(string nomeOrigem, string nomeDestino, char tipo);
    void cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade,  string nomeLocalAtual, int distanciaEntreDescansos, int tempoDescanso);
    Transporte* pesquisarTransporte(string nome);
    void relatarTransportes();
    void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    void avancarHoras();
    void salvarSair();
    void relatarEstados();
};

#endif // CONTROLADOR_H