#include <iostream>
#include <vector>
#include "datatype.h"
#include "readfile.h"
#include "showsolution.h"

using namespace std;

int calculaTerc(Solution solucao, vector<int> &v, int i, int clientes_atendidos, int L, vector<int> p, vector<vector<int>> c){

    int ant_i = v[i-1];
    int prox_i = v[i+1];
    int novo_custo = solucao.totalCost;
    //cout << "Anterior = " << ant_i << endl;
    //cout << "Proximo = " << prox_i << endl;

    // Verifica se PODE TERCEIRIZAR ALGUEM
    if (clientes_atendidos-1 >= L){

        int custo_manter_i = c[ant_i][v[i]] + c[v[i]][prox_i];
        
        
        //cout << "Custo de manter " << v[i] << " = " << custo_manter_i << endl;

        // Remove o custo de manter o cliente i do custo total
        novo_custo -= custo_manter_i;
        //cout << "Custo total sem ele = " << novo_custo << endl;

        // Adiciona o custo da aresta de ligação
        novo_custo += c[ant_i][prox_i];
        //cout << "Custo sem o cliente na rota = " << novo_custo << endl;

        // Adiciona o custo de terceirizar o cliente i no custo total
        novo_custo += p[v[i]-1];
        //cout << "Custo total com i terceirizado = " << novo_custo << endl;
        //cout << "Novo custo: " << novo_custo << endl;
    }
    return novo_custo;
}

void updateRoutes(vector<int> &v, int i, int *clientes_atendidos, int *rota_demanda, int *terc_size,vector<int> &terc, vector<int> d){

    // Remove a demanda do cliente que vai ser terceirizado
    *rota_demanda = *rota_demanda - d[v[i]-1];
    //cout << "Demanda da rota = " << *rota_demanda << endl;
        
    // Adiciona o cliente i na lista de terceirizados
    //cout << "Vou terceirizar o cliente " << v[i] << endl;
    terc.push_back(v[i]);

    // Remove o cliente i da rota
    v.erase(v.begin()+i);

    // Diminuir a variavel client_att pq eu tirei um cliente da rota, logo não atendi ele
    *clientes_atendidos -= 1;

    // Aumentar o tamanho do vetor de terceirizados
    *terc_size += 1;
}


Solution buscaExaustivaN4(Solution initial_solution, int r, int L, vector<int> d, vector<int> p, vector<vector<int>> c){
    //Inicia a solução vizinha...
    Solution sol_vizinha = initial_solution;

    // Inicializar variáveis para rastrear a melhor operação de terceirização.
    int min_custo_global = initial_solution.totalCost;
    int min_rota_index = -1;
    int min_i = -1;

    int num_rotas = sol_vizinha.routes.size();
    //cout << "Numero de rotas = " << num_rotas << endl;

    for (int k = 0; k < num_rotas; k++){
        //cout << "ROTA: " << k+1 << endl;
        int rota_atual_size = sol_vizinha.routes[k].size();

        for (int i = 1; i < rota_atual_size-1; i++){

            // Calcular o custo resultante de terceirizar o cliente
            int novo_custo = calculaTerc(sol_vizinha, sol_vizinha.routes[k], i, sol_vizinha.total_clientes, L, p, c);

            // Se esta terceirização reduz o custo, consideramos ela como a melhor até agora.
            if (novo_custo < min_custo_global){
                min_custo_global = novo_custo;
                min_rota_index = k;
                min_i = i;
                //cout << "Terceirizar o cliente " << sol_vizinha.routes[k][i] << " melhora o custo." << endl;
                //cout << "Novo custo = " << min_custo_global << endl;
            }
        }
    }


    // Depois de verificar todos os clientes em todas as rotas, se uma terceirização benéfica foi encontrada, realizamos essa única operação.
    if (min_rota_index != -1) {
        //cout << "Vou terceirizar o cliente " << sol_vizinha.routes[min_rota_index][min_i] << endl;
        updateRoutes(sol_vizinha.routes[min_rota_index], min_i, &sol_vizinha.total_clientes,&sol_vizinha.rota_dem[min_rota_index], &sol_vizinha.terc_size, sol_vizinha.terceirizados, d);
        sol_vizinha.route_size[min_rota_index] -= 1;//Remoção da quantidade de clientes atendidos na rota
        sol_vizinha.totalCost = min_custo_global;
        cout << "Clientes atendidos na rota: " << min_rota_index+1 << " = " << sol_vizinha.route_size[min_rota_index] << endl;
        //Verifica se a rota ficou vazia
        if (sol_vizinha.route_size[min_rota_index] == 0){
            //Remove o custo de um carro
            sol_vizinha.totalCost -= r;
            //Remove a rota vazia
            sol_vizinha.routes.erase(sol_vizinha.routes.begin()+min_rota_index);
            //Remove o tamanho da rota vazia
            sol_vizinha.route_size.erase(sol_vizinha.route_size.begin()+min_rota_index);
            //Remove a demanda da rota vazia
            sol_vizinha.rota_dem.erase(sol_vizinha.rota_dem.begin()+min_rota_index);
        }
    }
    else{
        //cout << "Nenhuma operação de terceirizacao vantajosa foi encontrada." << endl;
    }

    return sol_vizinha;
}
