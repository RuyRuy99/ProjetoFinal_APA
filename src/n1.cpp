#include <iostream>
#include <vector>
#include "readfile.h"
#include "construtor.h"
#include "showsolution.h"

using namespace std;

struct Solution{
    vector<vector<int>> routes;
    int totalCost = 0;
};

void swapInside(int *total_cost,vector<vector<int>> c,vector<int> &v, int i, int j){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int ant_j = v[j-1];
    int prox_j = v[j+1];

    if (i != j){

        //remove o custo de quem estava ligado em i
        *total_cost -= c[ant_i][v[i]];
        *total_cost -= c[v[i]][prox_i];
        
        //remove o custo de quem estava ligado em j
        *total_cost -= c[ant_j][v[j]];
        *total_cost -= c[v[j]][prox_j];

        //adiciona o novo custo em relação a troca de j
        *total_cost += c[ant_i][v[j]];
        *total_cost += c[v[j]][prox_i];

        //adiciona o novo custo em relação a troca de i
        *total_cost += c[ant_j][v[i]];
        *total_cost += c[v[i]][prox_j];

        //se a diferença de J e I == 1 então ele removeu 2 arestas iguais
        if (j - i == 1){
            *total_cost += c[v[i]][prox_i];
        }
        cout << "Custo total = " << *total_cost << endl;

        //swap no vetor
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        
        //cout << "Custo atualizado = " << *total_cost << endl;
    }
}