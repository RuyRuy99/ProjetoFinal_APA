#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;

/*
  Modelo do arquivo:

    <Valor total da solução>
    <custo de roteamento>
    <custo associado a utilização dos veículos>
    <custo de terceirização>

    <Lista de clientes terceirizados>

    <Número de rotas>
    <Rota 1>
    <Rota 2>
    ...

*/

int cost_terc(vector<int> p, vector<int> &terceirizados, int *terc_size){

    int custo = 0;
    for(int i = 0; i < *terc_size; i++){
        custo += p[terceirizados[i]];
    }

    return custo;
}

int cost_rotas(){

    int custo = 0;


    return custo;
}

void file_exit(int r, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &route_size, int *totalCost, int *total_clientes, int *terc_size) {

    // Nome do arquivo de saida
    const char* exit = "saida.txt";

    // Objeto de fluxo de saída (ofstream)
    ofstream arquivoSaida(exit);

    // Verificando se o arquivo foi aberto com sucesso
    if (!arquivoSaida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saida." << endl;
        return;
    
    }else{

        arquivoSaida << " " << *totalCost << endl; // Valor total da solução

        arquivoSaida << " " << route_size.size() * r << endl; // custo associado a utilização dos veículos

        arquivoSaida << " " << route_size.size() << endl; // Número de rotas

        // Adicionar as rotas
        for(int i=0; i < route_size.size(); i++){
            arquivoSaida << " " << &routes[i] << endl; 
        }

    }

    // Fechar o arquivo
    arquivoSaida.close();
}