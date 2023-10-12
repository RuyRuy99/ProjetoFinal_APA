#include <iostream>
#include <vector>
#include "construtor.h"

using namespace std;

void Upgrade_Routes(int *total_cost, int cap_atual, int Q, vector<int> lst_clientes,vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v, int i){

    int ant_i = v[i-1];
    int prox_i = v[i+1];

    for(int j=0; j < lst_clientes.size(); j++){ // Percorrendo a lista de clientes não atendidos

        int cliente_atual = lst_clientes[j]; // Cliente da lista de não atendidos
        cout << "cliente atual: " << cliente_atual << endl;
        cout << "v[i]: " << v[i] << endl;
        cout << "d:v[i]: " << d[v[i-1]] << " > p:v[i]: " << p[v[i-1]] << endl;
        if(d[v[i-1]] > p[v[i-1]]){ // Custo de ida e volta menor que a terceirização
            
            cap_atual -= d[v[i-1]];
            cout << "cap_atual:" << cap_atual + d[cliente_atual-1] << endl;

            if(cap_atual + d[cliente_atual-1] <= Q){ // Verificando se não ultrapassou a capacidade do carro

                cout << "Custo total antes de tudo: " << *total_cost << endl;

                //remove o custo de quem estava ligado em i
                cout << "Removendo:" << endl;
                *total_cost -= c[ant_i][v[i]];
                cout << "De " << ant_i << " para " << v[i] << " -> custo: " << c[ant_i][v[i]] << endl;
                *total_cost -= c[v[i]][prox_i];
                cout << "De " << v[i] << " para " << prox_i << " -> custo: " << c[v[i]][prox_i] << endl;

                cout << "Custo total depois da remocao: " << *total_cost << endl;

                //adiciona o novo custo em relação a troca de j
                cout << "Adicionando:" << endl;
                *total_cost += c[ant_i][cliente_atual];
                cout << "De " << ant_i << " para " << cliente_atual << " -> custo: " << c[ant_i][cliente_atual] << endl;
                *total_cost += c[cliente_atual][prox_i];
                cout << "De " << cliente_atual << " para " << prox_i << " -> custo: " << c[cliente_atual][prox_i] << endl;

                cout << "Custo total depois da adicao: " << *total_cost << endl;

                //swap no vetor
                int aux = v[i];
                v[i] = cliente_atual;
                lst_clientes[j] = aux;
                break;
                   
            }
        }
    }
}     