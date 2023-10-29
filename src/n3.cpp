#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;

int calcula_custo(Solution solucao, int k, vector<int> v, int i, vector<int> terc, int j, int Q ,int L, vector<int> d, vector<int> p, vector<vector<int>> c){
    
    int ant_i = v[i-1];
    int prox_i = v[i+1];

    int novo_custo = solucao.totalCost;

    // Verifica se a lista de terceirizados não está vazia
    if (solucao.terceirizados.size() > 0){
        
        // Custo das arestas que ligam i
        int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];

        // Custo das arestas de ligação do terceirizado
        int custo_manter_terc = c[ant_i][terc[j]] + c[terc[j]][prox_i];

        // Verifica se cabe colocar o terceirizado no carro
        if ((solucao.rota_dem[k] - d[v[i]-1]) + d[terc[j]-1] <= Q){

            // Remove o custo do cliente i do custo total
            novo_custo -= custo_manter_i;
            // Adicionar o custo de terceirizar esse cliente
            novo_custo += p[v[i]-1];

            // Adiciona o custo do terceirizado no custo total
            novo_custo += custo_manter_terc;
            // Remover o custo de terceirizar esse cliente
            novo_custo -= p[terc[j]-1];
        }

    }

    return novo_custo;
}

void atualizaValores(vector<int> &v, int i, vector<int> &terc, int j, vector<int> d, int *rota_demanda){
    
    // Atualiza o valor da demanda da rota
    *rota_demanda = *rota_demanda - d[v[i]-1] + d[terc[j]-1];

    // Swap dos vetores
    int aux = v[i];
    v[i] = terc[j];
    terc[j] = aux;
}

Solution SwapTerc(Solution initial_solution, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution sol_vizinha = initial_solution;

    int min_custo_global = initial_solution.totalCost;
    int min_rota_idx = -1;
    int min_i = -1;
    int min_j = -1;

    int num_rotas = sol_vizinha.routes.size();

    // Para cada rota
    for (int k = 0; k < num_rotas; k++){
        // Para cada elemento da rota
        for (int i = 1; i < sol_vizinha.routes[k].size()-1; i++){ // O(n)
            // Percorrer os terceirizados
            for (int j = 0; j < sol_vizinha.terceirizados.size(); j++){ // O(t), sendo t o número de terceirizados

                //O(n*t)
                
                // Calcula o novo custo
                int novo_custo = calcula_custo(sol_vizinha, k, sol_vizinha.routes[k], i, sol_vizinha.terceirizados, j, Q, L, d, p, c);

                if (novo_custo < min_custo_global){

                    min_custo_global = novo_custo;
                    min_rota_idx = k;
                    min_i = i;
                    min_j = j;
                }
            }
        }
    }

    // Se o custo global foi alterado, atualiza os valores
    if (min_rota_idx != -1){

        atualizaValores(sol_vizinha.routes[min_rota_idx], min_i, sol_vizinha.terceirizados, min_j, d, &sol_vizinha.rota_dem[min_rota_idx]);
        sol_vizinha.totalCost = min_custo_global;
    }

    return sol_vizinha;
}
