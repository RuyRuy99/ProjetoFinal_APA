#include <iostream>
#include <vector>
#include <string>
#include "terceirizacao.h"

using namespace std;

int terceirizacao(vector<int> lst_clientes, vector<int> p){

    int result = 0;

    for(int i=0; i<lst_clientes.size(); i++){
        cout << "Custo para tercerizar o cliente " << lst_clientes[i] << " = " << p[lst_clientes[i] - 1] << endl;
        result += p[lst_clientes[i] - 1];
    }
    
    return result;
}