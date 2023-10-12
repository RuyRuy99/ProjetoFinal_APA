#include <iostream>
#include <vector>
#include "construtor.h"
#include "showsolution.h"

using namespace std;

void Upgrade_Routes(int *total_cost, int cap_atual, int Q, vector<int> lst_clientes,vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v, int i, int j){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int ant_j = v[j-1];
    int prox_j = v[j+1];

    for(int k=0; k < lst_clientes.size(); k++){ // Percorrendo a lista de clientes não atendidos

        int cliente_atual = lst_clientes[k];

        if(d[v[i]] < p[v[i]]){ // Custo de ida e volta menor que a terceirização
            cap_atual -= d[v[i]];
            if(cap_atual + d[cliente_atual] <= Q){ // Verificando se não ultrapassou a capacidade do carro

                if (i != j){

                    //remove o custo de quem estava ligado em i
                    *total_cost -= c[ant_i][v[i]];
                    *total_cost -= c[v[i]][prox_i];
                    
                    //remove o custo de quem estava ligado em j
                    *total_cost -= c[ant_j][v[j]];
                    *total_cost -= c[v[j]][prox_j];

                    //adiciona o novo custo em relação a troca de j
                    *total_cost += c[ant_i][cliente_atual];
                    *total_cost += c[cliente_atual][prox_i];

                    //adiciona o novo custo em relação a troca de i
                    *total_cost += c[ant_j][cliente_atual];
                    *total_cost += c[cliente_atual][prox_j];

                    //se a diferença de J e I == 1 então ele removeu 2 arestas iguais
                    if (j - i == 1){
                        *total_cost += c[v[i]][prox_i];
                    }

                    cout << "Custo total = " << *total_cost << endl;

                    //swap no vetor
                    int aux = v[i];
                    v[i] = cliente_atual;
                    lst_clientes[k] = aux;
                    break;
        }}
}}}     