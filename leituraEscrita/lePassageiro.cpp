#include "../headers/Passageiro.h"
#include "../headers/Cidade.h"
#include <fstream>
#include <iostream>
#include <vector>

void salvarPassageiro(Passageiro *passageiro){
    ofstream arquivoPassageiros("memory/passageiros.txt", ios::app);
    if (arquivoPassageiros.is_open()){
        arquivoPassageiros << passageiro->getNome() << "," << passageiro->getLocalAtual()->getNome() << endl;
        arquivoPassageiros.close();
    } else {
        cerr << "Não foi possível abrir o arquivo passageiros.txt para escrita." << endl;
    }
}

vector<Passageiro>* carregarPassageiros(vector<Cidade>* cidades){
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