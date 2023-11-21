#ifndef N1_H_
#define N1_H_

#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

// Calcula o custo de troca de clientes na rota
int custoSwap(int custo_atual, const vector<vector<int>> &c, const vector<int> &v, int i, int j);

// Realiza a troca de clientes na rota
void swapInside(vector<int> &v, int i, int j);

// Busca exaustiva para a estrutura de vizinhança N1
Solution* SwapIntra(Solution* current_solution, InstanceData* dados);

#endif