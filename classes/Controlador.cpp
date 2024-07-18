#include "../headers/Controlador.h"

Controlador::Controlador(string nome){
    this->nome = nome;
}

string Controlador::getNome(){
    return this->nome;
}