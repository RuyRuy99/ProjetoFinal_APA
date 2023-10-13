#include <iostream>
#include <vector>
#include <string>
#include "terceirizacao.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;

int terceirizacao(vector<int> lst_clientes, vector<int> p){

    int result = 0;

    //show vector p
    //cout << "Custo de terceirizacao: ";
    //print_array(&p[0], p.size());

    for(int i=0; i<lst_clientes.size(); i++){
        //cout << "Custo para tercerizar o cliente " << lst_clientes[i] << " = " << p[lst_clientes[i] - 1] << endl;
        result += p[lst_clientes[i] - 1];
        //cout << "Result = " << result << endl;
    }

    return result;
}