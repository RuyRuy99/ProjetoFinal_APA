#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;

int calculaTerc(Solution* solucao, vector<int>& v, int i, InstanceData* dados) {
    int ant_i = v[i - 1];
    int prox_i = v[i + 1];
    int novo_custo = solucao->totalCost;

    // Verifica se pode terceirizar alguém
    if (solucao->total_clientes - 1 >= dados->L) {
        int custo_manter_i = dados->c[ant_i][v[i]] + dados->c[v[i]][prox_i];

        // Remove o custo de manter o cliente i do custo total
        novo_custo -= custo_manter_i;

        // Adiciona o custo da aresta de ligação
        novo_custo += dados->c[ant_i][prox_i];

        // Adiciona o custo de terceirizar o cliente i no custo total
        novo_custo += dados->p[v[i] - 1];
    }

    return novo_custo;
}

void updateRoutes(vector<int>& v, int i, Solution* solucao, InstanceData* dados) {
    // Remove a demanda do cliente que vai ser terceirizado
    solucao->rota_dem[i] -= dados->d[v[i] - 1];
        
    // Adiciona o cliente i na lista de terceirizados
    solucao->terceirizados.push_back(v[i]); // O(1)

    // Remove o cliente i da rota
    v.erase(v.begin() + i); // O(n) remove and shift

    // Diminuir a variável total_clientes porque tiramos um cliente da rota, logo não atendemos ele
    solucao->total_clientes -= 1;
}

Solution* remove(Solution* current_solution, InstanceData* dados) {
    // Inicializar variáveis para rastrear a melhor operação de terceirização.
    int min_custo_global = current_solution->totalCost;
    int min_rota_index = -1;
    int min_i = -1;

    int num_rotas = current_solution->routes.size();

    for (int k = 0; k < num_rotas; k++) {
        for (int i = 1; i < current_solution->routes[k].size() - 1; i++) { // O(n)
            // O(n)
            // Calcular o custo resultante de terceirizar o cliente
            int novo_custo = calculaTerc(current_solution, current_solution->routes[k], i, dados);

            // Se esta terceirização reduz o custo, consideramos ela como a melhor até agora.
            if (novo_custo < min_custo_global) {
                min_custo_global = novo_custo;
                min_rota_index = k;
                min_i = i;
            }
        }
    }

    // Depois de verificar todos os clientes em todas as rotas, se uma terceirização benéfica foi encontrada, realizamos essa única operação.
    if (min_rota_index != -1) {
        updateRoutes(current_solution->routes[min_rota_index], min_i, current_solution, dados);
        // Atualiza o custo total da solução
        current_solution->totalCost = min_custo_global;

        // Verifica se a demanda da rota é 0, se for, remove a rota (não há clientes)
        if (current_solution->rota_dem[min_rota_index] == 0) {
            // Remove o custo de um carro
            current_solution->totalCost -= dados->r;
            // Remove a rota vazia
            current_solution->routes.erase(current_solution->routes.begin() + min_rota_index); // O(n) remove and shift
            // Remove a demanda da rota vazia
            current_solution->rota_dem.erase(current_solution->rota_dem.begin() + min_rota_index); // O(n) remove and shift
        }
    }

    return current_solution;
}

