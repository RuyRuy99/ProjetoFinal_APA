#include <iostream>
#include <vector>
#include <string>
#include "construtor.h"

using namespace std;

int buildSolution(int n, int k, int r, int Q, vector<vector<int>> c, vector<int> d){

    vector<int> rotas;
    int lst_clientes[n] = {0,0,0,0,0,0};
    int atendidos;
    int result = 0;
    int uso_carro = 0;
    int viz_prox = 0;
    int dem_atual = 0;
    int cliente_atual = 0;

    for(int i=1; i < k or lst_clientes == NULL; i++){
        //solucao.push_back(0);
        int solucao[] = {};
        uso_carro = 1;
        while(lst_clientes == NULL){
            viz_prox = guloso();
            if(lst_clientes[cliente_atual] == 0){
                if(dem_atual + d[viz_prox] <= Q){
                    solucao.append(cliente_atual);
                    cliente_atual = viz_prox;
                    result += c[cliente_atual][viz_prox];
                    lst_clientes[cliente_atual] == 1; // Atualizar a lst de clientes
                }else{
                    solucao.append(0);
                    break; // Sair do loop
                }
            }
        if(uso_carro == 1){
            result += r; // só se o carro foi usado
        }}}

        rotas.push_back(solucao);
    }

    // Adicionar a terceirização aqui

    return result, rotas;
}