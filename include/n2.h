#ifndef N2_H_
#define N2_H_

using namespace std;

struct SwapResult;

int findMaxCostVertex(vector<int> rota, vector<vector<int>> c);

bool checkSwap(int Q, vector<int> d, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j, int cliente1, int cliente2);

SwapResult custoSwapRoutes(int total_cost, int Q, vector<int> d, vector<int> p, vector<vector<int>> c, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j);

void swapRoutes(vector<int> &v1, vector<int> &v2, int n1, int n2, int i, int j, vector<int> &d_routs, vector<int> d);

Solution buscaExaustivaN2(Solution initial_solution, int Q, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif