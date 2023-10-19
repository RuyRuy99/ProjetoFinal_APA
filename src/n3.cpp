#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;

int melhora_rotas(int Q ,int L, vector<int> d, vector<vector<int>> c, vector<int> &v, int i, vector<int> &terc, int j, int *terc_size, int *total_cost, int *rota_demanda){

    int ant_i = v[i-1];
    int prox_i = v[i+1];

    int novo_custo = *total_cost;
    
    // Verifica se a lista de terceirados não está vazia para poder fazer o swap
    if (*terc_size > 0){
        //print_array(&terc[0], terc.size());
        // Custo das arestas de ligação do cliente i
        int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];

        // Custo das arestas de ligação do cliente tercerizado
        int manter_terc_j = c[ant_i][terc[j]] + c[terc[j]][prox_i];

        cout << "Custo de manter o cliente: " << v[i] << " = " << custo_manter_i << endl;
        cout << "Custo de manter o terceirizado: " << terc[j] << " = "<< manter_terc_j <<endl;

        // Verifica se quando diminuir a demanda do cliente i e depois adicionar o terceirizado, é <= que a capacidade do carro
        if ((*rota_demanda - d[v[i]-1]) + d[terc[j]-1] <= Q) {
            //cout << "Vou fazer o SWAP"<<endl;
            // Remove o custo de manter o cliente i do custo total
            novo_custo -= custo_manter_i;
            //cout << "Custo depois de remover i: " << *total_cost << endl;

            // Adiciona o custo de manter o terceirizado no custo total
            novo_custo += manter_terc_j;         

            // OBS: Como estou fazendo um swap de um terceirizado com rota não precisa decrementar o clientes_att
        }
    }
    return novo_custo;
}

void atualizaValores(vector<int> &v, int i,vector<int> &terc, int j, vector<int> d, int *rota_demanda){

    // Atualiza a demanda da rota
    *rota_demanda = *rota_demanda - d[v[i]-1] + d[terc[j]-1];

    //Swap between vectors
    int aux = v[i];
    v[i] = terc[j];
    terc[j] = aux;
    //Obs: Não preciso atualizar o terc_size pq o tamanho do vetor de terceirizados não muda
}




void buscaExaustivaN3(int Q ,int L, int *total_cost, int *terc_size, int *total_clientes, vector<int> d, vector<int> p, vector<vector<int>> c, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &rota_dem){
    
    int num_rotas = routes.size();
    cout << "Quantidade de rotas == " << num_rotas << endl;

    for (int k = 0; k < num_rotas; k++){ // Para cada rota
        int rota_atual_size = routes[k].size();
        cout << "Rota " << k+1 << endl;
        for (int i = 1; i < rota_atual_size-1; i++){ // Percorrer os vetores da rota
            for (int j = 0; j < *terc_size; j++){ //Percorre cada elemento terceirizado


                int custo_atual = *total_cost;
                cout << "Custo atual = " << custo_atual << endl;

                int novo_custo = melhora_rotas(Q, L, d, c, routes[k], i, terceirizados, j, terc_size, total_cost, &rota_dem[k]);
                cout << "Custo novo = " << novo_custo << endl;

                if (novo_custo < custo_atual){
                    atualizaValores(routes[k], i, terceirizados, j, d, &rota_dem[k]);
                    *total_cost = novo_custo;
                }

            }
        }
    }
    
}