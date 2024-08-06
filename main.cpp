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

using namespace std;

vector<Cidade>* cidades = carregarCidades();

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

void salvarPassageiro(Passageiro *passageiro){
    ofstream arquivoPassageiros("memory/passageiros.txt", ios::app);
    if (arquivoPassageiros.is_open()){
        arquivoPassageiros << passageiro->getNome() << "," << passageiro->getLocalAtual()->getNome() << endl;
        arquivoPassageiros.close();
    } else {
        cerr << "Não foi possível abrir o arquivo passageiros.txt para escrita." << endl;
    }
}

vector<Passageiro>* carregarPassageiros(){
    vector<Passageiro>* passageiros = new vector<Passageiro>;
    ifstream arquivoPassageiros("memory/passageiros.txt");

    if (arquivoPassageiros.is_open()){
        string linha;
        while (getline(arquivoPassageiros, linha)){
            size_t pos = linha.find(",");
            if (pos != string::npos){
                string nome = linha.substr(0, pos);
                string nomeCidade = linha.substr(pos+1);

                Cidade* cidadeEncontrada = new Cidade("");
                for (auto& cidade: *cidades){
                    if (cidade.getNome() == nomeCidade){
                        cidadeEncontrada = &cidade;
                        break;
                    }
                }
                if (!cidadeEncontrada->getNome().empty()){
                    passageiros->emplace_back(nome, cidadeEncontrada);
                } else {
                    cerr << "Cidade não encontrada: " << nomeCidade << endl;
                }
            }
        }
        arquivoPassageiros.close();
    } else {
        cerr << "Não foi possível abrir o arquivo passageiros.txt para leitura." << endl;
    }
    return passageiros;
}

vector<Passageiro>* passageiros = carregarPassageiros();

int main() {
    Cidade* localAtual = new Cidade("Cidade Exemplo");
    Passageiro* novoPassageiro = new Passageiro("João", localAtual);
    salvarPassageiro(novoPassageiro);

    if (passageiros != nullptr){
        for (auto& passageiro: *passageiros){
            cout << "Nome: " << passageiro.getNome() << ", Local Atual" << passageiro.getLocalAtual()->getNome();
        }
    } else {
        cerr << "Erro ao carregar os passageiros." << endl;
    }

    delete cidades;
    delete passageiros;
    return 0;
}