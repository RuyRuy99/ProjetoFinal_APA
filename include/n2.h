#ifndef N3_H_
#define N3_H_
#include <vector>

using namespace std;

struct SwapResult;

int findMaxCostVertex(vector<int> &rota, vector<vector<int>> c);

SwapResult custoSwap_Routes(int *total_cost, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j);

void Swap_Routes(int *total_cost, int Q, vector<int> d, vector<vector<int>> c, vector<int> p, vector<int> &v1, vector<int> &v2, vector<int> &d_routs);

void swapRoutes(vector<int> &v1, vector<int> &v2, int n1, int n2, vector<int> &d_routs, vector<int> d, int i, int j);

int buscaExaustivaN2(vector<vector<int>> &routes, int *total_cost, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &d_routs);

#endif