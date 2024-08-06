#ifndef CIDADE_H
#define CIDADE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Cidade {
private:
    string nome;
public:
    Cidade(string nome);
    string getNome();
    
    void salvar(ofstream& fileName);
    void carregar(ifstream& fileName);
};

#endif