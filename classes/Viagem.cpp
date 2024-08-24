#include "../headers/Viagem.h"
#include <iostream>
using namespace std;

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima){
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->trajeto = trajeto;
    this->horasEmTransito = horasEmTransito;
    this->distanciaPercorrida = distanciaPercorrida;
    this->emAndamento = emAndamento;
    this->hasProxima = hasProxima;
}

Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima, Viagem* proxima){
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->trajeto = trajeto;
    this->horasEmTransito = horasEmTransito;
    this->distanciaPercorrida = distanciaPercorrida;
    this->emAndamento = emAndamento;
    this->hasProxima = hasProxima;
    this->proxima = proxima;
}

bool Viagem::isEmAndamento(){
    return this->emAndamento;
}

bool Viagem::getHasProxima(){
    return this->hasProxima;
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

Trajeto* Viagem::getTrajeto(){
    return this->trajeto;
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

void Viagem::finalizarViagem(Cidade* emTransito){
    if (isEmAndamento()){
        this->emAndamento = false;
        this->horasEmTransito = 0;
    }

    for (auto& passageiro : passageiros){
        passageiro->setLocalAtual(trajeto->getDestino());
    }

    transporte->setLocalAtual(trajeto->getDestino());
    
    if(this->getHasProxima()){
        this->getProxima()->iniciarViagem(emTransito);
    }

    this->getTrajeto()->getDestino()->addVisitantes(this->getPassageiros().size());

    cout << "Viagem de " << this->trajeto->getOrigem()->getNome() << " para " << this->trajeto->getDestino()->getNome() << " finalizada." << endl; 
}

void Viagem::avancarHoras(Cidade* emTransito) {
    if (isEmAndamento()) {
        this->horasEmTransito++;

        if (this->transporte->getDescansando()) {
            this->transporte->aumentarTempoDescansoAtual();

            if (this->transporte->getTempoDescansoAtual() >= this->transporte->getTempoDescanso()) {
                this->transporte->zerarDescanso();
            }
        } else {
            this->distanciaPercorrida += this->transporte->getVelocidade();

            // Verifica se a viagem terminou
            if (this->distanciaPercorrida >= this->trajeto->getDistancia()) {
                this->distanciaPercorrida = this->trajeto->getDistancia();
                this->finalizarViagem(emTransito);
                return;  // Retorna para evitar verificações adicionais após o término da viagem
            }

            // Verifica se o transporte precisa descansar
            if (this->distanciaPercorrida >= this->transporte->getDistanciaEntreDescansos()) {
                this->transporte->setDescansando(true);
            }
        }
    }
}


void Viagem::relatarEstado(){
    cout << "FINALIZAR!!!!!";
}

void Viagem::setDistanciaPercorrida(int distancia){
    this->distanciaPercorrida = distancia;
}