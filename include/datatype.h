#ifndef DATATYPE_H
#define DATATYPE_H

#include <iostream>
#include <vector>

using namespace std;

// Definição da struct
struct Solution{
    vector<vector<int>> routes;
    vector<int> terceirizados;
    vector<int> rota_dem;
    int totalCost;
    int total_clientes;
    int terc_size;
};



#endif