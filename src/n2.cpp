#include <iostream>
#include <vector>
#include <random>
#include "construtor.h"
#include "datatype.h"
#include <chrono>

using namespace std;

int findMaxCostVertex(vector<int> &rota, vector<vector<int>> c){
    int vertice;
    int cost = 0;
    for (int i = 1; i < rota.size()-1; i++){
        //cout << "Custo da aresta: (" << rota[i-1] << ","<< rota[i] << ")" << " = " << c[rota[i-1]][rota[i]] << endl;
        //cout << "Custo da aresta: (" << rota[i] << ","<< rota[i+1] << ")" << " = " << c[rota[i]][rota[i+1]] << endl;

        if(c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] > cost){
            cost = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]];
            vertice = i;
        }
    }

    cout << "FINAL DA CHAMDA\n" << endl;
    return vertice;
};

void Swap_Routes(int *total_cost, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v1, vector<int> &v2, vector<int> &d_routs){
    
    /*
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    uniform_int_distribution<int> distribution1(1, v1.size() - 2);
    uniform_int_distribution<int> distribution2(1, v2.size() - 2);
    */

    int n1 = findMaxCostVertex(v1, c);
    int n2 = findMaxCostVertex(v2, c);

    int cliente1 = v1[n1];
    int cliente2 = v2[n2];
    int ant_i = v1[n1-1];
    int prox_i = v1[n1+1];
    int ant_j = v2[n2-1];
    int prox_j = v2[n2+1];

    cout << "\n" << endl;
    cout << "O cliente mais caro da rota 1 eh: " << cliente1 << endl;
    cout << "O cliente mais caro da rota 2 eh: " << cliente2 << endl;

    cout << "\n" << endl;
    cout << "A DEMANDA DE CADA CARRO EH: " << Q << endl;

    cout << "\n" << endl;
    cout << "A demanda do cliente " << cliente1 << " eh:  " << d[cliente1-1] << endl;
    cout << "A demanda do cliente " << cliente2 << " eh:  " << d[cliente2-1] << endl;

    cout << "\n" << endl;
    cout << "A demanda da rota 1 eh: " << d_routs[0] << endl;
    cout << "A demanda da rota 2 eh: " << d_routs[1] << endl;

    cout << "\n" << endl;
    bool status;
    int d_att;
    
    if(d[cliente1-1] > d[cliente2-1]){
        cout << "Demanda do cliente " << cliente1 << " eh maior, ver como vai impactar na rota 2" << endl;
        d_att = d_routs[1];
        cout << "Demanda da rota 2 = " << d_att << endl;
        d_att -= d[cliente2-1];
        cout << "Demanda da rota 2 - demanda do cliente 2 = " << d_att << endl;
        d_att += d[cliente1-1];
        cout << "Demanda da rota 2 + demanda do cliente 1 = " << d_att << endl;

        if(d_att > Q){
            status = false;
        }
        else{
            status = true;
        }
        cout << "Pode fazer a troca? " << status << endl;
    }
    else if(d[cliente2-1] > d[cliente1-1]){
        cout << "Demanda do cliente " << cliente2 << " eh maior, ver como vai impactar na rota 1" << endl;
        d_att = d_routs[0];
        cout << "Demanda da rota 1 = " << d_att << endl;
        d_att -= d[cliente1-1];
        cout << "Demanda da rota 1 - demanda do cliente 1 = " << d_att << endl;
        d_att += d[cliente2-1];
        cout << "Demanda da rota 1 + demanda do cliente 2 = " << d_att << endl;

        if(d_att > Q){
            status = false;
        }
        else{
            status = true;
        }
        cout << "Pode fazer a troca? " << status << endl;
    }
    else{
        status = true;
        cout << "Demandas Iguais" << endl;
    }

    if(status){
        cout << "\n" << endl;
        cout << "FAZENDO SWAP DO " << cliente1 << " COM O CLIENTE: " << cliente2 << endl;
        cout << "O CUSTO ANTES DO SWAP EH: " << *total_cost << endl;
        
        /*
        cout << "\n" << endl;
        cout << "Custo da aresta (" << ant_i << "," << cliente1 << ") = " << c[ant_i][cliente1] << endl;
        cout << "Custo da aresta (" << cliente1 << "," << prox_i << ") = " << c[cliente1][prox_i] << endl;

        cout << "\n" << endl;
        cout << "Custo da aresta (" << ant_j << "," << cliente2 << ") = " << c[ant_j][cliente2] << endl;
        cout << "Custo da aresta (" << cliente2 << "," << prox_j << ") = " << c[cliente2][prox_j] << endl;
        
        cout << "\n" << endl;
        cout << "Custo da nova aresta (" << ant_i << "," << cliente2 << ") = " << c[ant_i][cliente2] << endl;
        cout << "Custo da nova aresta (" << cliente2 << "," << prox_i << ") = " << c[cliente2][prox_i] << endl;

        cout << "\n" << endl;
        cout << "Custo da nova aresta (" << ant_j << "," << cliente1 << ") = " << c[ant_j][cliente1] << endl;
        cout << "Custo da nova aresta (" << cliente1 << "," << prox_j << ") = " << c[cliente1][prox_j] << endl;
        */
        *total_cost -= c[ant_i][cliente1];
        *total_cost -= c[cliente1][prox_i];

        *total_cost -= c[ant_j][cliente2];
        *total_cost -= c[cliente2][prox_j];

        *total_cost += c[ant_i][cliente2];
        *total_cost += c[cliente2][prox_i];

        *total_cost += c[ant_j][cliente1];
        *total_cost += c[cliente1][prox_j];

        int aux1 = cliente1;
        int aux2 = cliente2;
        v1[n1] = aux2;
        v2[n2] = aux1;

        d_routs[0] -= d[cliente1-1];
        d_routs[0] += d[cliente2-1];

        d_routs[1] -= d[cliente2-1];
        d_routs[1] += d[cliente1-1];

        cout << "\n" << endl;
        cout << "O CUSTO DEPOIS DO SWAP EH: " << *total_cost << endl;
        cout << "\n" << endl;
    }
    else{
        return;
    }
}