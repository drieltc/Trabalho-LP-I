#include <iostream>
#include <vector>
#include <fstream>

#include "headers/Cidade.h"
#include "headers/Controlador.h"
#include "headers/Passageiro.h"
#include "headers/Trajeto.h"
#include "headers/Transporte.h"
#include "headers/Viagem.h"

#include "leituraEscrita/leCidade.cpp"
#include "leituraEscrita/lePassageiro.cpp"
#include "leituraEscrita/leTrajeto.cpp"
#include "leituraEscrita/leTransporte.cpp"
#include "leituraEscrita/leViagem.cpp"

using namespace std;

vector<Cidade>* cidades = carregarCidades();
vector<Passageiro>* passageiros = carregarPassageiros(cidades);
vector<Trajeto>* trajetos = carregarTrajetos();
vector<Transporte>* transportes = carregarTransportes();
vector<Viagem>* viagens = carregarViagens();

void cadastrarCidade(string nome){
    //adicionar nova cidade
    Cidade* novaCidade = new Cidade(nome);
    salvarCidade(novaCidade);
    cidades = carregarCidades();
}

void mostrarCidades(){
    // Verificar se o ponteiro de cidades não é nulo
    if (cidades != nullptr) {
        for (auto& cidade : *cidades) {
            cout << cidade.getNome() << endl;
        }
        delete cidades;
    } else {
        cerr << "Erro ao carregar as cidades." << endl;
    }
}

void cadastrarPassageiro(string nome, string nomeCidade){
    Cidade* localAtual = new Cidade(nomeCidade);
    Passageiro* novoPassageiro = new Passageiro("João", localAtual);
    salvarPassageiro(novoPassageiro);
    passageiros = carregarPassageiros(cidades);
}

void mostrarPassageiros(){
    if (passageiros != nullptr){
        for (auto& passageiro: *passageiros){
            cout << "Nome: " << passageiro.getNome() << ", Local Atual: " << passageiro.getLocalAtual()->getNome() << endl;
        }
    } else {
        cerr << "Erro ao carregar os passageiros." << endl;
    }
}

void deletarInfos(){
    for (auto& cidade : *cidades){
        delete &cidade;
    }

    for (auto& passageiro : *passageiros){
        delete &passageiro;
    }

    delete cidades;
    delete passageiros;
}

int main() {
    deletarInfos();
    return 0;
}