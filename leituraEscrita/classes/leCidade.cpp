// leCidade.cpp

#include "leCidade.h"
#include <fstream>
#include <iostream>

using namespace std;

void salvarCidade(Cidade *cidade){
    ofstream arquivoCidades("memory/cidades.txt", ios::app);
    if (arquivoCidades.is_open()){
        arquivoCidades << cidade->getNome() << endl;
        arquivoCidades.close();
    } else {
        cerr << "Não foi possível abrir o arquivo cidades.txt para escrita." << endl;
    }
}

vector<Cidade>* carregarCidades() {
    vector<Cidade>* cidades = new vector<Cidade>;
    ifstream arquivoCidades("memory/cidades.txt");

    if (arquivoCidades.is_open()){
        string nome;
        while (getline(arquivoCidades, nome)){
            cidades->emplace_back(nome);
        }
        arquivoCidades.close();
    } else {
        cerr << "Não foi possível abrir o arquivo cidades.txt para leitura." << endl;
    }

    return cidades;
}
