#include "datatype.h"
#include "construtor.h"

// Estrutura de vizinhança 1
int best_neighbor_structure1(solution){
    // Busca exaustiva pela melhor solução vizinha usando a estrutura de vizinhança 1
    return;
}

// Estrutura de vizinhança 2
int best_neighbor_structure2(solution){
    // Busca exaustiva pela melhor solução vizinha usando a estrutura de vizinhança 2
    return;
}

// Estrutura de vizinhança 3
int best_neighbor_structure3(solution){
    // Busca exaustiva pela melhor solução vizinha usando a estrutura de vizinhança 3
    return;
}

// Estrutura de vizinhança 4
int best_neighbor_structure4(solution){
    // Busca pela melhor solução vizinha usando a estrutura de vizinhança 4
    return;
}

// Comparar o custo da solution1 com o custo da solution2 e retornar quem é melhor (true)
bool is_better(solution1, solution2){
    return;
}
    
// Retorna a melhor solução vizinha para uma das estruturas de vizinhança k
int best_neighbor(solution, k){

    switch case{
        case k == 1:
            return; // best_neighbor_structure da primeira estrutura de vizinhança
        case k == 2:
            return; // best_neighbor_structure da segunda estrutura de vizinhança
        case k == 3:
            return; // best_neighbor_structure da terceira estrutura de vizinhança
        case k == 4:
            return; // best_neighbor_structure da quarta estrutura de vizinhança
    }
}

int vnd(initial_solution){

    k = 1;
    k_max = 4;  // Quantidade de estruturas de vizinhança
    current_solution = initial_solution;

    while(k <= k_max){
        neighbor = best_neighbor(current_solution, k);

        // Se a solução vizinha é melhor, atualizamos a solução atual
        if(is_better(neighbor, current_solution)){
            current_solution = neighbor;
            k = 1; // Para resetar o contador de vizinhança

        }else{
            k += 1; // Passamos para a próxima estrutura de vizinhança
        }
    }

    return current_solution
}