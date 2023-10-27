#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;


void ReinsertionFunc(vector<vector<int>> c, vector<int> &rota1, int i, int j){
    
    int cliente = rota1[i];
    rota1.erase(rota1.begin() + i);
    rota1.insert(rota1.begin() + j, cliente);
}

int costReinsertion(int total_cost, vector<vector<int>> c, vector<int> &rota, int i, int j){
    
    int cliente = rota[i];
    int adicoes = 0;
    int remocoes = 0;

    if( i == j){
        return total_cost;
    
    }else if (i - j == -1){

        remocoes = c[rota[j]][rota[j+1]] + c[rota[i]][rota[i-1]];
        adicoes = c[rota[i-1]][rota[j]] + c[rota[i]][rota[j+1]];
        total_cost = total_cost - remocoes + adicoes;
        return total_cost;
    
    }else if(i - j == 1){

        remocoes = c[rota[i]][rota[i+1]] + c[rota[j]][rota[j-1]];
        adicoes = c[rota[j-1]][rota[i]] + c[rota[j]][rota[i+1]];
        total_cost = total_cost - remocoes + adicoes;
        return total_cost;
    
    }else if(i > j){

        remocoes = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] + c[rota[j-1]][rota[j]];
        adicoes = c[rota[i-1]][rota[i+1]] + c[rota[j]][rota[i]] + c[rota[i]][rota[j-1]];
        total_cost = total_cost - remocoes + adicoes;
        return total_cost;
    
    }else{

        remocoes = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] + c[rota[j]][rota[j+1]];
        adicoes = c[rota[i-1]][rota[i+1]] + c[rota[j]][rota[i]] + c[rota[i]][rota[j+1]];
        total_cost = total_cost - remocoes + adicoes;
        return total_cost;
    }
}

Solution buscaExaustivaN2(Solution initial_solution, vector<vector<int>> c){

    Solution vizinha = initial_solution;

    // Variáveis para auxiliar a encontrar o minimo
    int min_custo_global = initial_solution.totalCost;
    int min_rota_idx = -1;
    int min_i_global = -1;
    int min_j_global = -1;

    int num_rotas = vizinha.routes.size();

    for (int k = 0; k < num_rotas; k++){
        for (int i = 1; i < vizinha.routes[k].size()-1; i++){
            for (int j = 1; j < vizinha.routes[k].size()-1; j++){
                int custo_aux = costReinsertion(vizinha.totalCost, c, vizinha.routes[k], i, j);
                if(custo_aux < min_custo_global){
                    min_custo_global = custo_aux;
                    min_rota_idx = k;
                    min_i_global = i;
                    min_j_global = j;
                }
            }
        }
    }
    
    if(min_rota_idx != -1){
        ReinsertionFunc(c, vizinha.routes[min_rota_idx], min_i_global, min_j_global);
        vizinha.totalCost = min_custo_global;
        return vizinha;
    }
    
    return vizinha;
}