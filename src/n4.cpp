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
        //cout << "Custo de manter " << v[i] << " = " << custo_manter_i << endl;

        // Remove o custo de manter o cliente i do custo total
        novo_custo -= custo_manter_i;
        //cout << "Custo total sem ele = " << novo_custo << endl;

        // Adiciona o custo da aresta de ligação
        novo_custo += c[ant_i][prox_i];
        //cout << "Custo da ligacao sem i = " << c[ant_i][prox_i] << endl;
        //cout << "Custo total com i = " << novo_custo << endl;

        // Adiciona o custo de terceirizar o cliente i no custo total
        novo_custo += p[v[i]-1];
        //cout << "Custo total com i terceirizado = " << novo_custo << endl;
    }
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

    // Inicializar variáveis para rastrear a melhor operação de terceirização.
    int min_custo_global = *total_cost;
    int min_rota_index = -1;
    int min_cliente_index = -1;

    for (int k = 0; k < num_rotas; k++){
        cout << "ROTA: " << k+1 << endl;
        for (int i = 1; i < route_size[k]-1; i++){

            // Calcular o custo potencial da terceirização deste cliente.
            int novo_custo = calculaTerc(routes[k], i, p, L, total_clientes, c, total_cost, terceirizados, terc_size, &rota_demanda[k]);

            // Se esta terceirização reduz o custo, consideramos ela como a melhor até agora.
            if (novo_custo < min_custo_global){
                min_custo_global = novo_custo;
                min_rota_index = k;
                min_cliente_index = i;
                cout << "Terceirizar o cliente " << routes[k][i] << " melhora o custo" <<endl;
                cout << "Custo atual = " << *total_cost << endl;
            }
        }
    }


    // Depois de verificar todos os clientes em todas as rotas, se uma terceirização benéfica foi encontrada, realizamos essa única operação.
    if (min_rota_index != -1) {
        cout << "Vou terceirizar o cliente " << routes[min_rota_index][min_cliente_index] << endl;
        updateRoutes(routes[min_rota_index], min_cliente_index, d, total_clientes, terceirizados, &rota_demanda[min_rota_index], terc_size);
        *total_cost = min_custo_global; // Atualizar o custo total para refletir essa mudança.
    }
    else{
        cout << "Nenhuma operação de terceirização vantajosa foi encontrada." << endl;
    }
}
