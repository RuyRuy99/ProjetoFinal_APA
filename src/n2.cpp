#include <iostream>
#include <vector>
#include <random>
#include "construtor.h"
#include "datatype.h"
#include <chrono>

using namespace std;

struct SwapResult { // Struct  para retornar o resultado do swap
    int total_cost; // Custo total
    int n1; // Indice do cliente 1
    int n2; // Indice do cliente 2
};

int findMaxCostVertex(vector<int> &rota, vector<vector<int>> c){ 
    // Função para calcular o vertice de maior custo de uma rota (somamdo as arestas de entrada e saida)
    int vertice;
    int cost = 0;
    for (int i = 1; i < rota.size()-1; i++){
        //Itera sobre os vértices na rota, o custo de cada vértice é a soma das arestas de entrada e saida
        //cout << "Custo da aresta: (" << rota[i-1] << ","<< rota[i] << ")" << " = " << c[rota[i-1]][rota[i]] << endl;
        //cout << "Custo da aresta: (" << rota[i] << ","<< rota[i+1] << ")" << " = " << c[rota[i]][rota[i+1]] << endl;
        if(c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]] > cost){
            // Atualiza quando acha um vértice com custo maior
            cost = c[rota[i-1]][rota[i]] + c[rota[i]][rota[i+1]];
            vertice = i;
        }
    }
    //cout << "FINAL DA CHAMADA\n" << endl;
    // Retorna a posição do vértice de maior custo
    return vertice;
};


SwapResult custoSwap_Routes(int *total_cost, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &v1, vector<int> &v2, vector<int> &d_routs, int i, int j){
    // Calcula o custo para realizar a troca do cliente i com o cliente j e diz se a troca é viável ou não (se a demanda total da rota não ultrapassa a capacidade do carro)
    int n1 = findMaxCostVertex(v1, c); // Acha o vértice mais caro da rota 1
    int n2 = findMaxCostVertex(v2, c); // Acha o vértice mais caro da rota 2
    
    //Cria a estrutura do swap, setando os parâmetros
    SwapResult result;
    result.total_cost = *total_cost;
    result.n1 = n1;
    result.n2 = n2;
    
    //Define os clientes (pra olhar os custos depois), os anteriores e posteriores a eles
    int cliente1 = v1[n1];
    int cliente2 = v2[n2];
    int ant_i = v1[n1-1];
    int prox_i = v1[n1+1];
    int ant_j = v2[n2-1];
    int prox_j = v2[n2+1];

    cout << "A DEMANDA DE CADA CARRO EH: " << Q << endl;
    
    cout << "\n" << endl;
    cout << "O cliente mais caro da rota 1 eh: " << cliente1 << endl;
    cout << "O cliente mais caro da rota 2 eh: " << cliente2 << endl;

    cout << "\n" << endl;
    cout << "A demanda do cliente " << cliente1 << " eh:  " << d[cliente1-1] << endl;
    cout << "A demanda do cliente " << cliente2 << " eh:  " << d[cliente2-1] << endl;

    cout << "\n" << endl;
    cout << "A demanda da rota 1 eh: " << d_routs[i] << endl;
    cout << "A demanda da rota 2 eh: " << d_routs[j] << endl;

    //Variáveis auxiliares para analisar o impacto da troca de clientes na demanda da rota
    //A variável status diz se a troca vai ser viável ou não
    //A variável d_att contém o valor da demanda atualizado após a troca
    bool status;
    int d_att;
    
    if(d[cliente1-1] > d[cliente2-1]){//Quando a demanda do cliente 1 for maior o impacto mais consideravel é na demanda da rota 2
        cout << "Demanda do cliente " << cliente1 << " eh maior, ver como vai impactar na rota 2" << endl;
        //Demanda da rota j
        d_att = d_routs[j];
        cout << "Demanda da rota 2 = " << d_att << endl;
        //Demanda da rota j sem a demanda do cliente 2
        d_att -= d[cliente2-1];
        cout << "Demanda da rota 2 - demanda do cliente 2 = " << d_att << endl;
        //Demanda da rota j com a demanda do cliente 1
        d_att += d[cliente1-1];
        cout << "Demanda da rota 2 + demanda do cliente 1 = " << d_att << endl;

        if(d_att > Q){//Se após a troca a demanda ultrapassar a capacidade do carro a troca não é viável
            status = false;
        }
        else{//Se após a troca a demanda não ultrapassar a capacidade do carro a troca é viável
            status = true;
        }

        cout << "Pode fazer a troca? " << status << endl;
    }
    else if(d[cliente2-1] > d[cliente1-1]){//Quando a demanda do cliente 2 for maior o impacto mais consideravel é na demanda da rota 1
        cout << "Demanda do cliente " << cliente2 << " eh maior, ver como vai impactar na rota 1" << endl;
        //Demanda da rota i
        d_att = d_routs[i];
        cout << "Demanda da rota 1 = " << d_att << endl;
        //Demanda da rota j sem a demanda do cliente 1
        d_att -= d[cliente1-1];
        cout << "Demanda da rota 1 - demanda do cliente 1 = " << d_att << endl;
        //Demanda da rota j com a demanda do cliente 2
        d_att += d[cliente2-1];
        cout << "Demanda da rota 1 + demanda do cliente 2 = " << d_att << endl;

        if(d_att > Q){//Se após a troca a demanda ultrapassar a capacidade do carro a troca não é viável
            status = false;
        }
        else{//Se após a troca a demanda não ultrapassar a capacidade do carro a troca é viável
            status = true;
        }
        cout << "Pode fazer a troca? " << status << endl;
    }
    else{//Caso onde as demandas são iguais
        status = true;
        cout << "Demandas Iguais" << endl;
    }
    if(status){//Calcula o custo total da solução quando a troca é viável
        cout << "FAZENDO SWAP DO " << cliente1 << " COM O CLIENTE: " << cliente2 << endl;
        cout << "O CUSTO ANTES DO SWAP EH: " << result.total_cost << endl;

        //Removendo os custos das arestas antigas
        result.total_cost -= c[ant_i][cliente1];
        result.total_cost -= c[cliente1][prox_i];

        result.total_cost -= c[ant_j][cliente2];
        result.total_cost -= c[cliente2][prox_j];

        //Somando os custos das novas arestas
        result.total_cost += c[ant_i][cliente2];
        result.total_cost += c[cliente2][prox_i];

        result.total_cost += c[ant_j][cliente1];
        result.total_cost += c[cliente1][prox_j];

        cout << "O CUSTO DEPOIS DO SWAP EH: " << result.total_cost << endl;
        return result;
    }
    else{//Caso onde a troca não é viável
        cout << "Não pode fazer a troca. Status: " << status << endl;
        result.total_cost = -1;
        return result;
    }

}

void swapRoutes(vector<int> &v1, vector<int> &v2, int n1, int n2, vector<int> &d_routs, vector<int> d, int i, int j){
    //Define os clientes e as variáveis auxiliares
    int cliente1 = v1[n1];
    int cliente2 = v2[n2];
    int aux1 = cliente1;
    int aux2 = cliente2;

    //Atualiza os clientes nas rotas
    v1[n1] = aux2;
    v2[n2] = aux1;

    //Atualiza a demanda total da rota i
    d_routs[i] -= d[cliente1-1];
    d_routs[i] += d[cliente2-1];

    //Atualiza a demanda total da rota j
    d_routs[j] -= d[cliente2-1];
    d_routs[j] += d[cliente1-1];

}

void buscaExaustivaN2(vector<vector<int>> &routes, int *total_cost, int Q, vector<int> d,vector<vector<int>> c,vector<int> p, vector<int> &d_routs){
    //Realiza a busca exaustiva, fazendo trocas entre as rotas i e j
    cout << "QUANTIDADE DE ROTAS: " << routes.size() << endl;
    for (int i = 0; i < routes.size(); i++){//Itera sobre as rotas (i)
        for (int j = i; j < routes.size(); j++){//Itera sobre as rotas (j), aqui estamos evitando olhar repetidamente (i com j e j com i)
            if(i != j){
                int custo_atual = *total_cost; // Define o custo atual
                cout << "\n" << endl;
                cout << "CUSTO ATUAL: " << custo_atual << endl;
                cout << "SWAP DA ROTA " << i << " COM A ROTA "<< j << endl;
               
                //Calcula o custo do SWAP da rota i com a rota j
                SwapResult resultado = custoSwap_Routes(&custo_atual, Q, d, c, p, routes[i], routes[j], d_routs, i, j);
                cout << "NOVO CUSTO: " << resultado.total_cost << endl;

                //Se o novo custo for melhor que o atual, concretiza o swap de i com j
                if(resultado.total_cost < custo_atual && resultado.total_cost != -1){
                    swapRoutes(routes[i], routes[j], resultado.n1, resultado.n2, d_routs, d, i, j);
                    *total_cost = resultado.total_cost;
                }
            }
        }
    }
}