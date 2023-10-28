#include <iostream>
#include <vector>
#include "datatype.h"
#include "readfile.h"
#include "showsolution.h"

using namespace std;

int calculaTerc(Solution solucao, vector<int> &v, int i, int clientes_atendidos, int L, vector<int> p, vector<vector<int>> c){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int novo_custo = solucao.totalCost;

    // Verifica se pode terceirizar alguém
    if (clientes_atendidos-1 >= L){

        int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];

        // Remove o custo de manter o cliente i do custo total
        novo_custo -= custo_manter_i;

        // Adiciona o custo da aresta de ligação
        novo_custo += c[ant_i][prox_i];

        // Adiciona o custo de terceirizar o cliente i no custo total
        novo_custo += p[v[i]-1];
    }

    return novo_custo;
}

void updateRoutes(vector<int> &v, int i, int *clientes_atendidos, int *rota_demanda,vector<int> &terc, vector<int> d){

    // Remove a demanda do cliente que vai ser terceirizado
    *rota_demanda = *rota_demanda - d[v[i]-1];
        
    // Adiciona o cliente i na lista de terceirizados
    terc.push_back(v[i]); //O(1)

    // Remove o cliente i da rota
    v.erase(v.begin()+i); //O(n) remove and shift

    // Diminuir a variavel client_att pq eu tirei um cliente da rota, logo não atendi ele
    *clientes_atendidos -= 1;
}


Solution Remove(Solution initial_solution, int r, int L, vector<int> d, vector<int> p, vector<vector<int>> c){
    
    // Inicia a solução vizinha
    Solution sol_vizinha = initial_solution;

    // Inicializar variáveis para rastrear a melhor operação de terceirização.
    int min_custo_global = initial_solution.totalCost;
    int min_rota_index = -1;
    int min_i = -1;

    int num_rotas = sol_vizinha.routes.size();

    for (int k = 0; k < num_rotas; k++){  
        for (int i = 1; i < sol_vizinha.routes[k].size()-1; i++){ //O(n)
            // O(n)
            // Calcular o custo resultante de terceirizar o cliente
            int novo_custo = calculaTerc(sol_vizinha, sol_vizinha.routes[k], i, sol_vizinha.total_clientes, L, p, c);

            // Se esta terceirização reduz o custo, consideramos ela como a melhor até agora.
            if (novo_custo < min_custo_global){

                min_custo_global = novo_custo;
                min_rota_index = k;
                min_i = i;
            }
        }
    }


    // Depois de verificar todos os clientes em todas as rotas, se uma terceirização benéfica foi encontrada, realizamos essa única operação.
    if(min_rota_index != -1){

        updateRoutes(sol_vizinha.routes[min_rota_index], min_i, &sol_vizinha.total_clientes,&sol_vizinha.rota_dem[min_rota_index], sol_vizinha.terceirizados, d);
        // Atualiza o custo total da solução
        sol_vizinha.totalCost = min_custo_global;
        
        // Verifica se a demanda da rota é 0, se for, remove a rota (não há clientes)
        if(sol_vizinha.rota_dem[min_rota_index] == 0){

            // Remove o custo de um carro
            sol_vizinha.totalCost -= r;
            // Remove a rota vazia
            sol_vizinha.routes.erase(sol_vizinha.routes.begin()+min_rota_index); //O(n) remove and shift
            // Remove a demanda da rota vazia
            sol_vizinha.rota_dem.erase(sol_vizinha.rota_dem.begin()+min_rota_index); //O(n) remove and shift
        }
    }

    return sol_vizinha;
}
