#include <iostream>
#include <fstream>
#include <vector>
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "datatype.h"

using namespace std;


Solution* best_neighbor(const Solution* current_solution, InstanceData* instanceData, int key) {
    // Cria uma nova solução baseada na atual
    Solution* neighbor_solution = new Solution(*current_solution);

    // Aplica a modificação na solução vizinha
    switch (key) {
        case 1:
            //cout << "N1" << endl;
            SwapIntra(neighbor_solution, instanceData);  // Altera a solução vizinha
            break;
        case 2:
            //cout << "N2" << endl;
            SwapInter(neighbor_solution, instanceData);  // Altera a solução vizinha
            break;
        case 3:
            //cout << "N3" << endl;
            Reinsertion(neighbor_solution, instanceData);  // Altera a solução vizinha
            break;
        case 4:
            //cout << "N4" << endl;
            SwapTerc(neighbor_solution, instanceData);  // Altera a solução vizinha
            break;
        case 5:
            //cout << "N5" << endl;
            remove(neighbor_solution, instanceData);  // Altera a solução vizinha
            break;
        default:
            // Caso não haja uma chave correspondente, retorna a cópia não alterada
            break;
    }

    // Retorna o ponteiro para a nova solução (já alterada ou não)
    return neighbor_solution;
}


Solution* vnd(Solution* current_solution, InstanceData* instanceData) {
    int k = 1;
    int k_max = 5;

    while (k <= k_max){
        Solution* neighbor_solution = best_neighbor(current_solution, instanceData, k);

        // Se a solução vizinha for melhor, atualiza a solução atual
        if (neighbor_solution->totalCost < current_solution->totalCost) {
            delete current_solution;  // Libera a memória da solução atual(memória do OBJETO)
            current_solution = neighbor_solution;  // Atualiza a solução atual para a solução vizinha
            k = 1;  // Reinicia o processo com a primeira estrutura de vizinhança
        } else {
            delete neighbor_solution;  // Libera a memória da solução vizinha
            k++;  // Avança para a próxima estrutura de vizinhança
        }
    }

    return current_solution;  // Retorna o ponteiro para a solução atualizada
}
