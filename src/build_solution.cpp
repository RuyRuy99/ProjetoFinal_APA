#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "datatype.h"

using namespace std;


Solution* buildSolution(const InstanceData* data){
    Solution* bestSolution = new Solution();
    bestSolution->totalCost = 0;

    vector<int> list_clientes;
    for (int i = 1; i <= data->n; i++) {
        list_clientes.push_back(i);
    }

    int clientes_att = 0;
    int cliente_atual = 0;
    int uso_carro = 0;
    int k = data->k;
    vector<int> rotas;

    while(k > 0 && !list_clientes.empty()) {
        int capacidade_carro = 0;
        int demanda_rota = 0;
        rotas.push_back(0);

        while(!list_clientes.empty() && capacidade_carro <= data->Q) {
            int custo_minimo = INT_MAX;
            int viz_prox = -1;
            int viz_idx = -1;

            for (int i = 0; i < list_clientes.size(); i++) {
                int cliente = list_clientes[i];
                int custo = data->c[cliente_atual][cliente];

                if (custo < custo_minimo && capacidade_carro + data->d[cliente-1] <= data->Q) {
                    custo_minimo = custo;
                    viz_prox = cliente;
                    viz_idx = i;
                }
            }

            if (viz_prox == -1) {
                break;  // Se não encontrar nenhum vizinho adequado, encerra a rota
            }

            rotas.push_back(viz_prox);
            bestSolution->totalCost += data->c[cliente_atual][viz_prox];
            capacidade_carro += data->d[viz_prox-1];
            cliente_atual = viz_prox;
            uso_carro = 1;
            demanda_rota += data->d[viz_prox-1];
            list_clientes.erase(list_clientes.begin() + viz_idx);
            clientes_att++;
        }

        if(uso_carro == 1) {
            bestSolution->totalCost += data->r;
        }

        bestSolution->rota_dem.push_back(demanda_rota);
        bestSolution->totalCost += data->c[cliente_atual][0];
        rotas.push_back(0);
        cliente_atual = 0;
        capacidade_carro = 0;
        bestSolution->routes.push_back(rotas);
        rotas.clear();
        uso_carro = 0;
        k--;
    }

    bestSolution->total_clientes = clientes_att;
    
    for(int cliente : list_clientes) {
        bestSolution->terceirizados.push_back(cliente);
    }

    if(clientes_att >= data->L) {
        for(int cliente : list_clientes) {
            bestSolution->totalCost += data->p[cliente - 1];
        }
    }

    return bestSolution;
}