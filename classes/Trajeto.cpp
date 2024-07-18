#include "../headers/Trajeto.h"

Trajeto::Trajeto(string nome) {
    this->nome = nome;
}

string Trajeto::getNome() {
    return this->nome;
}