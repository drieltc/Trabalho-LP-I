#include "../headers/Trajeto.h"

// Construtor
Trajeto::Trajeto(Cidade origem, Cidade destino, string tipo, float distancia)
    : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {
        //this->origem = origem;
        //this->destino = destino;
        //this->tipo = tipo;
        //this->distancia = distancia;
}

// Getters
Cidade Trajeto::getOrigem() {
    return this->origem;
}
Cidade Trajeto::getDestino() {
    return this->destino;
}
string Trajeto::getTipo() {
    return this->tipo;
}
float Trajeto::getDistancia() {
    return this->distancia;
}

// Setters
void Trajeto::setOrigem(Cidade origem) {
    this->origem = origem;
}
void Trajeto::setDestino(Cidade destino) {
    this->destino = destino;
}
void Trajeto::setTipo(string tipo) {
    this->tipo = tipo;
}
void Trajeto::setDistancia(float distancia) {
    this->distancia = distancia;
}
