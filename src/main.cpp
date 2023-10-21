#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "readfile.h"
#include "construtor.h"
#include "guloso.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "datatype.h"
using namespace std;


int main(void){

    int n;// Número de clientes
    int k; // Quantidade de veículos
    int Q; // Quantidade máxima de cada veículo
    int L; // Quantidade mínima de entrega sem terceirização
    int r; // Custo de cada veículo

    vector<int> dados;
    vector<int> d;
    vector<int> p;
    vector<vector<int>> c;
    dados = read_file("instance3.txt");
    //cout << "Size of dados = " << dados.size() << endl;

    extrai_dados(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);

    //print do vetor d
    //cout << "VECTOR D FORA DA FUNCAO: ";
    //print_array(&d[0], d.size());

    //print do vetor p
    //cout << "VECTOR P FORA DA FUNCAO: ";
    //print_array(&p[0], p.size());

    //print da matriz c
    /*
    cout << "MATRIZ C FORA DA FUNCAO: " << endl;
    for (int i = 0; i < c.size(); i++){
        print_array(&c[i][0], c[i].size());
    }
    cout << endl;
    */
    //print das variaveis após a função
    //cout << "n = " << n << endl;
    //cout << "k = " << k << endl;
    //cout << "Q = " << Q << endl;
    //cout << "L = " << L << endl;
    //cout << "r = " << r << endl;
    //cout << endl;
    
    Solution result = buildSolution(n, k, r, Q, L, c, d, p);
    printSolution(result);



    //busca exaustiva N1 para cada rota
    cout << "EXECUTANDO N1" <<endl;
    buscaExaustivaN1(c, result.routes, &result.totalCost);
    printSolution(result);
    
   

 



    
    /*
    printSolution(result);

    for (int i = 0; i < result.rota_dem.size(); i++){
        cout << "Rota " << i << " tem demanda " << result.rota_dem[i] << endl;
    }
    */

    //buscaExaustivaN2(result.routes, &result.totalCost, Q, d, c, p, result.rota_dem);

    //printSolution(result);

    /*
    for (int i = 0; i < result.rota_dem.size(); i++){
        cout << "Rota " << i << " tem demanda " << result.rota_dem[i] << endl;
    }

    */
    
    //melhora_rotas(Q, L , d, p , c, result.routes[1], result.terceirizados, 3, &result.terc_size, &result.total_clientes, &result.totalCost, &result.rota_dem[1]);
    cout << "EXECUTANDO N3" <<endl;
    buscaExaustivaN3(Q, L, &result.totalCost, &result.terc_size, &result.total_clientes, d, p, c, result.routes, result.terceirizados, result.rota_dem);
    printSolution(result);


    cout << "EXECUTANDO N4" <<endl;
    buscaExaustivaN4(L, &result.totalCost, &result.terc_size, &result.total_clientes, d, p, c, result.routes, result.terceirizados, result.rota_dem, result.route_size);
    printSolution(result);
    return 0;
}