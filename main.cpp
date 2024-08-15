#include <iostream>
#include <vector>
#include <fstream>

#include "headers/Cidade.h"
#include "headers/Controlador.h"
#include "headers/Passageiro.h"
#include "headers/Trajeto.h"
#include "headers/Transporte.h"
#include "headers/Viagem.h"

using namespace std;

void cadastrarCidade(Controlador* control){
    cout << "Opção Selecionada: CADASTRAR CIDADE\n\n";
    
    string nomeCidade;
    cout << "Digite o nome da Cidade: ";
    cin >> nomeCidade;
    
    control->cadastrarCidade(nomeCidade);
}

void cadastrarPassageiro(Controlador* control){
    cout << "Opção Selecionada: CADASTRAR PASSAGEIRO\n\n";
    
    string nomePassageiro;
    cout << "Digite o nome do Passageiro: ";
    cin >> nomePassageiro;
     
    string nomeCidade;
    cout << "Digite o nome da Cidade em que " << nomePassageiro << " se encontra: ";
    cin >> nomeCidade;
    
    control->cadastrarPassageiro(nomePassageiro, nomeCidade);
}

void cadastrarTrajeto(Controlador* control){
    cout << "Opção Selecionada: CADASTRAR TRAJETO\n\n";

    string cidadeOrigem;
    cout << "Digite o nome da cidade de origem do Trajeto: ";
    cin >> cidadeOrigem;

    string cidadeDestino;
    cout << "Digite o nome da cidade de destino do Trajeto: ";
    cin >> cidadeDestino;

    char tipo;
    cout << "Digite o tipo de Trajeto [A/T]: ";
    cin >> tipo;
    tipo = toupper(tipo);

    int distancia;
    cout << "Digite a distância entre " << cidadeOrigem << " e " << cidadeDestino << " (km): ";
    cin >> distancia;

    control->cadastrarTrajeto(cidadeOrigem, cidadeDestino, tipo, distancia);
}

void cadastrarTransporte(Controlador* control){
    cout << "Opção Selecionada: CADASTRAR TRANSPORTE\n\n";

    string nome;
    cout << "Digite o nome do Transporte: ";
    cin >> nome;

    char tipo;
    cout << "Digite o tipo do Transporte [A/T]: ";
    cin >> tipo;
    tipo = toupper(tipo);

    int capacidade;
    cout << "Digite a capacidade do Transporte: ";
    cin >> capacidade;

    int velocidade;
    cout << "Digite a velocidade do Transporte (km/h): ";
    cin >> velocidade;

    int distanciaEntreDescansos;
    cout << "Digite a distância entre descansos do Transporte (km): ";
    cin >> distanciaEntreDescansos;

    int tempoDescanso;
    if (distanciaEntreDescansos > 0){
        cout << "Digite o tempo de descanso necessário (h): ";
        cin >> tempoDescanso;
    } else {
        tempoDescanso=0;
    }

    string nomeLocalAtual;
    cout << "Digite o nome da Cidade em que o Transporte se encontra: ";
    cin >> nomeLocalAtual;

    control->cadastrarTransporte(nome, tipo, capacidade, velocidade, nomeLocalAtual, distanciaEntreDescansos, tempoDescanso);
}

void relatarPassageiros(Controlador* control){
    cout << "Opção Selecionada: RELATAR PASSAGEIROS\n\n";

    cout << "Nome | Local | Origem | Destino \n";
    control->relatarPassageiros();
}

void relatarCidades(Controlador* control){
    cout << "Opção Selecionada: RELATAR VIAGENS\n\n";
    cout << "As cidades mais visitadas são:\n";

    control->relatarCidades();
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
                cadastrarTrajeto(control);
                break;
            case 4:
                cadastrarTransporte(control);
                break;
            case 5:
                // Função para gerenciar viagens
                break;
            case 6:
                relatarPassageiros(control);
                break;
            case 7:
                // Função para relatar transportes
                break;
            case 8:
                // Função para relatar viagens
                break;
            case 9:
                relatarCidades(control);
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