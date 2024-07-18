#include "../headers/Viagem.h"

Viagem::Viagem(string nome) {
    this->nome = nome;
}

string Viagem::getNome() {
    return this->nome;
}