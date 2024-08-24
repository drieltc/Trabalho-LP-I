/**
 * @file main.cpp
 * @brief Programa principal para gerenciar cidades, passageiros, trajetos, transportes e viagens.
 * 
 * Este arquivo contém a implementação da função principal e das funções auxiliares que permitem ao usuário interagir com
 * o sistema para cadastrar novas cidades, passageiros, trajetos e transportes, iniciar viagens, avançar o tempo e gerar relatórios.
 */

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

/**
 * @brief Cadastra uma nova cidade no sistema.
 * 
 * Solicita ao usuário o nome de uma nova cidade e a adiciona ao sistema utilizando o objeto `Controlador`.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para realizar o cadastro da cidade.
 */
void cadastrarCidade(Controlador* control){
    cout << "Opção Selecionada: CADASTRAR CIDADE\n\n";
    
    string nomeCidade;
    cout << "Digite o nome da Cidade: ";
    cin >> nomeCidade;
    
    control->cadastrarCidade(nomeCidade);
}

/**
 * @brief Cadastra um novo passageiro no sistema.
 * 
 * Solicita ao usuário o nome de um passageiro e o nome da cidade em que o passageiro se encontra, e adiciona o passageiro ao sistema.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para realizar o cadastro do passageiro.
 */
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

/**
 * @brief Cadastra um novo trajeto no sistema.
 * 
 * Solicita ao usuário o nome das cidades de origem e destino, o tipo de trajeto e a distância entre elas, e adiciona o trajeto ao sistema.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para realizar o cadastro do trajeto.
 */
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

/**
 * @brief Cadastra um novo transporte no sistema.
 * 
 * Solicita ao usuário o nome do transporte, o tipo, a capacidade, a velocidade, a distância entre descansos, o tempo de descanso e a cidade atual,
 * e adiciona o transporte ao sistema.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para realizar o cadastro do transporte.
 */
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

/**
 * @brief Inicia uma nova viagem no sistema.
 * 
 * Solicita ao usuário o nome do transporte, os nomes dos passageiros, e as cidades de origem e destino, e inicia uma nova viagem no sistema.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para iniciar a viagem.
 */
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

/**
 * @brief Avança o tempo no sistema.
 * 
 * Avança o tempo em uma unidade no sistema, atualizando o status das viagens e transportes.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para avançar o tempo.
 */
void avancarHora(Controlador* control){
    cout << "Opção Selecionada: AVANÇAR HORA\n\n";

    control->avancarHoras();
}

/**
 * @brief Relata o estado dos passageiros no sistema.
 * 
 * Exibe uma lista de passageiros com seus respectivos locais, origens e destinos.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para relatar o estado dos passageiros.
 */
void relatarPassageiros(Controlador* control){
    cout << "Opção Selecionada: RELATAR PASSAGEIROS\n\n";

    cout << "Nome | Local | Origem | Destino \n";
    control->relatarPassageiros();
}

/**
 * @brief Relata o estado dos transportes no sistema.
 * 
 * Exibe uma lista de transportes com suas características, incluindo nome, tipo, capacidade, velocidade, local atual,
 * distância entre descansos e tempo de descanso.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para relatar o estado dos transportes.
 */
void relatarTransportes(Controlador* control){
    cout << "Opção Selecionada: RELATAR TRANSPORTES\n\n";

    cout << "Nome | Tipo | Capacidade | Velocidade (km/h) | Local Atual | Distância Entre Descansos (km) | Tempo de Descanso (h) | Tempo de Descanso Atual (h)\n";
    control->relatarTransportes();
}

/**
 * @brief Relata as cidades no sistema.
 * 
 * Exibe um relatório das cidades mais visitadas no sistema.
 * 
 * @param control Ponteiro para o objeto `Controlador` usado para relatar as cidades.
 */
void relatarCidades(Controlador* control){
    cout << "Opção Selecionada: RELATAR CIDADES\n\n";
    cout << "As cidades mais visitadas são:\n";

    control->relatarCidades();
}

/**
 * @brief Exibe o menu principal para o usuário.
 * 
 * Mostra as opções disponíveis para o usuário interagir com o sistema.
 */
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

/**
 * @brief Função principal do programa.
 * 
 * Inicializa o controlador e exibe o menu principal. Permite ao usuário selecionar ações para cadastrar cidades, passageiros, trajetos, transportes,
 * iniciar viagens, avançar o tempo e gerar relatórios. Encerra o programa quando o usuário escolhe a opção de sair.
 * 
 * @return 0 se a execução for bem-sucedida.
 */
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
