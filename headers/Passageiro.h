#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
using namespace std;

class Passsageiro {
private:
    string nome;
public:
    Passsageiro(string nome);
    string getNome();
};

#endif
