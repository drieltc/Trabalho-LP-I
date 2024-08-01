#include "../headers/Viagem.h"
#include <iostream>
using namespace std;

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino){
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    this->horasEmTransito = 0;
    this->emAndamento = false;
}

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, Viagem* proxima){
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    this->proxima = proxima;
    this->horasEmTransito = 0;
    this->emAndamento = false;
}

bool Viagem::isEmAndamento(){
    return this->emAndamento;
}

int Viagem::getHorasEmTransito(){
    return this->horasEmTransito;
}

void Viagem::iniciarViagem(){
    this->emAndamento = true;
}

void Viagem::finalizarViagem(){
    if (isEmAndamento()){
        this->emAndamento = false;
        this->horasEmTransito = 0;
    }
}

void Viagem::avancarHoras(){
    if (isEmAndamento()){
      this->horasEmTransito = this->horasEmTransito + 1;
    }
    else{
        cout << "Viagem não iniciada" << endl;
    }
}

void Viagem::relatarEstado(){
    cout << "FINALIZAR!!!!!";
}