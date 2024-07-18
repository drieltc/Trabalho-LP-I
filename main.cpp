#include <iostream>

#include "headers/Cidade.h"
#include "headers/Controlador.h"
#include "headers/Passageiro.h"
#include "headers/Trajeto.h"
#include "headers/Transporte.h"
#include "headers/Viagem.h"

using namespace std;

int main() {
    Cidade origem("Cidade A");
    Cidade destino("Cidade B");
    Trajeto trajeto(origem, destino, "Rodoviário", 150.0);

    cout << "Origem: " << trajeto.getOrigem().getNome() << endl;
    cout << "Destino: " << trajeto.getDestino().getNome() << endl;
    cout << "Tipo: " << trajeto.getTipo() << endl;
    cout << "Distância: " << trajeto.getDistancia() << " km" << endl;

    return 0;
}
