#ifndef N4_H
#define N4_H

#include <iostream>
#include <vector>

using namespace std;

int calculaTerc(vector<int> &v, int i, vector<int> p, int L, int *clientes_att, vector<vector<int>> c, int *total_cost, vector<int> &terc, int *terc_size, int *rota_demanda);

void updateRoutes(vector<int> &v, int i, vector<int> d, int *clientes_att, vector<int> &terc, int *rota_demanda, int *terc_size);

void buscaExaustivaN4(int L, int *total_cost, int *terc_size, int *total_clientes, vector<int> d, vector<int> p, vector<vector<int>> c, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &rota_demanda, vector<int> &routes_size);


#endif