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
    
    int num_rotas = solucao.routes.size(); //Colocar na struct a quantidade de rotas
    //cout << "Numero de rotas: " << num_rotas << endl;
    int custo_inicial = solucao.totalCost;

    for (int i = 0; i < 20; i++){ //Realiza 10 perturbações

        //10 SWAP entre rotas N5

        // Escolhe uma rota aleatória

        int r1 = rand() % num_rotas;
        int r2 = rand() % num_rotas;

        int indice_cliente1 = rand() % (solucao.routes[r1].size() - 2) + 1; // Escolhe um cliente aleátorio execto o depósito
        int indice_cliente2 = rand() % (solucao.routes[r2].size() - 2) + 1; // Escolhe um cliente aleátorio execto o depósito
        
        if(r1 != r2){
            int cliente_1 = solucao.routes[r1][indice_cliente1];
            int cliente_2 = solucao.routes[r2][indice_cliente2];

            bool verifica = checkSwap(Q, d, solucao.rota_dem, r1, r2, cliente_1, cliente_2);

            if (verifica){
            //Faz o swap Inter rotas
            //cria a structswapresult
                solucao.totalCost = CaculaCustoSwap(solucao.totalCost, c, solucao.routes[r1], solucao.routes[r2], indice_cliente1, indice_cliente2);
                swapRoutes(solucao.rota_dem, d, solucao.routes[r1], solucao.routes[r2], indice_cliente1, indice_cliente2, r1, r2);
                //cout << "Depois de perturbar: "<< solucao.totalCost <<endl;
            }
        }
    }
    return solucao;
}

Solution ILS(Solution solucao_inicial, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution S0  = solucao_inicial;
    Solution S = vnd(S0, r, Q, L, d, p, c); // Busca local
    int cont = 0;

    while(cont <= 10){ // Pode ser até 10 vezes sem achar uma melhor solução ou um tempo máximo
        
        Solution S1 = pertubacao(S, Q, d, c); // Fazer perturbações na solução
        Solution S2 = vnd(S1, r, Q, L, d, p, c); // Busca local
        // Critério de Aceitação
        if(S2.totalCost < S.totalCost){
            S = S2;
        }else{
            cont++;
        }
    }
    return S;
}