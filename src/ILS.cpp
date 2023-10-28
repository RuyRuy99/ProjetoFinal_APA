#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include "readfile.h"
#include "checksolution.h"
#include "datatype.h"
#include "vnd.h"
#include "n1.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "showsolution.h"

using namespace std;

Solution pertubacao(Solution solucao, int Q, vector<int> d, vector<vector<int>> c){

    // Inicializa o gerador de números aleátorios com o relógio
    srand((unsigned) time(0));
    
    // Variaveis auxiliares
    int num_rotas = solucao.routes.size();
    int custo_inicial = solucao.totalCost;

    for (int k = 0; k < num_rotas; k++){
        
        for (int i = 0 ; i < 10; i ++){
            int tam_rota = solucao.routes[k].size() - 2; //Subtrai 2 para não pegar o depósito
            //cout << "Rota " << k + 1 << " tam =  " << tam_rota << endl;

            int random_i = rand() % tam_rota + 1;
            int random_j = rand() % tam_rota + 1;
            
            //cout << "INDICES: " << random_i << " " << random_j << endl;

            //pq eu sempre passo o custo inicial ? solucao.totalCost
            int novo_custo = custoSwap(solucao.totalCost, c, solucao.routes[k], random_i, random_j);
            //cout << "Custo apos SWAP: " << novo_custo << endl;

            //Atualiza o custo
            solucao.totalCost = novo_custo;

            //Atualiza o vetor de rotas
            swapInside(solucao.routes[k], random_i, random_j);
        }
    }
    return solucao;
}

Solution ILS(Solution solucao_inicial, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){


    //Solução ja inicia após a busca local (VND)    
    Solution S = solucao_inicial;
    int cont = 0;
    //cout << "Solucao pre ils" << endl;
    //printSolution(S);

    while(cont <= 100){ // Pode ser até 10 vezes sem achar uma melhor solução ou um tempo máximo
        //cout << "Iteracao " << cont << endl;
        // Fazer perturbações na solução
        Solution S1 = pertubacao(S, Q, d, c);
        
        // Busca local
        Solution S2 = vnd(S1, r, Q, L, d, p, c);
        //doublecheck(S2, Q, L, r, d, p, c);

        //cout << "Custo de S2: " << S2.totalCost << endl;
        //cout << "Custo de S: " << S.totalCost << endl;
        // Critério de Aceitação
        if(S2.totalCost < S.totalCost){
            //cout << "Melhorou" << endl;
            S = S2;
        
        }else{
            //cout << "Não melhorou" << endl;
            cont++;
        }
    }

    return S;
}