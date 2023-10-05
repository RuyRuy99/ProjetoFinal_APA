#include <iostream>
#include <vector>
#include <string>
#include "terceirizacao.h"

using namespace std;

int terceirização(vector<int> lst_clientes, int result, vector<int> p){

    for(int i=0; i<sizeof(lst_clientes); i++){
        result += p[i];
    }
    
    return result;
}