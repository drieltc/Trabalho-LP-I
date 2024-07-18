#include <iostream>
#include "headers/Cidade.h"
#include "headers/Controlador.h"
#include "headers/Passageiro.h"
#include "headers/Trajeto.h"
#include "headers/Transporte.h"
#include "headers/Viagem.h"
using namespace std;

int main() {
    Cidade cidade("Bals");
    cout << cidade.getNome() << endl;
    return 0;
}
