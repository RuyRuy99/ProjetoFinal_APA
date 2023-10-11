#include <iostream>
#include <vector>
#include "readfile.h"
#include "construtor.h"
#include "showsolution.h"

using namespace std;

struct Solution{
    vector<vector<int>> routes;
    int totalCost;
};


void printSolution(Solution solucao){

    cout << "Solucao: " << endl;

    int rotaNumber = 1; // contador para identificar o número da rota
    for (int i = 0; i < solucao.routes.size();i++) {
        cout << "Rota " << rotaNumber << ": ";
        print_array(&solucao.routes[i][0], solucao.routes[i].size());
        cout << endl;
        rotaNumber++;
    }

    cout << "Custo total: " << solucao.totalCost << endl;




}
