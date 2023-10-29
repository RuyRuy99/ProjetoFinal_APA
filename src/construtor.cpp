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
        list_clientes.push_back(i); //O(1)
    }

    int clintes_att = 0;
    int cliente_atual = 0;
    int uso_carro = 0;
    vector<int> rotas;

    // Verifica se ainda possui carro disponível e se a lista de clientes não está vazia
    while(k > 0 and list_clientes.empty() == false){

        int capacidade_carro = 0;
        int demanda_rota = 0;
        rotas.push_back(0); // O(1)

        // Verifica se a lista de clientes está vazia e o carro possui capacidade
        while(list_clientes.empty() == false && capacidade_carro <= Q){
            
            int viz_prox,viz_idx;
            // Encontra o vizinho mais próximo
            tie(viz_prox, viz_idx) = guloso(cliente_atual, c, list_clientes);

            // Verifica se a demanda do cliente não ultrapassa a capacidade do carro
            if(capacidade_carro + d[viz_prox-1] <= Q){
    
                // Adiciona o cliente na rota
                rotas.push_back(viz_prox); // O(1)
                // Adiciona o custo da rota
                bestSolution.totalCost += c[cliente_atual][viz_prox];
                // Atualiza a capacidade do carro atual
                capacidade_carro += d[viz_prox-1];
                // Atualiza o cliente atual
                cliente_atual = viz_prox;
                // Atualiza flag de uso do carro
                uso_carro = 1;
                // Atualiza a demanda da rota
                demanda_rota += d[viz_prox-1];
                // Remove o cliente visitado
                list_clientes.erase(list_clientes.begin() + viz_idx); // O(n) remove and shift
                // Atualiza var de clientes atendidos pelos carros
                clintes_att++;
            
            }else{
                break; // Saída do loop
            }
        }

        // Adicionando o custo do carro
        if(uso_carro == 1){
            bestSolution.totalCost += r;
        }

        // Adiciona a demanda de cada rota no vetor
        bestSolution.rota_dem.push_back(demanda_rota);// O(1) just push a number in a vector 
        // Adiciona o custo de retornar ao deposito
        bestSolution.totalCost += c[cliente_atual][0];
        // Adiciona o deposito no final da rota
        rotas.push_back(0); // O(1)
        // Reseta o cliente atual
        cliente_atual = 0;
        // Reseta a capacidade do carro
        capacidade_carro = 0;
        // Adiciona a rota no vetor de rotas
        bestSolution.routes.push_back(rotas); // O(n), n sendo o tamanho da rota, pois há uma cópia
        // Limpa o vetor de rotas
        rotas.clear(); //O(n) , destroi os n elementos da rota
        // Reseta a flag de uso do carro
        uso_carro = 0;
        // Atualiza o numero de carros disponiveis
        k--;
    }

    // Adiciona a quantidade total de clientes atendidos na solução
    bestSolution.total_clientes = clintes_att;

    // Percorre a lista de clientes não atendidos e dá push na solução em terceirizados
    for(int i=0; i<list_clientes.size(); i++){
        bestSolution.terceirizados.push_back(list_clientes[i]); // O(1), mas roda n vezes, logo O(n)
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



