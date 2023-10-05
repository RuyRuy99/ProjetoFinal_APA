#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "teste.h"
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
    cout << "Size of dados = " << dados.size() << endl;
    dados = read_file("instance.txt");
    cout << "Size of dados = " << dados.size() << endl;

    cout <<"Primeiro e ultimo elemento do vetor: " << dados[0] << " " << dados[dados.size()-1] << endl;

    //swap(&dados[0], dados.size()); //passando vector por referencia
    //cout <<"Primeiro e ultimo elemento do vetor: " << dados[0] << " " << dados[dados.size()-1] << endl;
    alguma_coisa(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);

    //print do vetor d
    cout << "VECTOR D FORA DA FUNÇÃO: ";
    for (int i = 0; i < d.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;
    //print do vetor p
    cout << "VECTOR P FORA DA FUNÇÃO: ";
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    cout << endl;

    //print da matriz c
    cout << "MATRIZ C FORA DA FUNÇÃO: " << endl;
    for (int i = 0; i < c.size(); i++){
        for (int j = 0; j < c[i].size(); j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }


    //print das variaveis após a função
    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    cout << "Q = " << Q << endl;
    cout << "L = " << L << endl;
    cout << "r = " << r << endl;
    



    return 0;
}