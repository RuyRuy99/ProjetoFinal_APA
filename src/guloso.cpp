#include <iostream>
#include <vector>
#include <string>
#include "guloso.h"

using namespace std;

int guloso(int inicio, int n, vector<vector<int>> c){
    //começa de 1 pra pular o depósito
    int viz_prox = c[inicio][1];

    for (int i = 1; i < n; i++){
        if (c[inicio][i] < viz_prox and i != inicio){ //não pode i == inicio pq é 0
            viz_prox = c[inicio][i];
        }
    }

    return viz_prox;
}