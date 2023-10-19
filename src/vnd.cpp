#include <iostream>
#include <vector>
#include "datatype.h"
#include "construtor.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"

// Comparar o custo da solution1 com o custo da solution2 e retornar quem é melhor (true)
bool is_better(int solution1, int solution2){
    return solution1 < solution2;
}
    
// Retorna a melhor solução vizinha para uma das estruturas de vizinhança k
int best_neighbor(int solution, int k){

    switch case(k){

        // best_neighbor_structure da primeira estrutura de vizinhança
        case 1:
            return buscaExaustivaN2(&routes, *total_cost, Q, d, c, p, &d_routs);

        // best_neighbor_structure da segunda estrutura de vizinhança
        case 2:
            return buscaExaustivaN3(Q, L, *total_cost, *terc_size, *total_clientes, d, p, c, &routes, &terceirizados, &rota_dem); 

        // best_neighbor_structure da terceira estrutura de vizinhança
        case 3:
            return buscaExaustivaN1(c, &rotas, *total_cost);
        
        // best_neighbor_structure da quarta estrutura de vizinhança
        case 4:
            return buscaExaustivaN4(L, *total_cost, *terc_size, *total_clientes, d, p, c, &routes, &terceirizados, &rota_demanda, &routes_size); // best_neighbor_structure da quarta estrutura de vizinhança
    }
}

int vnd(int initial_solution){

    int k = 1; // Contador de vizinhança
    int k_max = 4;  // Quantidade de estruturas de vizinhança
    int current_solution = initial_solution;

    while(k <= k_max){
        int neighbor = best_neighbor(current_solution, k);

        // Se a solução vizinha é melhor, atualizamos a solução atual e resetamos o contador de vizinhança
        if(is_better(neighbor, current_solution)){
            current_solution = neighbor;
            k = 1;

        }else{
            k += 1; // Passamos para a próxima estrutura de vizinhança
        }
    }

    return current_solution;
}