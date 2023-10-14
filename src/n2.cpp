#include <iostream>
#include <vector>
#include <random>
#include "construtor.h"
#include "datatype.h"
#include <chrono>

using namespace std;

void Swap_Routes(int *total_cost, int cap_atual, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v1, vector<int> &v2){

    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);  // Mersenne Twister 19937 gerador
    uniform_int_distribution<int> distribution1(1, v1.size() - 2);
    uniform_int_distribution<int> distribution2(1, v2.size() - 2);
    
    int n1 = distribution1(generator);
    int n2 = distribution2(generator);

    // Acessar o elemento correspondente no vetor
    int cliente1 = v1[n1];
    int cliente2 = v2[n2];

    /* Imprimir o n�mero aleat�rio e o elemento selecionado
    cout << "Index aleatorio 1: " << n1 << endl;
    cout << "Cliente Selecionado 1: " << cliente1 << endl;
    cout << "\n" << endl;
    cout << "Index aleatorio 2: " << n2 << endl;
    cout << "Cliente Selecionado 2: " << cliente2 << endl;
    cout << "\n" << endl;
    */

    int ant_i = v1[n1-1];
    int prox_i = v1[n1+1];
    int ant_j = v2[n2-1];
    int prox_j = v2[n2+1];
    /*
    cout << "O Cliente anterior a " << cliente1 << " eh: " << ant_i << endl;
    cout << "O Cliente proximo a " << cliente1 << " eh: " << prox_i << endl;
    cout << "\n" << endl;
    cout << "O Cliente anterior a " << cliente2 << " eh: " << ant_j << endl;
    cout << "O Cliente proximo a " << cliente2 << " eh: " << prox_j << endl;
    */

    cout << "\n";
    cout << "FAZENDO SWAP DO " << cliente1 << " COM O CLIENTE: " << cliente2 << endl;
    cout << "O CUSTO ANTES DO SWAP EH: " << *total_cost << endl;
    
    cout << "\n";
    cout << "Custo da aresta (" << ant_i << "," << cliente1 << ") = " << c[ant_i][cliente1] << endl;
    cout << "Custo da aresta (" << cliente1 << "," << prox_i << ") = " << c[cliente1][prox_i] << endl;

    cout << "\n";
    cout << "Custo da aresta (" << ant_j << "," << cliente2 << ") = " << c[ant_j][cliente2] << endl;
    cout << "Custo da aresta (" << cliente2 << "," << prox_j << ") = " << c[cliente2][prox_j] << endl;
    
    cout << "\n";
    cout << "Custo da nova aresta (" << ant_i << "," << cliente2 << ") = " << c[ant_i][cliente2] << endl;
    cout << "Custo da nova aresta (" << cliente2 << "," << prox_i << ") = " << c[cliente2][prox_i] << endl;

    cout << "\n";
    cout << "Custo da nova aresta (" << ant_j << "," << cliente1 << ") = " << c[ant_j][cliente1] << endl;
    cout << "Custo da nova aresta (" << cliente1 << "," << prox_j << ") = " << c[cliente1][prox_j] << endl;

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

    cout << "\n";
    cout << "O CUSTO DEPOIS DO SWAP EH: " << *total_cost << endl;
    cout << "\n";
    // i é o vertice correspondente ao routes[0][i]
    // j é o vertice correspondente ao routes[1][j]

    // Encontrar o maior o vertice i que possue a maior soma das arestas
    // Encontrar o maior o vertice j que possue a maior soma das arestas

    // Verificar se quando efetuado a troca a demanda ultrapassa a capacidade do carro. 
    // Se verdadeiro, a troca é efetuada e custo recalculado:
        
        // Define: 
        // Recalcula o custo da solução:
        /*
        *total_cost -= c[ant_i][v[i]];
        *total_cost -= c[v[i]][prox_i];

        *total_cost -= c[ant_j][v[j]];
        *total_cost -= c[v[j]][prox_j];

        *total_cost -= c[ant_i][v[j]];
        *total_cost -= c[v[j]][prox_i];

        *total_cost -= c[ant_j][v[i]];
        *total_cost -= c[v[i]][prox_j];

        int aux1 = v[i];
        int aux2 = v[j];
        v[i] = aux1;
        v[j] = aux2;
        */
}

