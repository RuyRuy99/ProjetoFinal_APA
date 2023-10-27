#include <iostream>
#include <vector>
#include "readfile.h"
#include "construtor.h"
#include "showsolution.h"
#include "datatype.h"

using namespace std;


void printSolution(Solution solucao){

    cout << "Solucao: " << endl;

    // Contador para identificar o número da rota
    int rotaNumber = 1;

    for (int i = 0; i < solucao.routes.size();i++) {

        cout << "Rota " << rotaNumber << ": ";
        print_array(&solucao.routes[i][0], solucao.routes[i].size());
        rotaNumber++;
    }

    cout << "Lista tercerizados: ";
    print_array(&solucao.terceirizados[0], solucao.terceirizados.size());

    cout <<"Total de clientes atendidos: " << solucao.total_clientes << endl;

    cout << "Custo total: " << solucao.totalCost << "\n" << endl;
}
