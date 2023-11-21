#ifndef DATATYPE_H
#define DATATYPE_H

#include <iostream>
#include <vector>

using namespace std;


//Struct para armazenar os dados do problema
struct InstanceData{
    int n; // Número de clientes
    int k; // Número de veículos
    int Q; // Capacidade máxima de cada veículo
    int L; // Quantidade minima de entregas sem terceirização
    int r; //Custo de utilizar o veículo

    vector<int> d; // Demanda de cada cliente
    vector<int> p; // Custo de terceirizar cada cliente
    vector<vector<int>> c; // Matriz de custos
};

// Definição da struct
struct Solution{

    vector<vector<int>> routes; // Array com todas as rotas
    vector<int> terceirizados; // Array com os clientes terceirizados
    vector<int> rota_dem; // Array com as demandas total de cada rota
    int totalCost; // Custo total da solução
    int total_clientes; // Número total de clientes atendidos 
};

#endif