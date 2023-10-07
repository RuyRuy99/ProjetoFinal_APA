#include <iostream>
#include <vector>
#include <string>
#include "guloso.h"

using namespace std;

int guloso(int cliente_atual, int n, vector<vector<int>> c){
    
    int index = 1;
    int viz_prox = c[cliente_atual][1];

    for (int i = 1; i < n; i++){
        if (c[cliente_atual][i] < viz_prox && i != cliente_atual){
            index = i;
            viz_prox = c[cliente_atual][i];
        }
    }

    return index;
}