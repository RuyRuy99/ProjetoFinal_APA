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
    //srand((unsigned) time(0));

    cout << "rote_size: " << solucao.route_size[0] << endl;

    int random_i = 1 + (rand() % (solucao.route_size[0]-2));
    int random_j = 1 + (rand() % (solucao.route_size[0]-2));
    //swapInside(solucao.routes[0], random_i, random_j);
    int novo_custo = custoSwap(solucao.totalCost, c, solucao.routes[0], random_i, random_j);
    cout << "custo: " << solucao.totalCost << endl;
    return solucao;
}

Solution ILS(Solution solucao_inicial, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution S0  = solucao_inicial;
    Solution S = vnd(S0, Q, L, d, p, c); // Busca local
    int cont=0;

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