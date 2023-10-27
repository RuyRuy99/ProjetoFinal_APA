#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include "readfile.h"
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

    // Percorre as rotas
    for (int k = 0; k < num_rotas; k++){
        //Realiza 10 perturbações
        for (int i = 0; i < 10; i++){

            // Escolhe uma rota aleatória
            int r1 = rand() % (num_rotas - 1) + 0;
            int r2 = rand() % (num_rotas - 1) + 0;

            // Escolhe um cliente aleátorio execeto o depósito
            int indice_cliente1 = rand() % (solucao.routes[r1].size() - 2) + 1; 
            int indice_cliente2 = rand() % (solucao.routes[r2].size() - 2) + 1;
            
            if(r1 != r2){
                
                int cliente_1 = solucao.routes[r1][indice_cliente1];
                int cliente_2 = solucao.routes[r2][indice_cliente2];
                
                // Verifica se o swap é possível
                bool verifica = checkSwap(Q, d, solucao.rota_dem, r1, r2, cliente_1, cliente_2);

                if (verifica){
                    solucao.totalCost = CaculaCustoSwap(solucao.totalCost, c, solucao.routes[r1], solucao.routes[r2], indice_cliente1, indice_cliente2);
                    swapRoutes(solucao.rota_dem, d, solucao.routes[r1], solucao.routes[r2], indice_cliente1, indice_cliente2, r1, r2);
                }
            }
        }
    }
    
    return solucao;
}

Solution ILS(Solution solucao_inicial, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    // Solução inicial que vem do construtor
    Solution S0  = solucao_inicial;
    // Busca Local
    Solution S = vnd(S0, r, Q, L, d, p, c);
    int cont = 0;

    while(cont <= 0){ // Pode ser até 10 vezes sem achar uma melhor solução ou um tempo máximo
        
        // Fazer perturbações na solução
        Solution S1 = pertubacao(S, Q, d, c);

        // Busca local
        Solution S2 = vnd(S1, r, Q, L, d, p, c);

        // Critério de Aceitação
        if(S2.totalCost < S.totalCost){
            S = S2;
        
        }else{
            cont++;
        }
    }

    return S;
}