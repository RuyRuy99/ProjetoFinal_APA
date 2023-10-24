#include <iostream>
#include <vector>
#include "readfile.h"
#include "datatype.h"
#include "construtor.h"
#include "showsolution.h"

using namespace std;

void doublecheck(Solution solucao, int Q, int L, int r, vector<int> d, vector<int> p ,vector<vector<int>> c){

    int custo_real = 0;

    //Adiciona o custo de cada carro
    custo_real += solucao.routes.size() * r;

    //Adiciona o custo dos terceirizados
    for (int i = 0; i < solucao.terceirizados.size(); i++){
        custo_real += p[solucao.terceirizados[i]];
    }

    //Adiciona o custo de cada rota
    for (int k = 0 ; k < solucao.routes.size(); k++){
        for (int i = 0; i < solucao.routes[k].size()-1; i++){
            custo_real += c[solucao.routes[k][i]][solucao.routes[k][i+1]];
        }
    }

    cout << "O valor da função objetivo é: " << custo_real << endl;
}