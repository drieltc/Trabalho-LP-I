#ifndef CIDADE_H
#define CIDADE_H

#include <string>
using namespace std;

class Cidade {
private:
    string nome;
    int visitantes;
public:
    Cidade(string nome, int visitantes=0);
    string getNome();

    int getVisitantes();
    void addVisitantes(int n);
};

#endif