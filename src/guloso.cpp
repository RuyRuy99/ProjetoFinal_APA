#include <iostream>
#include <vector>
#include <string>
#include "guloso.h"

using namespace std;

int guloso(int i, int n, vector<vector<int>> c){

    int aux = c[i][0];
    int viz_prox = 0;
    
    for(int j=1; j<n; j++){
        if(c[i][j] < aux){
            aux = c[i][j];
            viz_prox = j;
    }}
    return viz_prox;
}