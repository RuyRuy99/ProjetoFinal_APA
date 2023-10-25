#ifndef N2_H_
#define N2_H_

using namespace std;

void ReinsertionFunc(vector<vector<int>> c, vector<int> &rota1, vector<int> &rota2, int i, int j);

void costReinsertion(int *total_cost, vector<vector<int>> c, vector<int> &rota1, vector<int> &rota2, int i, int j);

bool checkReinsertion(int Q, vector<int> d, vector<int> &d_routs, vector<int> &rota1, int rota_i, int rota_j, int i);

#endif