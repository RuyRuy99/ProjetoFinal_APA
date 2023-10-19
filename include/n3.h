#ifndef N3_1_H_
#define N3_1_H_
#include <vector>

using namespace std;


int melhora_rotas(int Q ,int L, vector<int> d, vector<vector<int>> c, vector<int> &v, int i, vector<int> &terc, int j, int *terc_size, int *total_cost, int *rota_demanda);

void atualizaValores(vector<int> &v, int i,vector<int> &terc, int j, vector<int> d, int *rota_demanda);

int buscaExaustivaN3(int Q ,int L, int *total_cost, int *terc_size, int *total_clientes, vector<int> d, vector<int> p, vector<vector<int>> c, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &rota_dem);


#endif