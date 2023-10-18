#ifndef N3_1_H_
#define N3_1_H_
#include <vector>

using namespace std;



void melhora_rotas(int Q ,int L, vector<int> d,vector<int> p, vector<vector<int>> c, vector<int> &v, vector<int> &terc, int i, int *terc_size,int *clientes_att,int *total_cost,int *rota_demanda);

void buscaExaustivaN3(int Q ,int L, int *total_cost, int *terc_size, int *total_clientes, vector<int> d, vector<int> p, vector<vector<int>> c, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &rota_dem);

#endif