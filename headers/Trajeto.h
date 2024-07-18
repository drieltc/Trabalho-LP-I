#ifndef TRAJETO_H
#define TRAJETO_H

#include <string>
using namespace std;

class Trajeto {
private:
    string nome;
public:
    Trajeto(string nome);
    string getNome();
};

#endif
