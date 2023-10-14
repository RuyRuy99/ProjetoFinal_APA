#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"

using namespace std;

void Upgrade_Routes(int *total_cost, int cap_atual, int Q, vector<int> lst_clientes,vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v, int i){

    int ant_i = v[i-1];
    int prox_i = v[i+1];

    for(int j=0; j < lst_clientes.size(); j++){ // Percorrendo a lista de clientes não atendidos

        int cliente_atual = lst_clientes[j]; // Cliente da lista de não atendidos
        if(d[v[i-1]] > p[v[i-1]]){ // Custo de ida e volta menor que a terceirização
            
            cap_atual -= d[v[i-1]];
            if(cap_atual + d[cliente_atual-1] <= Q){ // Verificando se não ultrapassou a capacidade do carro

                // Remove o custo de quem estava ligado em i
                *total_cost -= c[ant_i][v[i]];
                *total_cost -= c[v[i]][prox_i];;

                // Adiciona o novo custo em relação a troca de j
                *total_cost += c[ant_i][cliente_atual];
                *total_cost += c[cliente_atual][prox_i];

                // Swap no vetor de rotas
                int aux = v[i];
                v[i] = cliente_atual;

                // Swap na lista de clientes não atendidos
                lst_clientes[j] = aux;
                break;
                   
            }
        }
    }
}     