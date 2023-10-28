#ifndef N5_H_
#define N5_H_

using namespace std;

bool checkSwap(int Q, vector<int> d, vector<int> &rota_dem, int rota_i, int rota_j, int cliente1, int cliente2);

void swapRoutes(vector<int> &rota_dem, vector<int> d, vector<int> &v1, vector<int> &v2, int idx_cliente1, int idx_cliente2, int rota_i, int rota_j);

int CaculaCustoSwap(int total_cost, vector<vector<int>> c, vector<int> &rota1, vector<int> &rota2, int idx_cliente_i, int idx_cliente_j);

Solution SwapInter(Solution initial_solution, int Q, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif