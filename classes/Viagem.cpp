#include "../headers/Viagem.h"
#include <iostream>
using namespace std;

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, int horasEmTransito, int distanciaPercorrida, bool emAndamento){
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    this->horasEmTransito = horasEmTransito;
    this->distanciaPercorrida = distanciaPercorrida;
    this->emAndamento = emAndamento;
}

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, int horasEmTransito, int distanciaPercorrida, bool emAndamento, Viagem* proxima){
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    this->horasEmTransito = horasEmTransito;
    this->distanciaPercorrida = distanciaPercorrida;
    this->emAndamento = emAndamento;
    this->proxima = proxima;
}

bool Viagem::isEmAndamento(){
    return this->emAndamento;
}

int Viagem::getHorasEmTransito(){
    return this->horasEmTransito;
}

int Viagem::getDistanciaPercorrida(){
    return this->distanciaPercorrida;
}

Transporte* Viagem::getTransporte(){
    return this->transporte;
}

vector<Passageiro*> Viagem::getPassageiros(){
    return this->passageiros;
}

Cidade* Viagem::getOrigem(){
    return this->origem;
}

Cidade* Viagem::getDestino(){
    return this->destino;
}

Viagem* Viagem::getProxima(){
    return this->proxima;
}

void Viagem::iniciarViagem(Cidade* emTransito){
    this->emAndamento = true;
    
    for (auto& passageiro : passageiros){
        passageiro->setLocalAtual(emTransito);
    }

    transporte->setLocalAtual(emTransito);
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