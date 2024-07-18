#ifndef CCONTROLADOR_H
#define CONTROLADOR_H

#include <string>
using namespace std;

class Controlador {
private:
    string nome;
public:
    Controlador(string nome);
    string getNome();
};

#endif