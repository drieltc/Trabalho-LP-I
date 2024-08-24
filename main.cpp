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

void iniciarViagem(Controlador* control){
    cout << "Opção Selecionada: INICIAR VIAGEM\n\n";

    string nomeTransporte;
    cout << "Digite o nome do Transporte: ";
    cin >> nomeTransporte;

    vector<string> nomesPassageiros;
    int numPassageiros;
    cout << "Digite a quantidade de passageiros: ";
    cin >> numPassageiros;

    nomesPassageiros.clear();
    for (int i = 0; i < numPassageiros; ++i) {
        string nomePassageiro;
        cout << "Nome do passageiro " << i + 1 << ": ";
        cin >> nomePassageiro;
        nomesPassageiros.push_back(nomePassageiro);
    }

    string nomeOrigem;
    cout << "Digite o nome da cidade de origem: ";
    cin >> nomeOrigem;

    string nomeDestino;
    cout << "Digite o nome da cidade de destino: ";
    cin >> nomeDestino;

    control->iniciarViagem(nomeTransporte, nomesPassageiros, nomeOrigem, nomeDestino);
}

void avancarHora(Controlador* control){
    cout << "Opção Selecionada: AVANÇAR HORA\n\n";

    control->avancarHoras();
}

void relatarPassageiros(Controlador* control){
    cout << "Opção Selecionada: RELATAR PASSAGEIROS\n\n";

    cout << "Nome | Local | Origem | Destino \n";
    control->relatarPassageiros();
}

void relatarTransportes(Controlador* control){
    cout << "Ooção Selecionada: RELATAR TRANSPORTES\n\n";

    cout << "Nome | Tipo | Capacidade | Velocidade (km/h) | Local Atual | Distância Entre Descansos (km) | Tempo de Descanso (h) | Tempo de Descanso Atual (h)\n";
    control->relatarTransportes();
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
    cout << "[6] - Avançar Horas\n";
    cout << "[7] - Relatar Estados\n";
    cout << "[0] - Salvar e Sair\n";
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
                iniciarViagem(control);
                break;
            case 6:
                avancarHora(control);
                break;
            case 7:
                control->relatarEstados();
                break;
            case 0:
                running = false;
                cout << "Encerrando\n";

                control->salvarSair();
                break;
            default:
                cout << "Opção Inválida\n";
                break;
        }
    }

    delete control;
    return 0;
}