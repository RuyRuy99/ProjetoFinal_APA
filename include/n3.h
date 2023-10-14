#ifndef N2_H_
#define N2_H_
#include <vector>

using namespace std;

// Estutura de vizinhança para swap de clientes entre rota e terceirização
void Upgrade_Routes(int *total_cost, int cap_atual, int Q, vector<int> lst_clientes,vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v, int i);

#endif