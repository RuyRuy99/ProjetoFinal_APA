#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "readfile.h"
#include "construtor.h"
using namespace std;

struct Solution{
    vector<vector<int>> routes;
    int totalCost;
    };

int main(){

    int n;// Número de clientes
    int k; // Quantidade de veículos
    int Q; // Quantidade máxima de cada veículo
    int L; // Quantidade mínima de entrega sem terceirização
    int r; // Custo de cada veículo

    vector<int> dados;
    vector<int> d;
    vector<int> p;
    vector<vector<int>> c;
    dados = read_file("instance.txt");
    cout << "Size of dados = " << dados.size() << endl;

    extrai_dados(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);

    //print do vetor d
    cout << "VECTOR D FORA DA FUNCAO: ";
    print_array(&d[0], d.size());

    //print do vetor p
    cout << "VECTOR P FORA DA FUNCAO: ";
    print_array(&p[0], p.size());

    //print da matriz c
    cout << "MATRIZ C FORA DA FUNCAO: " << endl;
    for (int i = 0; i < c.size(); i++){
        print_array(&c[i][0], c[i].size());
    }
    cout << endl;

    //print das variaveis após a função
    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    cout << "Q = " << Q << endl;
    cout << "L = " << L << endl;
    cout << "r = " << r << endl;

    cout << endl;
    
    Solution result = buildSolution(n, k, r, Q, c, d, p);
    cout << "Custo total: " << result.totalCost << endl;

    cout << "Rotas: " << endl;
    for (int i = 0; i < result.routes.size(); i++){
        print_array(&result.routes[i][0], result.routes[i].size());
    }
    cout << endl;

    return 0;
}