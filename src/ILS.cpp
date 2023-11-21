#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "datatype.h"
#include "vnd.h"
#include "n1.h"
#include "n2.h"
#include "check_solution.h"

using namespace std;

Solution* perturbacao(const Solution* solucao, InstanceData* dados) {
    Solution* new_solution = new Solution(*solucao);  // Cria uma cópia da original

    int num_rotas = new_solution->routes.size();

    for (int i = 0; i < 100; i++) {
        int rota_idx = rand() % num_rotas;
        
        // Certifica que a rota tem pelo menos 2 clientes (excluindo o depósito)
        if (new_solution->routes[rota_idx].size() > 2) {
            int indice_cliente1 = rand() % (new_solution->routes[rota_idx].size() - 2) + 1; 
            int indice_cliente2 = rand() % (new_solution->routes[rota_idx].size() - 2) + 1;

            // Certifica que não são o mesmo cliente
            while (indice_cliente1 == indice_cliente2) {
                indice_cliente2 = rand() % (new_solution->routes[rota_idx].size() - 2) + 1;
            }
            //cout << "Rota: " << rota_idx << " Cliente 1: " << indice_cliente1 << " Cliente 2: " << indice_cliente2 << endl;
            // Recalcula o custo e faz o swap, pois se fizer o swap primeiro, vai dar bug
            new_solution->totalCost = custoSwap(new_solution->totalCost, dados->c, new_solution->routes[rota_idx], indice_cliente1, indice_cliente2);
            swapInside(new_solution->routes[rota_idx], indice_cliente1, indice_cliente2);
            
        }
    }

    return new_solution;  // Retorna a nova solução perturbada
}



Solution* ils(Solution* initial_solution, InstanceData* dados) {

    int semente = time(NULL);  // Pega o tempo atual como semente
    srand(semente);  // Inicializa a semente do gerador de números aleatórios
    cout << "Semente: " << semente << endl;

    Solution* S = vnd(initial_solution, dados);  // Aplica VND na solução inicial
    int cont = 0;

    while(cont <= 1000) {
        
        Solution* S1 = vnd(perturbacao(S, dados), dados); //Combina vnd e perturbação

        if (S1->totalCost < S->totalCost) {
            delete S;  // Libera a memória da solução atual
            S = S1;    // Atualiza S para ser a solução S1
        }
        else{
            delete S1; // Libera a memória da solução S1, já que não foi melhor
            cont++;    // Incrementa o contador
        }
    }
    cout << "FIM DO ILS" << endl;
    return S;  // Retorna a melhor solução encontrada
}
