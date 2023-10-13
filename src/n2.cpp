#include <iostream>
#include <vector>
#include "construtor.h"

using namespace std;

void Swap_Routes(int *total_cost, int cap_atual, int Q, vector<int> lst_clientes,vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v, int i){

    // i é o vertice correspondente ao routes[0][i]
    // j é o vertice correspondente ao routes[1][j]

    // Encontrar o maior o vertice i que possue a maior soma das arestas
    // Encontrar o maior o vertice j que possue a maior soma das arestas

    // Verificar se quando efetuado a troca a demanda ultrapassa a capacidade do carro. 
    // Se verdadeiro, a troca é efetuada e custo recalculado:
        
        // Define: ant_i, ant_j, prox_i e prox_j
        // Recalcula o custo da solução:

        *total_cost -= c[ant_i][v[i]];
        *total_cost -= c[v[i]][prox_i];

        *total_cost -= c[ant_j][v[j]];
        *total_cost -= c[v[j]][prox_j];

        *total_cost -= c[ant_i][v[j]];
        *total_cost -= c[v[j]][prox_i];

        *total_cost -= c[ant_j][v[i]];
        *total_cost -= c[v[i]][prox_j];

        int aux1 = v[i];
        int aux2 = v[j];
        v[i] = aux1;
        v[j] = aux2;

}

