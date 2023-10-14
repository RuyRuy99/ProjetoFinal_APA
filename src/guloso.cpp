#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "guloso.h"
#include "datatype.h"

using namespace std;

pair<int, int> guloso(int cliente_atual, vector<vector<int>> c, vector<int> list_clientes){
    
    int custo = c[cliente_atual][list_clientes[0]];
    int viz_prox = list_clientes[0];
    int index = 0;

    // Percorre a lista de clientes não atendidos para encontrar o vizinho mais próximo
    for (int i = 0 ; i < list_clientes.size(); i++){
        
        if (c[cliente_atual][list_clientes[i]] < custo){ 
            custo = c[cliente_atual][list_clientes[i]];
            viz_prox = list_clientes[i];
            index = i;
        }
    }

    return make_pair(viz_prox, index);
}