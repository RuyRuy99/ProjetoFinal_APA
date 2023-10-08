#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <utility>
#include <tuple>
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

    vector<int> list_clientes;
    //Cria lista de clientes não atendidos
    for (int i = 1; i < (n+1); i++){
        list_clientes.push_back(i);
    }




    int clintes_att = 0;
    int uso_carro = 0;
    int cliente_atual = 0;
    vector<int> rotas;


    while (k > 0){

        cout << "Clientes lista: ";
        for (int i = 0; i < list_clientes.size(); i++){
            cout << list_clientes[i] << " ";
        }
        cout << endl;

        cout << "Rota: ";
        for (int i = 0; i < rotas.size(); i++){
            cout << rotas[i] << " ";
        }
        cout << endl;





        int capacidade_carro = 0;
        //inicia a rota no deposito
        rotas.push_back(0);

        while (list_clientes.empty() == false){ //capacidade_carro <= Q
            //procura o vizinho mais proximo do cliente atual
            int viz_prox,viz_idx;
            tie(viz_prox, viz_idx) = guloso(cliente_atual, n, c, list_clientes);
            //cout << "Vizinho e index " << viz_prox << " " << viz_idx << endl;

            //verifica se é possível levar no carro
            if(capacidade_carro + d[viz_prox-1] <= Q){
                cout << "Fui do cliente " << cliente_atual << " para o cliente " << viz_prox << "  demanda: " << d[viz_prox-1] << endl;
                rotas.push_back(viz_prox);
                capacidade_carro += d[viz_prox-1];
                cliente_atual = viz_prox;
                //remove o cliente visitado
                list_clientes.erase(list_clientes.begin() + viz_idx);
                clintes_att++;
            }
        }
        rotas.push_back(0);
        
        cliente_atual = 0;
        k --;
    }
}












    /*

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

    


*/
