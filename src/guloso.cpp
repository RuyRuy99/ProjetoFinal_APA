#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vizinho_prox(int i, int n, vector<vector<int>> c){

    int aux = c[i][0];
    int viz_prox = 0;
    for(int j=1; j<n; j++){
        if(c[i][j] < aux){
            aux = c[i][j];
            viz_prox = j;
    }}
    return viz_prox;
}

int algoritmo_guloso(int n, int k, int r, int Q, vector<vector<int>> c, vector<int> d){

    vector<int> solucao;
    vector<int> rotas;
    vector<int> rota_atual;
    vector<int> lst_clientes; // Não atendidos
    int atendidos;
    int result = 0;
    int uso_carro = 0;
    int viz_prox = 0;
    int dem_atual = 0;

    for(int i=1; i < k or lst_clientes.empty() == false; i++){
        solucao.push_back(0);
        int cliente_atual = 0;
        uso_carro = 1;
        while(lst_clientes.empty() == false){
            viz_prox = vizinho_prox(cliente_atual,n,c);
            // Verificar se o cliente está na lista de não atendidos
            if(dem_atual + d[viz_prox] <= Q){
                solucao.push_back(cliente_atual);
                cliente_atual = viz_prox;
                result += c[cliente_atual][viz_prox];
                lst_clientes.pop_back(cliente_atual); // Ver como fazer essa remoção
            }else{
                solucao.push_back(0);
                break; // Sair do loop
            }
        if(uso_carro == 1){
            result += r; // só se o carro foi usado
        }}
    }

    // Adicionar a terceirização aqui ou não ??

    return;
}