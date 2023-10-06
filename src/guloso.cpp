#include <iostream>
#include <vector>
#include <string>
#include "guloso.h"

using namespace std;

// Recebe o vértice atual e percorre  linha correspondente na matriz buscando o 
// mais próximo (aresta de menor valor)

int guloso(int cliente_atual, int n, vector<vector<int>> c){
    //começa de 1 pra pular o depósito
    int index = 1;
    int viz_prox = c[cliente_atual][1];

    for (int i = 1; i < (n-1) ; i++){
        if (c[cliente_atual][i] < viz_prox && i != cliente_atual){ //não pode i == cliente_atual pq é 0
            index = i;
            viz_prox = c[cliente_atual][i];
        }
    }

    return index;
}