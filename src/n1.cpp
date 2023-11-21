#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

int custoSwap(int custo_atual, const vector<vector<int>> &c, const vector<int> &v, int i, int j){

    int novo_custo = custo_atual;
    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int ant_j = v[j-1];
    int prox_j = v[j+1];

    // Remove o custo de quem estava ligado em i
    novo_custo -= c[ant_i][v[i]];
    novo_custo -= c[v[i]][prox_i];

    // Remove o custo de quem estava ligado em j
    novo_custo -= c[ant_j][v[j]];
    novo_custo -= c[v[j]][prox_j];

    // Adiciona o novo custo em relação a troca de j
    novo_custo += c[ant_i][v[j]];
    novo_custo += c[v[j]][prox_i];

    // Adiciona o novo custo em relação a troca de i
    novo_custo += c[ant_j][v[i]];
    novo_custo += c[v[i]][prox_j];

    // Se a diferença de J e I == 1 então ele removeu 2 arestas iguais
    if (abs(j - i) == 1){

        if (j > i){

            // Adiciona a aresta i e o próximo de i
            novo_custo += c[v[i]][prox_i];
        
            // Adiciona a aresta j i
            novo_custo += c[v[j]][v[i]];
       
        }else{

            // Adiciona a aresta j e o próximo de j
            novo_custo += c[v[j]][prox_j];

            // Adiciona a aresta i j
            novo_custo += c[v[i]][v[j]];
        }

    }
    
    return novo_custo;
}

void swapInside(vector<int> &v, int i, int j){
    
    // Swap no vetor de rotas
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


Solution* SwapIntra(Solution* current_solution, InstanceData* dados){
    // Variáveis para auxiliar a encontrar o mínimo
    int min_custo = current_solution->totalCost;
    int min_rota_idx = -1;
    int min_i_global = -1;
    int min_j_global = -1;

    int num_rotas = current_solution->routes.size();

    // Refazendo todo o laço
    for (int k = 0; k < num_rotas; k++) {
        for (int i = 1; i < current_solution->routes[k].size() - 1; i++) { // O(n)
            for (int j = i + 1; j < current_solution->routes[k].size() - 1; j++) { // O(n)
                // O(n^2)
                int novo_custo = custoSwap(current_solution->totalCost, dados->c, current_solution->routes[k], i, j);

                // Se o custo novo for menor que o mínimo global, atualiza o mínimo
                if (novo_custo < min_custo) {
                    min_custo = novo_custo;
                    min_rota_idx = k;
                    min_i_global = i;
                    min_j_global = j;
                }
            }
        }
    }

    if (min_rota_idx != -1) {
        swapInside(current_solution->routes[min_rota_idx], min_i_global, min_j_global);
        current_solution->totalCost = min_custo;
    }

    // Retorna o ponteiro para a current_solution modificada
    return current_solution;
}
