#include <iostream>
#include <vector>
#include "construtor.h"
#include "datatype.h"

using namespace std;

void melhora_rotas(int Q , int *total_cost, vector<int> d, vector<int> p, vector<vector<int>> c, vector<int> &v, int i, vector<int> &terc,int rota_demanda){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int custo_aux = 0;

    cout << "Demanda do cliente " << v[i] << ": " << d[v[i]-1] << endl;
    cout << "Demanda do tercerizado " << terc[0] << ": " << d[terc[0]-1] << endl;
    cout << "Demanda da rotas: " << rota_demanda << endl;

    //precisa verificar que se eu diminuir a demanda do cliente i, e depois adicionar o terceirizado é menor que Q
    if (rota_demanda - d[v[i]-1] + d[terc[0]-1] <= Q){
        int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];
        int manter_terc = c[ant_i][terc[0]] + c[terc[0]][prox_i];
        cout << "Custo para manter o cliente " << v[i] << " na rota: " << custo_manter_i << endl;
        cout << "Custo para terceirizar o cliente " << v[i] << ": " << p[v[i]-1] << endl;

        cout <<"Custo para manter o cliente que era terceirizado" << terc[0] << " na rota: " << manter_terc << endl;
        cout << "Custo para terceirizar o cliente terc: " << terc[0] << ": " << p[terc[0]-1] << endl;
        
        //verifica se o custo de manter o terceirizado é menor que o custo de manter o cliente i
        if (manter_terc < custo_manter_i){
            cout << "O custo de manter o terceirizado eh menor que o custo de manter o cliente i" << endl;
        }
        //verifica se o custo de terceirizar o cliente i é menor que o custo de manter
        else if (p[v[i]-1] < custo_manter_i){
            cout << "Eh melhor terceirizar o cliente do que manter" << endl;
            cout << "Diferença de custo: " << custo_manter_i - p[v[i]-1] << endl;
            cout <<"Colocar o cliente na lista de terceirizados, atualizar o custo e remover da rota" << endl;
            //verificar clientes_att
        }
    }
}