#ifndef N2_H_
#define N2_H_

using namespace std;

void ReinsertionFunc(vector<vector<int>> c, vector<int> &rota1, int i, int j);

int costReinsertion(int total_cost, vector<vector<int>> c, vector<int> &rota, int i, int j);

Solution Reinsertion(Solution initial_solution, vector<vector<int>> c);
#endif