#include <iostream>
#include <vector>
#include "readfile.h"
#include "construtor.h"
#include "showsolution.h"
#include "datatype.h"

using namespace std;


void printSolution(Solution solucao){

    cout << "Solucao: " << endl;

    int rotaNumber = 1; // contador para identificar o número da rota
    for (int i = 0; i < solucao.routes.size();i++) {
        cout << "Rota " << rotaNumber << ": ";
        print_array(&solucao.routes[i][0], solucao.routes[i].size());
        cout << "Demanda da rotas: " << solucao.rota_dem[i] << endl;
        rotaNumber++;
    }

    cout << "Lista tercerizados: ";
    print_array(&solucao.terceirizados[0], solucao.terceirizados.size());

    cout << "Custo total: " << solucao.totalCost << endl;
}
