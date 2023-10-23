#ifndef N5_H_
#define N5_H_

using namespace std;

struct SwapResult;

bool checkSwap2(int Q, vector<int> d, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j, int cliente1, int cliente2);

SwapResult custoSwapRoutes2(int total_cost, int Q, vector<int> d, vector<int> p, vector<vector<int>> c, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j);

void swapRoutes2(vector<int> &v1, vector<int> &v2, int n1, int n2, int i, int j, vector<int> &d_routs, vector<int> d);

Solution buscaExaustivaN5(Solution initial_solution, int Q, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif