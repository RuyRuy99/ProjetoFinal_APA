#include <iostream>
#include <vector>
#include <random>
#include "construtor.h"
#include "datatype.h"
#include <chrono>

using namespace std;

struct SwapResult { // Struct  para retornar o resultado do swap
    int total_cost; // Custo total
    int n1; // Indice do cliente 1
    int n2; // Indice do cliente 2
};

int findMaxCostVertex(vector<int> rota, vector<vector<int>> c){ 
    // Função para calcular o vertice de maior custo de uma rota (somamdo as arestas de entrada e saida)
    int vertice;
    int cost = 0;
    for (int i = 1; i < rota.size()-1; i++){
        //Itera sobre os vértices na rota, o custo de cada vértice é a soma das arestas de entrada e saida
        //cout << "Custo da aresta: (" << rota[i-1] << ","<< rota[i] << ")" << " = " << c[rota[i-1]][rota[i]] << endl;
        //cout << "Custo da aresta: (" << rota[i] << ","<< rota[i+1] << ")" << " = " << c[rota[i]][rota[i+1]] << endl;
        if(c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] > cost){
            // Atualiza quando acha um vértice com custo maior
            cost = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]];
            vertice = i;
        }
    }
    //cout << "FINAL DA CHAMADA\n" << endl;
    // Retorna a posição do vértice de maior custo
    //cout << "Vertice de maior custo = " << rota[vertice] << endl;
    return vertice;
}

bool checkSwap(int Q, vector<int> d, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j, int cliente1, int cliente2){
    int d1 = d[cliente1 - 1];
    int d2 = d[cliente2 - 1];

    int d_att_i = d_routs[i] - d1 + d2;
    int d_att_j = d_routs[j] - d2 + d1;

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

SwapResult custoSwapRoutes(int total_cost, int Q, vector<int> d, vector<int> p, vector<vector<int>> c, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j){
    //Calcula o custo para realizar a troca do cliente i com o cliente j e diz se a troca é viável ou não (se a demanda total da rota não ultrapassa a capacidade do carro)
    int n1 = findMaxCostVertex(v1, c); // Encontra o vértice de maior custo da rota 1
    int n2 = findMaxCostVertex(v2, c); // Encontra o vértice de maior custo da rota 2
    
    //Cria a estrutura do swap, setando os parâmetros	
    SwapResult result;
    result.total_cost = total_cost;
    result.n1 = n1;
    result.n2 = n2;

    //Define os clientes (pra olhar os custos depois), os anteriores e posteriores a eles
    int cliente1 = v1[n1];
    int cliente2 = v2[n2];
    int ant_i = v1[n1-1];
    int prox_i = v1[n1+1];
    int ant_j = v2[n2-1];
    int prox_j = v2[n2+1];
    
    bool check_status_swap = checkSwap(Q, d, v1, v2, d_routs, i, j, cliente1, cliente2);
    

    if(check_status_swap){//Calcula o custo total da solução quando a troca é viável
        //cout << "\n" << endl;
        //cout << "FAZENDO SWAP DO " << cliente1 << " COM O CLIENTE: " << cliente2 << endl;
        //cout << "O CUSTO ANTES DO SWAP EH: " << result.total_cost << endl;

        //Removendo os custos das arestas antigas
        result.total_cost -= c[ant_i][cliente1];
        result.total_cost -= c[cliente1][prox_i];

        result.total_cost -= c[ant_j][cliente2];
        result.total_cost -= c[cliente2][prox_j];

        //Somando os custos das novas arestas
        result.total_cost += c[ant_i][cliente2];
        result.total_cost += c[cliente2][prox_i];

        result.total_cost += c[ant_j][cliente1];
        result.total_cost += c[cliente1][prox_j];

        //cout << "O CUSTO DEPOIS DO SWAP EH: " << result.total_cost << endl;
        return result;
    }
    else{//Caso onde a troca não é viável
        //cout << "\n" << endl;
        //cout << "NAO pode fazer a troca. Status: " << status << endl;
        result.total_cost = -1;
        return result;
    }
}

void swapRoutes(vector<int> &v1, vector<int> &v2, int n1, int n2, int i, int j, vector<int> &d_routs, vector<int> d){

    //Define os clientes e as variáveis auxiliares
    int cliente1 = v1[n1];
    int cliente2 = v2[n2];
    int aux1 = cliente1;
    int aux2 = cliente2;

    //Atualiza os clientes nas rotas
    v1[n1] = aux2;
    v2[n2] = aux1;

    //Atualiza a demanda total da rota i
    d_routs[i] -= d[cliente1-1];
    d_routs[i] += d[cliente2-1];

    //Atualiza a demanda total da rota j
    d_routs[j] -= d[cliente2-1];
    d_routs[j] += d[cliente1-1];

}

Solution buscaExaustivaN2(Solution initial_solution, int Q, vector<int> d, vector<int> p, vector<vector<int>> c){

    Solution sol_vizinha = initial_solution;

    int num_rotas = sol_vizinha.routes.size();

    //Variáveis auxiliares
    int min_i = -1;
    int min_j = -1;
    int rota_i__idx = -1;
    int rota_j_idx = -1;
    int min_custo_global = initial_solution.totalCost;
    int initial_cost = initial_solution.totalCost;

    for (int i = 0; i < num_rotas; i++){//Para cada rota i
        for (int j= i+1; j < num_rotas; j++){ //Para cada rota j
            //cout << "\n" << endl;
            //cout << "CUSTO ATUAL: " << min_custo_global << endl;
            //cout << "SWAP DA ROTA " << i+1 << " COM A ROTA "<< j+1 << endl;

            //Calcula o custo do SWAP da rota i com a rota j
            //Não precisa passar o vetor de rotas, só o INT com a quantidade.
            SwapResult resultado = custoSwapRoutes(initial_cost, Q, d, p, c, sol_vizinha.routes[i], sol_vizinha.routes[j], sol_vizinha.rota_dem, i, j);
            //cout << "CUSTO DO SWAP: " << resultado.total_cost << endl;

            //Se o novo custo for melhor que o atual, concretiza o swap de i com j
            if (resultado.total_cost < min_custo_global && resultado.total_cost != -1){
                //cout << "Fazendo o swap" << endl;
                min_custo_global = resultado.total_cost;
                min_i = resultado.n1;
                min_j = resultado.n2;
                rota_i__idx = i;
                rota_j_idx = j;
            }
        }
    }

    //Atualizando os valores
    if (min_i != -1 && min_j != -1){
        //cout << "\n" << endl;
        //cout << "O SWAP COM MENOR CUSTO EH O DA ROTA " << rota_i__idx+1 << " COM A ROTA " << rota_j_idx+1 << endl;
        //cout << "FAZER O SWAP DO CLIENTE " << sol_vizinha.routes[rota_i__idx][min_i] << " COM O CLIENTE " << sol_vizinha.routes[rota_j_idx][min_j] << endl;
        //cout << "O CUSTO DO SWAP EH: " << min_custo_global << endl;
        swapRoutes(sol_vizinha.routes[rota_i__idx], sol_vizinha.routes[rota_j_idx], min_i, min_j, rota_i__idx, rota_j_idx, sol_vizinha.rota_dem, d);
        sol_vizinha.totalCost = min_custo_global;
    }
    else{
        //cout << "\n" << endl;
        //cout << "NÃO HÁ SWAP VIÁVEL" << endl;
    }
    return sol_vizinha; 
}

