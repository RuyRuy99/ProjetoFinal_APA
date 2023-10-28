#ifndef N1_H_
#define N1_H_

using namespace std;

// Calcula o custo de troca de clientes na rota
int custoSwap(int custo_atual, vector<vector<int>> c, vector<int> &v, int i, int j);

// Realiza a troca de clientes na rota
void swapInside(vector<int> &v, int i, int j);

// Busca exaustiva para a estrutura de vizinhança N1
Solution SwapIntra(Solution initial_solution, vector<vector<int>> c);

#endif