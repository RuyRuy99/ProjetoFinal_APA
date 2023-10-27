#ifndef DATATYPE_H
#define DATATYPE_H

#include <iostream>
#include <vector>

using namespace std;

// Definição da struct
struct Solution{

    vector<vector<int>> routes; // Array com todas as rotas
    vector<int> terceirizados;
    vector<int> rota_dem; // Array com as demandas total de cada rota
    //vector<int> route_size; // Um vetor que armazena o tamanho de cada rota
    int totalCost; // Custo total da solução
    int total_clientes; 
    
};

#endif