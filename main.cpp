#include <iostream>
#include <vector>
#include <fstream>

#include "headers/Cidade.h"
#include "headers/Controlador.h"
#include "headers/Passageiro.h"
#include "headers/Trajeto.h"
#include "headers/Transporte.h"
#include "headers/Viagem.h"

#include "leituraEscrita/headers/leCidade.h"
#include "leituraEscrita/headers/lePassageiro.h"

using namespace std;

// void mostrarCidades(){
//     // Verificar se o ponteiro de cidades não é nulo
//     if (cidades != nullptr) {
//         for (auto& cidade : *cidades) {
//             cout << cidade.getNome() << endl;
//         }
//         delete cidades;
//     } else {
//         cerr << "Erro ao carregar as cidades." << endl;
//     }
// }

// void mostrarPassageiros(){
//     if (passageiros != nullptr){
//         for (auto& passageiro: *passageiros){
//             cout << "Nome: " << passageiro.getNome() << ", Local Atual: " << passageiro.getLocalAtual()->getNome() << endl;
//         }
//     } else {
//         cerr << "Erro ao carregar os passageiros." << endl;
//     }
// }

void cadastrarCidade(Controlador* control){
    string nomeCidade;
    cout << "Opção Selecionada: CADASTRAR CIDADE\n";
    cout << "Digite o nome da Cidade: ";
    cin >> nomeCidade;
    control->cadastrarCidade(nomeCidade);
    cout << "Cidade " << nomeCidade << " cadastrada com sucesso!\n";
}

void cadastrarPassageiro(Controlador* control){
    string nomePassageiro;
    string nomeCidade;
    cout << "Opção Selecionada: CADASTRAR PASSAGEIRO\n";
    cout << "Digite o nome do Passageiro: ";
    cin >> nomePassageiro;
    cout << "Digite o nome da Cidade em que " << nomePassageiro << " se encontra: ";
    cin >> nomeCidade;
    control->cadastrarPassageiro(nomePassageiro, nomeCidade);
    cout << "Passageiro " << nomePassageiro << " na cidade " << nomeCidade << " cadastrado com sucesso!";
}

void mostrarMenu(){
    cout << "O quê deseja fazer? \n";
    cout << "[1] - Cadastrar Nova Cidade\n";
    cout << "[2] - Cadastrar Novo Passageiro\n";
    cout << "[3] - Cadastrar Novo Trajeto\n";
    cout << "[4] - Cadastrar Novo Transporte\n";
    cout << "[5] - Iniciar Viagem\n";
    cout << "[6] - Relatar Pessoas\n";
    cout << "[7] - Relatar Transportes\n";
    cout << "[8] - Relatar Viagens\n";
    cout << "[9] - Ver cidades mais visitadas\n";
    cout << "[0] - Sair\n";
    cout << "Digite sua opção: ";  
}

int main() {
    Controlador* control = new Controlador();
    int opcao;
    bool running = true;

    while (running) {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cadastrarCidade(control);
                break;
            }
            case 2:
                cadastrarPassageiro(control);
                break;
            case 3:
                // Função para cadastrar novo traejto
                break;
            case 4:
                // Função para cadastrar novo transporte
                break;
            case 5:
                // Função para gerenciar viagens
                break;
            case 6:
                // Função para relatar pessoas
                break;
            case 7:
                // Função para relatar transportes
                break;
            case 8:
                // Função para relatar viagens
                break;
            case 9:
                // Função para ver cidades mais visitadas
                break;
            case 0:
                running = false;
                cout << "Encerrando\n";
                break;
            default:
                cout << "Opção Inválida\n";
                break;
        }
    }

    delete control;
    return 0;
}