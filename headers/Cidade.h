#ifndef CIDADE_H
#define CIDADE_H

#include <string>
using namespace std;

class Cidade {
private:
    string nome;
    string codigo;  // Este membro não foi usado, mas vamos mantê-lo conforme o original
public:
    Cidade(string nome);
    string getNome();
    void setNome(string nome);
};

#endif
