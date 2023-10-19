#include <iostream>
#include <vector>
#include "datatype.h"
#include "readfile.h"
#include "showsolution.h"

using namespace std;

int calculaTerc(vector<int> &v, int i, vector<int> p, int L, int *clientes_att, vector<vector<int>> c, int *total_cost, vector<int> &terc, int *terc_size, int *rota_demanda){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int novo_custo = *total_cost;

    // Verifica se PODE TERCEIRIZAR ALGUEM
    if (*clientes_att -1 >= L){

        int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];
        cout << "Custo de manter " << v[i] << " = " << custo_manter_i << endl;

        // Remove o custo de manter o cliente i do custo total
        novo_custo -= custo_manter_i;
        cout << "Custo total sem ele = " << novo_custo << endl;

        // Adiciona o custo da aresta de ligação
        novo_custo += c[ant_i][prox_i];
        cout << "Custo da ligacao sem i = " << c[ant_i][prox_i] << endl;
        cout << "Custo total com i = " << novo_custo << endl;

        // Adiciona o custo de terceirizar o cliente i no custo total
        novo_custo += p[v[i]-1];
        cout << "Custo total com i terceirizado = " << novo_custo << endl;
    }

    cout << endl;
    return novo_custo;
}

void updateRoutes(vector<int> &v, int i, vector<int> d, int *clientes_att, vector<int> &terc, int *rota_demanda, int *terc_size){

    // Remove a demanda do cliente que vai ser terceirizado
    *rota_demanda = *rota_demanda - d[v[i]-1];
        
    // Adiciona o cliente i na lista de terceirizados
    terc.push_back(v[i]);

    // Remove o cliente i da rota
    v.erase(v.begin()+i);

    // Diminuir a variavel client_att pq eu tirei um cliente da rota, logo não atendi ele
    *clientes_att -= 1;

    // Aumentar o tamanho do vetor de terceirizados
    *terc_size += 1;
}


void buscaExaustivaN4(int L, int *total_cost, int *terc_size, int *total_clientes, vector<int> d, vector<int> p, vector<vector<int>> c, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &rota_demanda, vector<int> &route_size){

    int num_rotas = routes.size();
    cout << "Numero de rotas = " << num_rotas << endl;

    for (int k = 0; k < num_rotas; k++){
        //int rota_atual_size = routes[k].size();
        cout << "ROTA: " << k+1 <<endl;
        for (int i = 1; i < route_size[k]; i++){

            int custo_atual = *total_cost;

            int novo_custo = calculaTerc(routes[k], i, p, L, total_clientes, c, total_cost, terceirizados, terc_size, &rota_demanda[k]);

            if (novo_custo < custo_atual){
                cout << "Vou terceirizar o cliente " << routes[k][i] << endl;
                updateRoutes(routes[k], i, d, total_clientes, terceirizados, &rota_demanda[k], terc_size);
                *total_cost = novo_custo;
            }
        }

    }

}