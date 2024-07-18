#ifndef VIAGEM_H
#define VIAGEM_H

#include <string>
using namespace std;

class Viagem {
private:
    string nome;
public:
    Viagem(string nome);
    string getNome();
};

#endif
