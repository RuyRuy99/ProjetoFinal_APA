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
    //cout << "qtd de rotas * r = " << solucao.routes.size() * r << endl;

    //Adiciona o custo dos terceirizados
    for (int i = 0; i < solucao.terceirizados.size(); i++){
        //cout << "Custo de terceirizar o cliente " << solucao.terceirizados[i] << " = " << p[solucao.terceirizados[i]-1] << endl;
        custo_real += p[solucao.terceirizados[i]-1];
    }

    //Adiciona o custo de cada rota
    for (int k = 0 ; k < solucao.routes.size(); k++){
        for (int i = 0; i < solucao.routes[k].size()-1; i++){
            //cout << "Custo da aresta " << solucao.routes[k][i] << " -> " << solucao.routes[k][i+1] << " = " << c[solucao.routes[k][i]][solucao.routes[k][i+1]] << endl;
            custo_real += c[solucao.routes[k][i]][solucao.routes[k][i+1]];
        }
    }

    cout << "CUSTO REAL: " << custo_real << endl;
}