#include "../headers/Transporte.h"

Transporte::Transporte(string nome) {
    this->nome = nome;
}

string Transporte::getNome() {
    return this->nome;
}