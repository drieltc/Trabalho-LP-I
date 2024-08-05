#include "../headers/Controlador.h"

void Controlador::cadastrarCidade(string nome){
    Cidade* origem = new Cidade(nome);
}

void Controlador::cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia){
    //criar uma funcao que acesse o vetor de cidades cadastradas, use o metodo getNome() e se getNome() == nome, retornar a cidade (origem)
    //fazer o mesmo para destino
    //criar o trajeto
}

void cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescanso, int tempoDescanso, string localAtual){
    //criar uma funcao que acesse o vetor de cidades cadastradas, use o metodo getNome() e se getNome() == nome, retornar a cidade (localAtual)
    //criar o transpote
}

void cadastrarPassageiro(string nome, string localAtual){
    //criar uma funcao que acesse o vetor de cidades cadastradas, use o metodo getNome() e se getNome() == nome, retornar a cidade (localAtual)
    //criar o passageiro
}

void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino){
    //criar uma funcao que acesse o vetor de transportes, use o getNome() e retorne o nome do transporte
    //fazer o mesmo para nomeOrigem e nomeDestino
}

void avancarHoras(){
    //transporte e viagem
}

void relatarEstado(){
    //não sei o que fzer
}