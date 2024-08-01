#include "../headers/Trajeto.h"

// Construtor
Trajeto::Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia){
    this->origem = origem;
    this->destino = destino;
    this->tipo = tipo;
    this->distancia = distancia;
}

// Getters
Cidade* Trajeto::getOrigem() {
    return this->origem;
}
Cidade* Trajeto::getDestino() {
    return this->destino;
}
char Trajeto::getTipo() {
    return this->tipo;
}
int Trajeto::getDistancia() {
    return this->distancia;
}

// Setters
void Trajeto::setOrigem(Cidade* origem) {
    this->origem = origem;
}
void Trajeto::setDestino(Cidade* destino) {
    this->destino = destino;
}
void Trajeto::setTipo(char tipo) {
    this->tipo = tipo;
}
void Trajeto::setDistancia(int distancia) {
    this->distancia = distancia;
}
