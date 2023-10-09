#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include "guloso.h"
#include "readfile.h"
#include "terceirizacao.h"

using namespace std;

struct Solution{
    vector<vector<int>> routes;
    int totalCost = 0;
};

Solution buildSolution(int n, int k, int r, int Q, vector<vector<int>> c, vector<int> d, vector<int> p) {
    
    Solution bestSolution;

    vector<int> list_clientes;
    //Cria lista de clientes não atendidos
    for (int i = 1; i < (n+1); i++){
        list_clientes.push_back(i);
    }

    int clintes_att = 0;
    int uso_carro = 0;
    int cliente_atual = 0;
    
    vector<int> rotas;

    while(k > 0 and list_clientes.empty() == false){

        int capacidade_carro = 0;
        //inicia a rota no deposito
        rotas.push_back(0);

        while(list_clientes.empty() == false && capacidade_carro <= Q){ //capacidade_carro <= Q
            
            int viz_prox,viz_idx;
            tie(viz_prox, viz_idx) = guloso(cliente_atual, c, list_clientes);

            if(capacidade_carro + d[viz_prox-1] <= Q){
                cout << "Fui do cliente " << cliente_atual << " para o cliente " << viz_prox << "  demanda: " << d[viz_prox-1] << " Custo:" <<   c[cliente_atual][viz_prox]  << endl;
                rotas.push_back(viz_prox);

                bestSolution.totalCost += c[cliente_atual][viz_prox];
                
                capacidade_carro += d[viz_prox-1];
                cliente_atual = viz_prox;
                uso_carro = 1;

                //tamanho da lista de clientes
                //cout << "Tamanho da lista de clientes: " << list_clientes.size() << endl;
                //cout << "Clientes lista: ";
                //print_array(&list_clientes[0], list_clientes.size());

                //remove o cliente visitado
                list_clientes.erase(list_clientes.begin() + viz_idx);
                clintes_att++;
                
            }
            else{
                break;
            }
        }

        if(uso_carro == 1){
            bestSolution.totalCost += r;
            cout << "best + carro: " << bestSolution.totalCost << endl;
        }
        cout << "cliente atual: " << cliente_atual << endl;
        cout << "custo de retorno ao deposito: " << c[cliente_atual][0] << endl;
        bestSolution.totalCost += c[cliente_atual][0];
        cout << "Custo total da rota: " << bestSolution.totalCost << endl;
        rotas.push_back(0);
        cliente_atual = 0;
        capacidade_carro = 0;
        //adiciona a rota na bestSolution
        bestSolution.routes.push_back(rotas);
        //limpa a rota
        rotas.clear();
        k--;
        uso_carro = 0;
    }

    //bestSolution size
    cout << "BestSolution size: " << bestSolution.routes.size() << endl;

    int rotaNumber = 1; // contador para identificar o número da rota
    for (int i = 0; i < bestSolution.routes.size();i++) {
        cout << "Rota " << rotaNumber << ": ";
        print_array(&bestSolution.routes[i][0], bestSolution.routes[i].size());
        cout << endl;
        rotaNumber++;
    }
    
    //mostra lista clientes
    cout << "Clientes lista: ";
    print_array(&list_clientes[0], list_clientes.size());

    //terceirização
    int custo_terceirizacao = terceirizacao(list_clientes, p);
    //update bestSolution
    bestSolution.totalCost += custo_terceirizacao;
    

    cout << "Custo total: " << bestSolution.totalCost << endl;
}
