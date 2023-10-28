#ifndef N3_H_
#define N3_H_
#include <vector>
#include "datatype.h"

using namespace std;


int melhora_rotas(Solution solucao, int k, vector<int> v, int i, vector<int> terc, int j, int Q ,int L, vector<int> d, vector<int> p, vector<vector<int>> c);

void atualizaValores(vector<int> &v, int i, vector<int> &terc, int j, vector<int> d, int *rota_demanda);

Solution N3(Solution initial_solution, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif