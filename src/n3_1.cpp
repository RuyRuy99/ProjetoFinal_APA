#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"
#include "readfile.h"

using namespace std;

void melhora_rotas(int Q ,int L, vector<int> d,vector<int> p, vector<vector<int>> c, vector<int> &v, vector<int> &terc, int i, int *terc_size,int *clientes_att,int *total_cost,int *rota_demanda){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int custo_aux = 0;

    int j = 0;
    
    int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];

    cout << "Custo para manter o cliente " << v[i] << " na rota: " << custo_manter_i << endl;
    cout << "Custo para terceirizar o cliente " << v[i] << ": " << p[v[i]-1] << endl;
    int manter_terc = c[ant_i][terc[j]] + c[terc[j]][prox_i];
    cout <<"Custo para manter o cliente que era terceirizado" << terc[j] << " na rota: " << manter_terc << endl;
    cout << "Custo para terceirizar o cliente terc: " << terc[j] << ": " << p[terc[j]-1] << endl;
    cout << "Demanda do cliente " << v[i] << ": " << d[v[i]-1] << endl;
    cout << "demanda do terceirizado " << terc[j] << ": " << d[terc[j]-1] << endl;


    //VETOR DE TERCEIRIZAÇÃO N PODE SER VAZIO PARA FZR O SWAP ENTÃO VERIFICA
    if (*terc_size > 0){
        //precisa verificar que se eu diminuir a demanda do cliente i, e depois adicionar o terceirizado é menor que Q
        if (*rota_demanda - d[v[i]-1] + d[terc[j]-1] <= Q){
            int manter_terc = c[ant_i][terc[j]] + c[terc[j]][prox_i];
            //cout << "Custo para manter o cliente " << v[i] << " na rota: " << custo_manter_i << endl;
            //cout << "Custo para terceirizar o cliente " << v[i] << ": " << p[v[i]-1] << endl;

            //cout <<"Custo para manter o cliente que era terceirizado" << terc[j] << " na rota: " << manter_terc << endl;
            //cout << "Custo para terceirizar o cliente terc: " << terc[j] << ": " << p[terc[j]-1] << endl;
        
            //verifica se o custo de manter o terceirizado é menor que o custo de manter o cliente i
            if (manter_terc < custo_manter_i){
                //cout << "O custo de manter o terceirizado eh menor que o custo de manter o cliente i" << endl;
                //remove o custo de manter o cliente i do custo total
                *total_cost -= custo_manter_i;
                //adiciona o custo de manter o terceirizado no custo total
                *total_cost += manter_terc;

                //atualiza a demanda da rota
                *rota_demanda = *rota_demanda - d[v[i]-1] + d[terc[j]-1];

                //fazer swap do terceirizado com cliente
                int aux = v[i];
                v[i] = terc[j];
                terc[j] = aux;
                //como estou fazendo um swap de um terceirizado com rota não precisa decrementar o clientes_att
            
            }

            else if (p[v[i]-1] < custo_manter_i and *clientes_att - 1 >= L){

                //cout << "Eh melhor terceirizar o cliente do que manter diferenca do custo = " << custo_manter_i - p[v[i]-1] << endl;
                //cout << "Custo antes de tudo = " << *total_cost << endl;
                //remove o custo de manter o cliente i do custo total
                *total_cost -= custo_manter_i;
                //cout << "Custo depois de remover o custo de manter o cliente i = " << *total_cost << endl;
                //adiciona o custo da aresta de ligação
                *total_cost += c[ant_i][prox_i];
                //cout << "Custo depois de adicionar o custo da aresta de ligacao = " << *total_cost << endl;
                //adiciona o custo de terceirizar o cliente i no custo total
                *total_cost += p[v[i]-1];
                //cout << "Custo depois de adicinaor o custo de terceirizar o cliente i = " << *total_cost << endl;

                //atualiza a demanda da rota
                *rota_demanda = *rota_demanda - d[v[i]-1];

                //adiciona o cliente i na lista de terceirizados
                terc.push_back(v[i]);

                //remove o cliente i da rota
                v.erase(v.begin()+i);
            
                //print_array(&v[0], v.size());
                //print_array(&terc[j], terc.size());

                //diminuir a variavel client_att pq eu tirei um cliente da rota, logo não atendi ele
                *clientes_att -= 1;
                //aumentar o tamanho do vetor de terceirizados
                *terc_size += 1;
            }



        }
    }

    //verifica se o custo de terceirizar do cliente i é menor que o custo de mante-lo
    //verificar também se clientes_att - 1 >= L
    else if (p[v[i]-1] < custo_manter_i and *clientes_att - 1 >= L){
        //cout << "Tamanho do vetor de tercerizacao: " << *terc_size << endl;
        //cout << "Eh melhor terceirizar o cliente do que manter diferenca do custo = " << custo_manter_i - p[v[i]-1] << endl;
        

        //remove o custo de manter o cliente i do custo total
        *total_cost -= custo_manter_i;
        //cout << "Custo depois de remover o custo de manter o cliente i = " << *total_cost << endl;

        //adiciona o custo da aresta de ligação
        *total_cost += c[ant_i][prox_i];
        //cout << "Custo depois de adicionar o custo da aresta de ligacao = " << *total_cost << endl;

        //adiciona o custo de terceirizar o cliente i no custo total
        *total_cost += p[v[i]-1];

        //atualiza a demanda da rota
        *rota_demanda = *rota_demanda - d[v[i]-1];
            
        //adiciona o cliente i na lista de terceirizados
        terc.push_back(v[i]);

        //remove o cliente i da rota
        v.erase(v.begin()+i);
            
        //print_array(&v[0], v.size());
        //print_array(&terc[j], terc.size());

        //diminuir a variavel client_att pq eu tirei um cliente da rota, logo não atendi ele
        *clientes_att -= 1;
        //aumentar o tamanho do vetor de terceirizados
        *terc_size += 1;
    }
}
