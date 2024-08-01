#include "../headers/Cidade.h"

Cidade::Cidade(string nome) {
    this->nome = nome;
}

string Cidade::getNome() {
    return this->nome;
}