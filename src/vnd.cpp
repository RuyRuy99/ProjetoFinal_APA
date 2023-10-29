#include <iostream>
#include <vector>
#include "datatype.h"
#include "construtor.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"

// Comparar o custo da solution1 com o custo da solution2 e retornar quem é melhor (true)
bool is_better(Solution solution1, Solution solution2){
    return solution1.totalCost > solution2.totalCost;
}
    
// Retorna a melhor solução vizinha para uma das estruturas de vizinhança k
Solution best_neighbor(Solution vizinha , int r, int key, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    switch (key){
        case 1:
            return SwapIntra(vizinha, c);

        case 2:
            return Reinsertion(vizinha, c);

        case 3:
            return SwapInter(vizinha, Q, d, p, c);

        case 4:
            return SwapTerc(vizinha, Q, L, d, p, c);
        
        case 5:
            return Remove(vizinha, r, L, d, p, c);
        
        default:
            return vizinha;
    }
}

Solution vnd(Solution initial_solution, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    // Contador de vizinhança
    int k = 1;

    // Quantidade de estruturas de vizinhança
    int k_max = 5;
    
    Solution current_solution = initial_solution;

    while(k <= k_max){

        Solution sol_vizinha = best_neighbor(current_solution, r, k, Q, L, d, p, c);

        // Verifica se a solução vizinha é melhor que a solução atual
        if (is_better(current_solution, sol_vizinha) == true){
            current_solution = sol_vizinha;
            k = 1;
        
        }else{ // Próxima estrutura de vizinhança
        
            k += 1;
        }
    }

    return current_solution;
}