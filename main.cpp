#include <iostream>
#include <vector>

#include "headers/Cidade.h"
#include "headers/Controlador.h"
#include "headers/Passageiro.h"
#include "headers/Trajeto.h"
#include "headers/Transporte.h"
#include "headers/Viagem.h"

using namespace std;

int main() {
    Cidade* origem = new Cidade("Cidade A");
    Cidade* destino = new Cidade("Cidade B");
    // Trajeto* trajeto = new Trajeto(origem, destino, 'R', 150);
    
    cout << origem->getNome() << endl;

    cout << destino->getNome() << endl;
    
    // cout << "Origem: " << trajeto->getOrigem()->getNome() << endl;
    // cout << "Destino: " << trajeto->getDestino()->getNome() << endl;
    // cout << "Tipo: " << trajeto->getTipo() << endl;
    // cout << "Distância: " << trajeto->getDistancia() << " km" << endl;

    // Transporte* transporte = new Transporte("Cavalo", 'A', 4, 6, 12, 1, origem);
    
    // cout << transporte->getNome() << endl;
    // cout << transporte->getTipo() << endl;
    // cout << transporte->getCapacidade() << " pessoas \n";
    // cout << transporte->getVelocidade() << "km/h\n";
    // cout << transporte->getDistanciaEntreDescanso() << "km\n";
    // cout << transporte->getTempoDescanso() << "horas\n";
    // cout << transporte->getTempoDescansoAtual() << "horas\n";
    // cout << transporte->getLocalAtual()->getNome() << endl;
    
    // transporte->aumentarTempoDescansoAtual();
    // cout << transporte->getTempoDescansoAtual() << "horas\n";

    // transporte->setLocalAtual(destino);
    // cout << transporte->getLocalAtual()->getNome() << endl;

    // Passageiro* passageiro = new Passageiro("Adriel", origem);
    // Passageiro* passageiro2 = new Passageiro("Caio", origem);

    // cout << passageiro->getNome() << endl;
    // cout << passageiro->getLocalAtual()->getNome() << endl;

    // passageiro->setLocalAtual(destino);
    // cout << passageiro->getLocalAtual()->getNome() << endl;

    // vector<Passageiro*> passageiros;
    // passageiros.push_back(passageiro);
    // passageiros.push_back(passageiro2);

    // Viagem* viagem = new Viagem(transporte, passageiros, origem, destino);

    // cout << viagem->isEmAndamento() << endl;
    // cout << viagem->getHorasEmTransito() << endl;

    // viagem->avancarHoras();

    // viagem->iniciarViagem();
    // viagem->avancarHoras();

    // cout << viagem->isEmAndamento() << endl;
    // cout << viagem->getHorasEmTransito() << endl;
    
    // viagem->finalizarViagem();
    // viagem->avancarHoras();

    // cout << viagem->isEmAndamento() << endl;
    // cout << viagem->getHorasEmTransito() << endl;
    
    return 0;
}
