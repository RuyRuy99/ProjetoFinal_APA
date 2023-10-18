#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;

void melhora_rotas(int Q ,int L, vector<int> d,vector<int> p, vector<vector<int>> c, vector<int> &v, vector<int> &terc, int i, int j, int *terc_size,int *clientes_att,int *total_cost,int *rota_demanda){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    
    // Custo das arestas de ligação do cliente i
    int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];

    // Verifica se a lista de terceirados não está vazia para poder fazer o swap
    if (*terc_size > 0){

        // Custo das arestas de ligação do cliente tercerizado
        int manter_terc = c[ant_i][terc[j]] + c[terc[j]][prox_i];

        cout << "Custo de manter o cliente: " << custo_manter_i << endl;
        cout << "Custo de manter o terceirizado: " << manter_terc <<endl;

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
                cout << "Fiz o SWAP"<<endl;
                // OBS: Como estou fazendo um swap de um terceirizado com rota não precisa decrementar o clientes_att
            }
            //Verifica se o custo de terceirizar o cliente i é menor que o custo de manter o cliente i
            else if(p[v[i]-1] < custo_manter_i and *clientes_att - 1 >= L){
                // Remove o custo de manter o cliente i do custo total
                *total_cost -= custo_manter_i;
                cout << "Custo depois de remover i: " << *total_cost << endl;
                // Adiciona o custo da aresta de ligação
                *total_cost += c[ant_i][prox_i];
                cout << "Custo ao adicionar a aresta de ligacao " << *total_cost << endl;
                // Adiciona o custo de terceirizar o cliente i no custo total
                *total_cost += p[v[i]-1];
                cout << "Custo ao adicionar o terceirizado " << *total_cost << endl;
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
                cout << "Entrei aqui "<<endl;
            }
        }
    }
    //Verifica se o custo de terceirizar o cliente i é menor que o custo de manter o cliente i
    else if(p[v[i]-1] < custo_manter_i and *clientes_att - 1 >= L){
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
        cout << "Entrei aqui"<<endl;
    }
}

void buscaExaustivaN3(int Q ,int L, int *total_cost, int *terc_size, int *total_clientes, vector<int> d, vector<int> p, vector<vector<int>> c, vector<vector<int>> &routes, vector<int> &terceirizados, vector<int> &rota_dem){
    
    int num_rotas = routes.size();
    cout << "Quantidade de rotas == " << num_rotas << endl;
    for (int k = 0; k < num_rotas; k++){ // Percorre a lista de clientes não atendidos
        int rota_atual_size = routes[k].size();
        cout << "Rota " << k+1 << endl;
        for (int i = 1; i < rota_atual_size-1; i++){ // Percorrer os vetores da rota
            for (int j = 0; j < *terc_size; j++){
                melhora_rotas(Q, L, d, p, c, routes[k], terceirizados, i,j, terc_size, total_clientes, total_cost, &rota_dem[k]);
                
            }
        }
    if (k==1){
        break;
    }
    }
    
}