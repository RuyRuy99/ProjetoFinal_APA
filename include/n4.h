#ifndef N4_H
#define N4_H

#include <iostream>
#include <vector>

using namespace std;

int calculaTerc(Solution solucao, vector<int> &v, int i, int clientes_atendidos, int L, vector<int> p, vector<vector<int>> c);

void updateRoutes(vector<int> &v, int i, int *clientes_atendidos, int *rota_demanda,vector<int> &terc, vector<int> d);

Solution Remove(Solution initial_solution, int r, int L, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif