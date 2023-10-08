#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "guloso.h"

using namespace std;

pair<int, int> guloso(int cliente_atual, vector<vector<int>> c, vector<int> list_clientes){
    
    int custo = c[cliente_atual][list_clientes[0]];
    int viz_prox;
    int index;
    cout << "Entrou no guloso" << endl;
    cout << "Tamanho da lista de clientes: " << list_clientes.size() << endl;
    cout << "Custo atual = " << custo << endl;


    //   0 ->[1,2,5,6]
    //cout <<" Tamanho de list_clientes = " << list_clientes.size() << endl;

    //varre a lista de clientes para encontrar o vizinho mais proximo que ainda não foi atendido
    for (int i = 0 ; i < list_clientes.size(); i++){
        cout << "Custo do vertice " << cliente_atual << " para o vertice " << list_clientes[i] << " = " << c[cliente_atual][list_clientes[i]] << endl;
        if (c[cliente_atual][list_clientes[i]] < custo){
            cout << "Custo do vertice " << cliente_atual << " para o vertice " << list_clientes[i] << " = " << c[cliente_atual][list_clientes[i]] << endl;
            custo = c[cliente_atual][list_clientes[i]];
            viz_prox = list_clientes[i];
            index = i;
        }
        else{
            
        }
    }

    //cout << "O vizinho mais proximo o vertice " << cliente_atual << " eh o vertice " << viz_prox << endl;

    return make_pair(viz_prox, index);
}