#include <iostream>
#include <vector>
#include <string>
#include "guloso.h"

using namespace std;

int guloso(int inicio, int n, vector<vector<int>> c){
    //começa de 1 pra pular o depósito
    int index = 1;
    int viz_prox = c[inicio][1];

    for (int i = 1; i < (n-1) ; i++){
        if (c[inicio][i] < viz_prox and i != inicio){ //não pode i == inicio pq é 0
            index = i;
            viz_prox = c[inicio][i];
        }
    }

    return index;
}