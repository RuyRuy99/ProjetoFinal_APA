#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include "vnd.h"
#include "datatype.h"
#include "n1.h"

using namespace std;

Solution pertubacao(Solution solucao, vector<vector<int>> c){

    // Inicializa o gerador de números aleátorios com o relógio
    srand((unsigned) time(0));
    
    int num_rotas = solucao.routes.size(); //Colocar na struct a quantidade de rotas
    cout << "Numero de rotas: " << num_rotas << endl;
    int custo_inicial = solucao.totalCost;

    //Para cada rota
    for (int k = 0; k < num_rotas; k++){


        // Escolhe um cliente aleatório da rota
        int random_i = rand() % (solucao.route_size[k]-2) + 1;
        int random_j = rand() % (solucao.route_size[k]-2) + 1;

        cout << "Indices randomicos: " << random_i << " " << random_j << endl;
        //swapInside(solucao.routes[k], random_i, random_j);

        int novo_custo = custoSwap(solucao.totalCost, c, solucao.routes[k], random_i, random_j);
        cout << "Custo inicial: " << custo_inicial << endl;
        cout << "Novo custo: " << novo_custo << endl;

    }
    
    return solucao;
}

Solution ILS(Solution solucao_inicial, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution S0  = solucao_inicial;
    Solution S = vnd(S0, Q, L, d, p, c); // Busca local
    int cont= 0;

    while(cont <= 10){ // Pode ser até 10 vezes sem achar uma melhor solução ou um tempo máximo
        
        Solution S1 = pertubacao(S,c); // Fazer perturbações na solução
        Solution S2 = vnd(S1, Q, L, d, p, c); // Busca local

        // Critério de Aceitação
        if(S2.totalCost < S.totalCost){
            S = S2;
        }
        cont++;
    }

    return S;
}