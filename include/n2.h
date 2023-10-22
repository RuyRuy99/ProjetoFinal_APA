#ifndef N2_H_
#define N2_H_

using namespace std;

struct SwapResult;

int findMaxCostVertex(vector<int> rota, vector<vector<int>> c);

void swapRoutes(vector<int> &v1, vector<int> &v2, int n1, int n2, int i, int j, vector<int> &d_routs, vector<int> d);

Solution buscaExaustivaN2(Solution initial_solution, int Q, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif