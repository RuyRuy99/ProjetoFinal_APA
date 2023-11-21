#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;

int calcularCustoRota(const vector<vector<int>>& routes, const vector<vector<int>>& c) {
    int custoTotal = 0;

    // Itera sobre cada rota
    for (const auto& rota : routes) {
        // Itera sobre cada cliente na rota, exceto o último
        for (size_t i = 0; i < rota.size() - 1; ++i) {
            int origem = rota[i];
            int destino = rota[i + 1];
            custoTotal += c[origem][destino];
        }
    }

    return custoTotal;
}



int cost_terc(const vector<int>& p, const vector<int>& terceirizados) {
    int custo = 0;
    for (const int& cliente : terceirizados) {
        custo += p[cliente - 1];  // Assume que os IDs dos clientes começam em 1
    }
    return custo;
}



void saveSolutionToFile(const string& instanceName, Solution* final_solution, InstanceData* dados) {
    string outputFilename = "outputs/" + instanceName + ".txt";
    ofstream outputFile(outputFilename);

    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo de saida." << endl;
        return;
    }

    // Escreve os detalhes da solução no arquivo
    outputFile << final_solution->totalCost << endl;
    outputFile << calcularCustoRota(final_solution->routes, dados->c) << endl;
    outputFile << final_solution->routes.size() * dados->r << endl; 
    outputFile << cost_terc(dados->p, final_solution->terceirizados) << "\n" << endl;

    // Lista de clientes terceirizados
    for (const int& cliente : final_solution->terceirizados) {
        outputFile << cliente << " ";
    }
    outputFile << "\n" << endl;

    // Quantidade de rotas e as rotas
    outputFile << final_solution->routes.size() << endl;
    for(const auto& rota : final_solution->routes) {
        for (const auto& cliente : rota) {
            outputFile << cliente << " "; 
        }
        outputFile << endl;
    }

    outputFile.close();
}
