#ifndef N4_H_
#define N4_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;

int calcula_custo(const Solution* solucao, int k, const vector<int>& v, int i, const vector<int>& terc, int j, const InstanceData* dados);

void atualizaValores(vector<int>& v, int i, vector<int>& terc, int j, vector<int>& d, int* rota_demanda);

Solution* SwapTerc(Solution* current_solution, InstanceData* dados);

#endif