#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;

void melhora_rotas(int Q ,int L, vector<int> d,vector<int> p, vector<vector<int>> c, vector<int> &v, vector<int> &terc, int i, int *terc_size,int *clientes_att,int *total_cost,int *rota_demanda){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int j = 0; // Valor fixo ou deve ser passado na função ??
    
    // Custo das arestas de ligação do cliente i
    int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];

    // Custo das arestas de ligação do cliente tercerizado
    int manter_terc = c[ant_i][terc[j]] + c[terc[j]][prox_i];

    // Verifica se a lista de terceirados não está vazia para poder fazer o swap
    if (*terc_size > 0){

        // Verifica se o custo de manter o terceirizado é menor que o custo de manter o cliente i
        if(manter_terc < custo_manter_i){

            // Verifica se quando diminuir a demanda do cliente i e depois adicionar o terceirizado, é menor que a capacidade do carro
            if ((*rota_demanda - d[v[i]-1]) + d[terc[j]-1] <= Q){
         
                // Remove o custo de manter o cliente i do custo total
                *total_cost -= custo_manter_i;

                // Adiciona o custo de manter o terceirizado no custo total
                *total_cost += manter_terc;

                // Atualiza a demanda da rota
                *rota_demanda = *rota_demanda - d[v[i]-1] + d[terc[j]-1];

                // Fazer swap do terceirizado com cliente
                int aux = v[i];
                v[i] = terc[j];
                terc[j] = aux;

                // OBS: Como estou fazendo um swap de um terceirizado com rota não precisa decrementar o clientes_att
            }

        }else{

            // Remove o custo de manter o cliente i do custo total
            *total_cost -= custo_manter_i;
            
            // Adiciona o custo da aresta de ligação
            *total_cost += c[ant_i][prox_i];
            
            // Adiciona o custo de terceirizar o cliente i no custo total
            *total_cost += p[v[i]-1];

            // Atualiza a demanda da rota
            *rota_demanda -= d[v[i]-1];

            // Adiciona o cliente i na lista de terceirizados
            terc.push_back(v[i]);

            // Remove o cliente i da rota
            v.erase(v.begin()+i);

            // Diminuir a variavel client_att pq eu tirei um cliente da rota, logo não atendi ele
            *clientes_att -= 1;

            // Aumentar o tamanho do vetor de terceirizados
            *terc_size += 1;

        }
    }
}