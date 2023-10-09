#include <iostream>
#include <vector>
#include <string>
#include "terceirizacao.h"

using namespace std;

int terceirizacao(vector<int> lst_clientes, vector<int> p){

    int result = 0;

    for(int i=0; i<lst_clientes.size(); i++){
        result += p[i];
    }
    
    return result;
}