#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;

int calcula_custo(const Solution* solucao, int k, const vector<int>& v, int i, const vector<int>& terc, int j, const InstanceData* dados) {
    int ant_i = v[i - 1];
    int prox_i = v[i + 1];
    int novo_custo = solucao->totalCost;

    // Verifica se a lista de terceirizados não está vazia
    if (!solucao->terceirizados.empty()) {
        // Custo das arestas que ligam i
        int custo_manter_i = dados->c[ant_i][v[i]] + dados->c[v[i]][prox_i];

        // Custo das arestas de ligação do terceirizado
        int custo_manter_terc = dados->c[ant_i][terc[j]] + dados->c[terc[j]][prox_i];

        // Verifica se cabe colocar o terceirizado no carro
        if ((solucao->rota_dem[k] - dados->d[v[i] - 1]) + dados->d[terc[j] - 1] <= dados->Q) {
            // Remove o custo do cliente i do custo total
            novo_custo -= custo_manter_i;
            // Adiciona o custo de terceirizar esse cliente
            novo_custo += dados->p[v[i] - 1];

            // Adiciona o custo do terceirizado no custo total
            novo_custo += custo_manter_terc;
            // Remove o custo de terceirizar esse cliente
            novo_custo -= dados->p[terc[j] - 1];
        }
    }

    return novo_custo;
}


void atualizaValores(vector<int>& v, int i, vector<int>& terc, int j, vector<int>& d, int* rota_demanda) {
    // Atualiza o valor da demanda da rota
    *rota_demanda = *rota_demanda - d[v[i] - 1] + d[terc[j] - 1];

    // Swap dos vetores
    int aux = v[i];
    v[i] = terc[j];
    terc[j] = aux;
}


Solution* SwapTerc(Solution* current_solution, InstanceData* dados) {

    int min_custo_global = current_solution->totalCost;
    int min_rota_idx = -1;
    int min_i = -1;
    int min_j = -1;

    int num_rotas = current_solution->routes.size();
    

    // Para cada rota
    for (int k = 0; k < num_rotas; k++) {
        // Para cada elemento da rota
        for (int i = 1; i < current_solution->routes[k].size() - 1; i++) { // O(n)
            // Percorrer os terceirizados
            for (int j = 0; j < current_solution->terceirizados.size(); j++) { // O(t), sendo t o número de terceirizados

                //O(n*t)
                // Calcula o novo custo
                
                int novo_custo = calcula_custo(current_solution, k, current_solution->routes[k], i, current_solution->terceirizados, j, dados);

                if (novo_custo < min_custo_global) {

                    min_custo_global = novo_custo;
                    min_rota_idx = k;
                    min_i = i;
                    min_j = j;
                }
            }
        }
    }

    // Se o custo global foi alterado, atualiza os valores
    if (min_rota_idx != -1) {
        atualizaValores(current_solution->routes[min_rota_idx], min_i, current_solution->terceirizados, min_j, dados->d, &current_solution->rota_dem[min_rota_idx]);
        current_solution->totalCost = min_custo_global;
    }

    return current_solution;
}
