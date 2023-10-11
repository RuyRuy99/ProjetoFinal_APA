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

    int ant_i = i-1;
    int prox_i = i+1;
    int ant_j = j-1;
    int prox_j = j+1;

    if (i != j){
        //remove o custo de quem estava ligado em i
        *total_cost -= c[v[ant_i]][v[i]];
        cout << "Apos remover a aresta [" << v[ant_i] << "][" << v[i] << "] o custo atual = " << *total_cost << endl;
        *total_cost -= c[v[i]][v[prox_i]];
        cout << "Apos remover a aresta [" << v[i] << "][" << v[prox_i] << "] o custo atual = " << *total_cost << endl;

        
        //remove o custo de quem estava ligado em j

        *total_cost -= c[v[ant_j]][v[j]];
        cout << "Apos remover a aresta [" << v[ant_j] << "][" << v[j] << "] o custo atual = " << *total_cost << endl;
        *total_cost -= c[v[j]][v[prox_j]];
        cout << "Apos remover a aresta [" << v[j] << "][" << v[prox_j] << "] o custo atual = " << *total_cost << endl;
       

        //adiciona o novo custo em relação a troca de j
        *total_cost += c[v[ant_i]][v[j]];
        cout << "Apos adicionar a aresta [" << v[ant_i] << "][" << v[j] << "] o custo atual = " << *total_cost << endl;
        *total_cost += c[v[j]][v[prox_i]];
        cout << "Apos adicionar a aresta [" << v[j] << "][" << v[prox_i] << "] o custo atual = " << *total_cost << endl;

        //adiciona o novo custo em relação a troca de i
        *total_cost += c[v[ant_j]][v[i]];
        cout << "Apos adicionar a aresta [" << v[ant_j] << "][" << v[i] << "] o custo atual = " << *total_cost << endl;
        *total_cost += c[v[i]][v[prox_j]];
        cout << "Apos adicionar a aresta [" << v[i] << "][" << v[prox_j] << "] o custo atual = " << *total_cost << endl;
        //se a diferença de J e I == 1 então ele removeu 2 arestas iguais
        if (j - i == 1){
            *total_cost += c[v[i]][v[prox_i]];
        }
        cout << "Custo total = " << *total_cost << endl;

        //swap no vetor
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        //cout << "Custo atualizado = " << *total_cost << endl;
    }
}