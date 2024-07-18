#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string>
using namespace std;

class Transporte {
private:
    string nome;
public:
    Transporte(string nome);
    string getNome();
};

#endif
