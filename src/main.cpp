#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "readfile.h"
#include "datatype.h"
#include "construtor.h"
#include "guloso.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "vnd.h"
#include "ILS.h"


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
    dados = read_file("instance4.txt");
    //cout << "Size of dados = " << dados.size() << endl;

    extrai_dados(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);

    //print do vetor d
    cout << "VECTOR D FORA DA FUNCAO: ";
    print_array(&d[0], d.size());

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
    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    cout << "Q = " << Q << endl;
    cout << "L = " << L << endl;
    cout << "r = " << r << endl;
    cout << endl;
    
    Solution result = buildSolution(n, k, r, Q, L, c, d, p);
    printSolution(result);

    //busca exaustiva N1 para cada rota
    //cout << "EXECUTANDO N1" <<endl;
    //Solution result2 = buscaExaustivaN1(result, c);
    //printSo/ution(result2);

    
    //busca exaustiva N2 para cada rota
    //cout << "EXECUTANDO N2" <<endl;
    //Solution result3 = buscaExaustivaN2(result, Q, d, p, c);
    //printSolution(result3);
    
    //cout << "EXECUTANDO N3" << endl;
    //Solution result4 = buscaExaustivaN3(result, Q, L, d, p, c);
    //printSolution(result4);
    

    //cout << "EXECUTANDO N4" <<endl;
    //Solution result5 = buscaExaustivaN4(result, L, p, d, c);
    //printSolution(result5);

    //cout << "EXECUTANDO N5" <<endl;
    //Solution result7 = buscaExaustivaN5(result, Q, d, p, c);
    //printSolution(result7);
    
    /*
    cout << "EXECUTANDO O VND" << endl;
    Solution result6 = vnd(result, Q, L, d, p, c);
    printSolution(result6);
    cout << "Demanda de cada rotas: ";
    print_array(&result6.rota_dem[0], result6.rota_dem.size());
    */

    Solution pert_solution = pertubacao(result, c);
    printSolution(pert_solution);

    return 0;
}