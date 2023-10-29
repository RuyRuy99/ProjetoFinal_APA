#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;


void ReinsertionFunc(vector<vector<int>> c, vector<int> &rota1, int i, int j){

    // Define o cliente que será removido
    int cliente = rota1[i];
    // Remove o cliente na posição i da rota
    rota1.erase(rota1.begin() + i);
    // Insere o cliente na posição j da rota
    rota1.insert(rota1.begin() + j, cliente);
}

int costReinsertion(int total_cost, vector<vector<int>> c, vector<int> &rota, int i, int j){

    // Define o cliente que será reinserido
    int cliente = rota[i];
    // Variável para armazenar o custo das adições
    int adicoes = 0;
    // Variável para armazenar o custo das remoções
    int remocoes = 0; 

    // Se i == j, não precisa fazer reinserção
    if(i == j){ 
        return total_cost;
    
    // Se i - j == -1, inserindo uma posição a frente de onde foi removido
    }else if (i - j == -1){

        // No caso especial de distância 1, as posições i e j tem aresta entre elas, que não precisa ser removida
        remocoes = c[rota[j]][rota[j+1]] + c[rota[i]][rota[i-1]]; 
        adicoes = c[rota[i-1]][rota[j]] + c[rota[i]][rota[j+1]];
        total_cost = total_cost - remocoes + adicoes;
        return total_cost;
    
    // Se i - j == 1, inserindo uma posição atrás de onde foi removido
    }else if(i - j == 1){
        
        // No caso especial de distância 1, as posições i e j tem aresta entre elas, que não precisa ser removida
        remocoes = c[rota[i]][rota[i+1]] + c[rota[j]][rota[j-1]];
        adicoes = c[rota[j-1]][rota[i]] + c[rota[j]][rota[i+1]]; 
        total_cost = total_cost - remocoes + adicoes; 
        return total_cost;
    
    // Se i > j, inserindo mais de posição atrás de onde foi removido
    }else if(i > j){
        
        remocoes = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] + c[rota[j-1]][rota[j]]; 
        adicoes = c[rota[i-1]][rota[i+1]] + c[rota[j]][rota[i]] + c[rota[i]][rota[j-1]]; 
        total_cost = total_cost - remocoes + adicoes; 
        return total_cost;
    
    // Se i < j, inserindo mais de posição a frente de onde foi removido
    }else{
        
        remocoes = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] + c[rota[j]][rota[j+1]];
        adicoes = c[rota[i-1]][rota[i+1]] + c[rota[j]][rota[i]] + c[rota[i]][rota[j+1]];
        total_cost = total_cost - remocoes + adicoes; 
        return total_cost;
    }
}

Solution Reinsertion(Solution initial_solution, vector<vector<int>> c){

    // Inicializa a solução vizinha com a solução inicial
    Solution vizinha = initial_solution;

    // Variáveis para auxiliar a encontrar o minimo
    int min_custo_global = initial_solution.totalCost;
    int min_rota_idx = -1;
    int min_i_global = -1;
    int min_j_global = -1;

    int num_rotas = vizinha.routes.size();
   
    // Faz a busca exaustiva em cada rota
    for (int k = 0; k < num_rotas; k++){
        // Verificando todas as possibilidades de reinserção na rota k
        for (int i = 1; i < vizinha.routes[k].size()-1; i++){ // O(n)
            for (int j = 1; j < vizinha.routes[k].size()-1; j++){ // O(n)
                // O(n^2)
                // Calcula o custo da reinserção do cliente i na posição j da rota k
                int custo_aux = costReinsertion(vizinha.totalCost, c, vizinha.routes[k], i, j);
                // Se o custo da reinserção for menor que o custo da solução atual, atualiza a solução vizinha
                if(custo_aux < min_custo_global){
                    // Atualiza as variáveis auxiliares, salvando os indices da melhor reinserção
                    min_custo_global = custo_aux;
                    min_rota_idx = k;
                    min_i_global = i;
                    min_j_global = j;
                }
            }
        }
    }

    // Se encontrou uma solução melhor, faz a reinserção
    if(min_rota_idx != -1 && min_i_global != -1 && min_j_global != -1){
        ReinsertionFunc(c, vizinha.routes[min_rota_idx], min_i_global, min_j_global);
        vizinha.totalCost = min_custo_global;
        return vizinha;
    
    }else{
        return vizinha;
    }
}