#include <iostream>
#include <vector>
#include <random>
#include "construtor.h"
#include "datatype.h"
#include <chrono>

using namespace std;

bool checkSwap(int Q, vector<int> d, vector<int> &rota_dem, int rota_i, int rota_j, int cliente1, int cliente2){
    int d1 = d[cliente1 - 1]; // Demanda do cliente 1
    int d2 = d[cliente2 - 1]; // Demanda do cliente 2

    int d_att_i = rota_dem[rota_i] - d1 + d2; // Demanda atualizada da rota i
    int d_att_j = rota_dem[rota_j] - d2 + d1; // Demanda atualizada da rota j

    //Avalia qual cliente tem demanda maior e se é possível atender a essa demanda
    if (d1 > d2) {
        if (d_att_j > Q) {
            return false;
        }
    }
    else if (d2 > d1) {
        if (d_att_i > Q) {
            return false;
        }
    }

    return true;
}


int CaculaCustoSwap(int total_cost, vector<vector<int>> c, vector<int> &rota1, vector<int> &rota2, int idx_cliente_i, int idx_cliente_j){
    //Define os clientes
    int cliente_i = rota1[idx_cliente_i];
    int cliente_j = rota2[idx_cliente_j];
    
    //Define os clientes adjacentes ao cliente i
    int ant_cliente_i = rota1[idx_cliente_i - 1];
    int prox_cliente_i = rota1[idx_cliente_i + 1];
    
    //Define os clientes adjacentes ao cliente j
    int ant_cliente_j = rota2[idx_cliente_j - 1];
    int prox_cliente_j = rota2[idx_cliente_j + 1];

    //Calcula o custo das remoções e das adições
    int remocoes = c[ant_cliente_i][cliente_i] + c[cliente_i][prox_cliente_i] + c[ant_cliente_j][cliente_j] + c[cliente_j][prox_cliente_j];
    int adicoes = c[ant_cliente_i][cliente_j] + c[cliente_j][prox_cliente_i] + c[ant_cliente_j][cliente_i] + c[cliente_i][prox_cliente_j];
    
    //Retorna o custo total atualizado
    return total_cost - remocoes + adicoes;
}


void swapRoutes(vector<int> &rota_dem, vector<int> d, vector<int> &v1, vector<int> &v2, int idx_cliente1, int idx_cliente2, int rota_i, int rota_j){

    //Define os clientes e as variáveis auxiliares
    int cliente1 = v1[idx_cliente1];
    int cliente2 = v2[idx_cliente2];
    int aux1 = cliente1;
    int aux2 = cliente2;

    //Atualiza os clientes nas rotas
    v1[idx_cliente1] = aux2;
    v2[idx_cliente2] = aux1;

    //Atualiza a demanda total da rota i
    rota_dem[rota_i] -= d[cliente1-1];
    rota_dem[rota_i] += d[cliente2-1];

    //Atualiza a demanda total da rota j
    rota_dem[rota_j] -= d[cliente2-1];
    rota_dem[rota_j] += d[cliente1-1];

}


Solution SwapInter(Solution initial_solution, int Q, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution sol_vizinha = initial_solution;

    //Variáveis auxiliares
    int best_cliente_i = -1;
    int best_cliente_j = -1;
    int rota_i_idx = -1;
    int rota_j_idx = -1;
    int min_custo_global = initial_solution.totalCost;
    int initial_cost = initial_solution.totalCost;

    int num_rotas = sol_vizinha.routes.size();
    //cout << "Tamanho de rotas: " << num_rotas <<endl;

    //Para cada par i e j de rotas
    for (int rota_i = 0; rota_i < num_rotas; rota_i++){
        for (int rota_j = rota_i + 1; rota_j < num_rotas; rota_j++){
            //Para cada cliente i e j, nas rotas i e j
            for(int idx_cliente_i = 1; idx_cliente_i < sol_vizinha.routes[rota_i].size() - 1; idx_cliente_i++){ //Para cada cliente i
                for(int idx_cliente_j = 1; idx_cliente_j < sol_vizinha.routes[rota_j].size() - 1; idx_cliente_j++){ //Para cada cliente j
                    //Verifica se é possível fazer o swap
                    bool check = checkSwap(Q, d, sol_vizinha.rota_dem, rota_i, rota_j, sol_vizinha.routes[rota_i][idx_cliente_i], sol_vizinha.routes[rota_j][idx_cliente_j]);
                    
                    //Se for possível fazer o swap, calcula o custo do swap
                    if(check){
                        //Calcula o custo do swap
                        int custo_aux = CaculaCustoSwap(initial_cost, c, sol_vizinha.routes[rota_i], sol_vizinha.routes[rota_j], idx_cliente_i, idx_cliente_j);
                        
                        //Atualiza o melhor custo, e salva os indices do melhor swap
                        if(custo_aux < min_custo_global){
                            best_cliente_i = idx_cliente_i;
                            best_cliente_j = idx_cliente_j;
                            rota_i_idx = rota_i;
                            rota_j_idx = rota_j;
                            min_custo_global = custo_aux;
                        }
                    }
                }
            }
        }
    }

    //Se encontrou uma solução melhor, faz o swap
    if (best_cliente_i != -1 && best_cliente_j != -1){
        swapRoutes(sol_vizinha.rota_dem, d, sol_vizinha.routes[rota_i_idx], sol_vizinha.routes[rota_j_idx], best_cliente_i, best_cliente_j, rota_i_idx, rota_j_idx);
        sol_vizinha.totalCost = min_custo_global;
    }
    return sol_vizinha; 
}