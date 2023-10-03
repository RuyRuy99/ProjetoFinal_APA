#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "teste.h"
using namespace std;


int main(void){
    //Colocar as variaveis int para cada Q, k ,L ,r
    vector<int> dados; // Utilizar ponteiro
    vector<int> d;
    vector<int> p;
    vector<vector<int>> c;
    cout << "Size of dados = " << dados.size() << endl;
    dados = read_file("instance.txt");
    cout << "Size of dados = " << dados.size() << endl;

    cout <<"Primeiro e ultimo elemento do vetor: " << dados[0] << " " << dados[dados.size()-1] << endl;

    //swap(&dados[0], dados.size()); //passando vector por referencia
    //cout <<"Primeiro e ultimo elemento do vetor: " << dados[0] << " " << dados[dados.size()-1] << endl;
    alguma_coisa(&dados[0], d, p, c);

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




    return 0;
}