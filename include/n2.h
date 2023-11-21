#ifndef N2_H_
#define N2_H_

using namespace std;

bool checkSwap(int Q, const vector<int> &d, vector<int> &rota_dem, int rota_i, int rota_j, int cliente1, int cliente2);

int CaculaCustoSwap(int total_cost, const vector<vector<int>> &c, const vector<int> &rota1, const vector<int> &rota2, int idx_cliente_i, int idx_cliente_j);

void swapRoutes(vector<int> &rota_dem, vector<int> &d, vector<int> &v1, vector<int> &v2, int idx_cliente1, int idx_cliente2, int rota_i, int rota_j);

Solution* SwapInter(Solution* current_solution, InstanceData* dados);

#endif