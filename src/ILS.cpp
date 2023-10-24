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
    
    int num_rotas = solucao.routes.size(); //Colocar na struct a quantidade de rotas
    //cout << "Numero de rotas: " << num_rotas << endl;
    int custo_inicial = solucao.totalCost;

    for (int k = 0; k < num_rotas; k++){//Para cada rota


        for (int i = 0; i < 10; i++){ //Realiza 10 perturbações

            //10 SWAP entre rotas N5

            // Escolhe uma rota aleatória
            int r1 = rand() % num_rotas;
            int r2 = rand() % num_rotas;

            int cliente_1 = rand() % (solucao.route_size[r1]) + 1; 
            int cliente_2 = rand() % (solucao.route_size[r2]) + 1;

            //check if is possible to swap

            bool verifica = checkSwap2(Q,d, solucao.routes[r1], solucao.routes[r2], solucao.rota_dem, r1, r2, cliente_1,cliente_2);
            if (verifica){
            //Faz o swap Inter rotas

            //cria a structswapresult
            SwapResult result = custoSwapRoutes2(solucao.totalCost, Q, d, c, solucao.routes[r1], solucao.routes[r2], solucao.rota_dem, r1, r2);
            solucao.totalCost = result.total_cost;
            swapRoutes2(solucao.routes[r1], solucao.routes[r2], result.n1, result.n2, r1, r2, solucao.rota_dem, d);


            }







            /*  
            // Escolhe um cliente aleatório da rota
            //cout << "Tamanho da rotas: " << solucao.route_size[k] << endl;
            int random_i = rand() % (solucao.route_size[k]) + 1; //Subtrai 2 por causa do deposito
            int random_j = rand() % (solucao.route_size[k]) + 1; //Subtrai 2 por causa do deposito

            //cout << "Indices randomicos: " << random_i << " " << random_j << endl;
            
            //Calcula o novo custo da função objetivo
            int novo_custo = custoSwap(solucao.totalCost, c, solucao.routes[k], random_i, random_j);

            //Atualiza o custo
            solucao.totalCost = novo_custo;

            //Atualiza o vetor de rotas
            swapInside(solucao.routes[k], random_i, random_j);
            */
        }
    }
    
    cout << "Pertubei a solucao !!!" << endl;
    return solucao;
}

Solution ILS(Solution solucao_inicial, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution S0  = solucao_inicial;
    Solution S = vnd(S0, r, Q, L, d, p, c); // Busca local
    int cont = 0;

    cout << "Inicio do ILS" << endl;

    while(cont <= 10){ // Pode ser até 10 vezes sem achar uma melhor solução ou um tempo máximo
        
        cout << "cont: " << cont << endl;
        Solution S1 = pertubacao(S, Q, d, c); // Fazer perturbações na solução
        cout << "Pertubação: " << endl;
        //printSolution(S1);
        Solution S2 = vnd(S1, r, Q, L, d, p, c); // Busca local
        cout << "VND: " << endl;
        //printSolution(S1);
        // Critério de Aceitação
        if(S2.totalCost < S.totalCost){
            S = S2;
            cout << "Melhorou a solução" << endl;
        }else{
            cont++;
        }
    }

    cout << "Fim do ILS" << endl;

    return S;
}