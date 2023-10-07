#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "guloso.h"
#include "terceirizacao.h"

using namespace std;

struct Solution{
    vector<vector<int>> routes;
    int totalCost;
};

Solution buildSolution(int n, int k, int r, int Q, vector<vector<int>> c, vector<int> d, vector<int> p) {
    
    Solution bestSolution;
    bestSolution.totalCost = 0;

    vector<int> lst_clientes(n, 0);

    int atendidos = 0;
    int uso_carro = 0;
    int cliente_atual = 0;
    int cap_carro = Q;

    //ERRO: lst não tá vazia nunca vai ser false
    for(int i=1; i <= k or lst_clientes.empty() == true; i++){
        vector<int> solucao;
        int dem_atual = 0;
        int cap_carro = Q;
        
        // Ver como verificar a lista de clientes não atendidos

        solucao.push_back(0);

        while(lst_clientes.empty() == false){ //ERRO: lst não tá vazia nunca vai ser true
            int viz_prox = guloso(cliente_atual, n, c);
            cout << "viz_prox: " << viz_prox << endl;

            // Verificar se o cliente já foi atendido e a demanda não ultrapassa a capacidade
            if(lst_clientes[viz_prox-1] == 0 && dem_atual + d[viz_prox-1] <= cap_carro){
                solucao.push_back(viz_prox); //add cliente na solução
                bestSolution.totalCost += c[cliente_atual][viz_prox+1];
                cap_carro -= d[viz_prox-1];
                cliente_atual = viz_prox;
                lst_clientes[cliente_atual-1] = 1; // Atualizar a lst de clientes
                dem_atual += d[viz_prox-1];
            }else{
                solucao.push_back(0);
                bestSolution.totalCost += c[cliente_atual][0];
                uso_carro = 1;
                bestSolution.totalCost += dem_atual;
                break; // Sair do loop
            }
        }

        if (uso_carro == 1) {
            bestSolution.totalCost += r; // só se o carro foi usado
        }

        cout << "custo: " << bestSolution.totalCost << endl;
        bestSolution.routes.push_back(solucao);
    }

    //ERRO: Rever como verificar se o cliente já foi atendido
    // Adicionar a terceirização aqui
    int terc = terceirizacao(lst_clientes,bestSolution.totalCost,p);
    bestSolution.totalCost += terc;

    return bestSolution; // Rotas e Custo total
}
