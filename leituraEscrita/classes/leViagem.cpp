#include "../headers/leViagem.h"
#include <fstream>
#include <iostream>

void salvarViagem(Viagem *viagem){
    ofstream arquivoViagem("memory/viagens.txt", ios::app);
    if (arquivoViagem.is_open()){
        arquivoViagem << viagem->getTransporte()->getNome() << ","
        
        << viagem->getPassageiros().size() << ",";

        for (auto& passageiro: viagem->getPassageiros()){
            arquivoViagem << passageiro->getNome() << ",";
        }

        arquivoViagem << viagem->getOrigem()->getNome() << ","
        << viagem->getDestino()->getNome() << ","
        << viagem->getProxima()
        << endl;
        arquivoViagem.close();
    } else {
        cerr << "Não foi possível abrir o arquivo viagens.txt para escrita.\n";
    }
}