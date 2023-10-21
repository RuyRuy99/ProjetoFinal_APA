#include <iostream>
#include <vector>
#include "readfile.h"
#include "construtor.h"
#include "showsolution.h"
#include "datatype.h"

using namespace std;


int custoSwap(int *custo_atual, vector<vector<int>> c, vector<int> &v, int i, int j){

    int novo_custo = *custo_atual;
    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int ant_j = v[j-1];
    int prox_j = v[j+1];

    //remove o custo de quem estava ligado em i
    novo_custo -= c[ant_i][v[i]];
    novo_custo -= c[v[i]][prox_i];
    //cout << "removi as arestas " << ant_i <<"-" << v[i] << " e " << v[i] << "-" << prox_i << endl;
    //cout << "foi removido o custo de " << c[ant_i][v[i]] << " e " << c[v[i]][prox_i] << endl;

    //remove o custo de quem estava ligado em j
    novo_custo -= c[ant_j][v[j]];
    novo_custo -= c[v[j]][prox_j];
    //cout << "removi as arestas " << ant_j <<"-" << v[j] << " e " << v[j] << "-" << prox_j << endl;
    //cout << "foi removido o custo de " << c[ant_j][v[j]] << " e " << c[v[j]][prox_j] << endl;

    //adiciona o novo custo em relação a troca de j
    novo_custo += c[ant_i][v[j]];
    novo_custo += c[v[j]][prox_i];
    //cout << "Adicionei as arestas " << ant_i <<"-" << v[j] << " e " << v[j] << "-" << prox_i << endl;
    //cout << "foi adicionado o custo de " << c[ant_i][v[j]] << " e " << c[v[j]][prox_i] << endl;


    //adiciona o novo custo em relação a troca de i
    novo_custo += c[ant_j][v[i]];
    novo_custo += c[v[i]][prox_j];
    //cout << "Adicionei as arestas " << ant_j <<"-" << v[i] << " e " << v[i] << "-" << prox_j << endl;
    //cout << "foi adicionado o custo de " << c[ant_j][v[i]] << " e " << c[v[i]][prox_j] << endl;

    //se a diferença de J e I == 1 então ele removeu 2 arestas iguais
    if (abs(j - i) == 1){

        if (j > i){
            novo_custo += c[v[i]][prox_i];
            //cout << "Adicionei a aresta " << v[i] << "-" << prox_i << endl;
            //cout << "foi adicionado o custo de " << c[v[i]][prox_i] << endl;

            //adiciona a aresta j i
            novo_custo += c[v[j]][v[i]];
            //cout << "Adicionei a aresta " << v[j] << "-" << v[i] << endl;
            //cout << "foi adicionado o custo de " << c[v[j]][v[i]] << endl;
        }
        
        else{
            novo_custo += c[v[j]][prox_j];
            //cout << "Adicionei a aresta " << v[j] << "-" << prox_j << endl;
            //cout << "foi adicionado o custo de " << c[v[j]][prox_j] << endl;

            //adiciona a aresta i j
            novo_custo += c[v[i]][v[j]];
            //cout << "Adicionei a aresta " << v[i] << "-" << v[j] << endl;
            //cout << "foi adicionado o custo de " << c[v[i]][v[j]] << endl;
        }

    }

    return novo_custo;
}

void swapInside(vector<int> &v, int i, int j){
    //swap no vetor de rotas
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


void buscaExaustivaN1(vector<vector<int>> c, vector<vector<int>> &rotas, int *total_cost){

    int num_rotas = rotas.size();
    cout << "Numero de rotas = " << num_rotas << endl;

    int min_custo_global = *total_cost;
    int min_rota_idx = -1;
    int min_i_global = -1;
    int min_j_global = -1;


    for (int k = 0; k < num_rotas; k++){
        cout << "ROTA " << k+1 << endl;
        for (int i = 1 ; i < rotas[k].size()-1; i++){
            for (int j = i+1; j < rotas[k].size()-1; j++){ //Alteração de j = i

                //Custo atual, pode ser atualizado a cada troca
                int custo_atual = *total_cost;
                //cout << "Custo atual = " << custo_atual << endl;

                int novo_custo = custoSwap(&custo_atual, c, rotas[k], i, j);
                //cout << "Novo custo = " << novo_custo << endl;
                cout << "Visitei a aresta " << rotas[k][i] << "-" << rotas[k][j] << endl;

                //Se o custo novo for menor que o minimo global, atualiza o minimo global
                if (novo_custo < min_custo_global){
                    min_custo_global = novo_custo;
                    min_rota_idx = k;
                    min_i_global = i;
                    min_j_global = j;
                    cout << "A aresta " << rotas[k][i] << "-" << rotas[k][j] << " teve uma melhora" << endl;
                    cout << "O novo custo eh: " << min_custo_global << endl;
                }
            }
        }
    }

    //Se o custo global foi atualizado, então troca os clientes
    if (min_rota_idx != -1){
        cout << "O vertice " << rotas[min_rota_idx][min_i_global] << " foi trocado com o vertice " << rotas[min_rota_idx][min_j_global] << endl;
        cout << "O custo foi atualizado para " << min_custo_global << endl;
        swapInside(rotas[min_rota_idx], min_i_global, min_j_global);
        *total_cost = min_custo_global;
    }
    else{
        cout << "NENHUMA MELHORA ENCONTRADA !!!" << endl;
    }
}