#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include "guloso.h"
#include "readfile.h"
#include "showsolution.h"
#include "datatype.h"

using namespace std;

Solution buildSolution(int n, int k, int r, int Q,  int L, vector<vector<int>> c, vector<int> d, vector<int> p){
    
    // Inicialização da Struct
    Solution bestSolution;
    bestSolution.totalCost = 0;

    // Cria lista de clientes não atendidos
    vector<int> list_clientes;
    for (int i = 1; i < (n+1); i++){
        list_clientes.push_back(i);
    }

    int clintes_att = 0;
    int cliente_atual = 0;
    int uso_carro = 0;
    vector<int> rotas;

    while(k > 0 and list_clientes.empty() == false){ // Verifica se ainda possui carro disponível e se a lista de clientes não está vazia

        int capacidade_carro = 0;
        int demanda_rota = 0;
        rotas.push_back(0);

        while(list_clientes.empty() == false && capacidade_carro <= Q){ // Verifica se a lista de clientes está vazia e o carro possui capacidade
            
            int viz_prox,viz_idx;
            tie(viz_prox, viz_idx) = guloso(cliente_atual, c, list_clientes); // Encontra o vizinho mais próximo

            if(capacidade_carro + d[viz_prox-1] <= Q){ // Verifica se a demanda do cliente não ultrapassa a capacidade do carro
    
                //Adiciona o cliente na rota
                rotas.push_back(viz_prox);
                //Adiciona o custo da rota
                bestSolution.totalCost += c[cliente_atual][viz_prox];
                //Atualiza a capacidade do carro atual
                capacidade_carro += d[viz_prox-1];
                //Atualiza o cliente atual
                cliente_atual = viz_prox;
                //Atualiza flag de uso do carro
                uso_carro = 1;
                //Atualiza a demanda da rota
                demanda_rota += d[viz_prox-1];
                //remove o cliente visitado
                list_clientes.erase(list_clientes.begin() + viz_idx);
                //Atualiza var de clientes atendidos pelos carros
                clintes_att++;
            
            }
            else{
                break; // Saída do loop
            }
        }

        // Adicionando o custo do carro
        if(uso_carro == 1){
            bestSolution.totalCost += r;
        }

        //Adiciona a demanda de cada rota no vetor
        bestSolution.rota_dem.push_back(demanda_rota);        
        //Adiciona o custo de retornar ao deposito
        bestSolution.totalCost += c[cliente_atual][0];
        //Adiciona o deposito no final da rota
        rotas.push_back(0);
        //Reseta o cliente atual
        cliente_atual = 0;
        //Reseta a capacidade do carro
        capacidade_carro = 0;
        //Adiciona a rota no vetor de rotas
        bestSolution.routes.push_back(rotas);
        // Limpa o vetor de rotas
        rotas.clear();
        //Reseta a flag de uso do carro
        uso_carro = 0;
        //Atualiza o numero de carros disponiveis
        k--;
    }

    //adiciona a quantidade total de clientes atendidos na solução
    bestSolution.total_clientes = clintes_att;

    //adiciona o tamanho do vetor de terceirizados
    //int terc_size = n - clintes_att;
    //bestSolution.terc_size = terc_size;

    // Percorre a lista de clientes não atendidos e dá push na solução em terceirizados
    for(int i=0; i<list_clientes.size(); i++){
        bestSolution.terceirizados.push_back(list_clientes[i]);
    }

    //   -- TERCEIRIZAÇÃO --
    // Verificar se o minimo de entregas foi realizados para poder terceirizar as restantes
    if(clintes_att >= L){

        // Adicionando a terceirização
        for(int i=0; i<list_clientes.size(); i++){
            bestSolution.totalCost += p[list_clientes[i] - 1];
        }
    }

    return bestSolution;
}



