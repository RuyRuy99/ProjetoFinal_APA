#ifndef N3_H_
#define N3_H_
#include <vector>

using namespace std;

// Estrutura de vizinha para swap de clientes entre rotas
void Swap_Routes(int *total_cost, int cap_atual, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v1, vector<int> &v2);

#endif