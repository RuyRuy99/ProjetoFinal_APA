#include <iostream>
#include <vector>
#include "datatype.h"
#include "construtor.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"



// Comparar o custo da solution1 com o custo da solution2 e retornar quem é melhor (true)
bool is_better(Solution solution1, Solution solution2){
    return solution1.totalCost > solution2.totalCost;
}
    
// Retorna a melhor solução vizinha para uma das estruturas de vizinhança k
Solution best_neighbor(Solution vizinha , int key, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    switch (key){
        case 1:
            cout << "EXECUTANDO N1" << endl;
            return buscaExaustivaN1(vizinha, c);

        case 2:
            cout << "EXECUTANDO N3" << endl;
            return buscaExaustivaN3(vizinha, Q, L, d, p, c);

        case 3:
            cout << "EXECUTANDO N2" << endl;
            return buscaExaustivaN2(vizinha, Q, d, p, c);
        
        case 4:
            cout << "EXECUTANDO N4" << endl;
            return buscaExaustivaN4(vizinha, L, d, p, c);

        default:
            return vizinha;
    }
}

Solution vnd(Solution initial_solution, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c){

    int k = 1; // Contador de vizinhança
    int k_max = 4;  // Quantidade de estruturas de vizinhança
    
    Solution current_solution = initial_solution;

    printSolution(current_solution);

    while(k <= k_max){


        //cout << "Estrutura de vizinhanca: " << k << endl;
        Solution sol_vizinha = best_neighbor(current_solution, k, Q, L, d, p, c);

        //Verifica se a solução vizinha é melhor que a solução atual
        if (is_better(current_solution, sol_vizinha) == true){
            cout << "Melhorou a solucao" << endl;
            cout << "Novo melhor custo: " << sol_vizinha.totalCost << endl;
            current_solution = sol_vizinha;
            k = 1;
        }
        else{
            //Proxima estrutura
            k += 1;
        }
    }
    cout << "FIM VND" << endl;
    return current_solution;
}