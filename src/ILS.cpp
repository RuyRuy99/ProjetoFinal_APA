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

struct SwapResult { // Struct  para retornar o resultado do swap
    int total_cost; // Custo total
    int idx_cliente1; // Indice do cliente 1
    int idx_cliente2; // Indice do cliente 2
};

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

            int indice_cliente1 = rand() % (solucao.route_size[r1]) + 1; 
            int indice_cliente2 = rand() % (solucao.route_size[r2]) + 1;
            
            if(r1 != r2){
                int cliente_1 = solucao.routes[r1][indice_cliente1];
                int cliente_2 = solucao.routes[r2][indice_cliente2];

                cout << "\n" << endl;
                cout << "Verificando o swap da rota " << r1 +1<< " com a rota " << r2+1 << endl;
                cout << "Os cliente analisados: " << cliente_1 << " e " << cliente_2 << endl;

                bool verifica = checkSwap(Q, d, solucao.rota_dem, r1, r2, cliente_1, cliente_2);

                cout << "Status: " << verifica << endl;

                if (verifica){
                //Faz o swap Inter rotas
                //cria a structswapresult
                    cout << "\n" << endl;
                    cout << "Fazendo o swap entre as rotas: " << r1+1 << " e " << r2+1 << endl;
                    cout << "Os clientes escolhidos foram: " << cliente_1 << " e " << cliente_2 << endl;
                    cout << "Os indices escolhidos foram: " << indice_cliente1 << " e " << indice_cliente2 << endl;
                    cout << "Antes de perturbar: "<< solucao.totalCost <<endl;
                    solucao.totalCost = CaculaCustoSwap(solucao.totalCost, c, solucao.routes[r1], solucao.routes[r2], indice_cliente1, indice_cliente2);
                    swapRoutes(solucao.rota_dem, d, solucao.routes[r1], solucao.routes[r2], indice_cliente1, indice_cliente2, r1, r2);
                    cout << "Depois de perturbar: "<< solucao.totalCost <<endl;
                }
                else{
                    cout << "\n" << endl;
                    cout << "Não pode fazer o swap entre as rotas: " << r1 << " e " << r2 << endl;
                    //cout << "Os clientes escolhidos foram: " << cliente_1 << " e " << cliente_2 << endl;
                }
            }
            //check if is possible to swap
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