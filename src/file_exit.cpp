#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;

// Função para calcular o custa da terceirização
int cost_terc(vector<int> p, vector<int> &terceirizados){

    int custo = 0;
    for(int i = 0; i < terceirizados.size(); i++){
        custo += p[terceirizados[i]-1];
    }

    return custo;
}

// Função para calcular o custo da rota
int calcularCustoRota(vector<vector<int>> routes, vector<vector<int>> c, vector<int> &route_size){
    
    int custo = 0;
    for(int i=0; i < route_size.size(); i++){
        for(int j = 0; j < routes[i].size()-1; j++){
            int origem = routes[i][j];
            int destino = routes[i][j + 1];
            custo += c[origem][destino];
        }
    }

    return custo;
}

void file_exit(int r, vector<vector<int>> c, vector<int> p, Solution solucao){

    // Nome do arquivo de saida
    const char* exit = "saida.txt";

    // Objeto de fluxo de saída (ofstream)
    ofstream arquivoSaida(exit);

    // Verificando se o arquivo foi aberto com sucesso
    if (!arquivoSaida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saida." << endl;
        return;
    
    }else{ // Escrevendo no arquivo

        arquivoSaida << "" << solucao.totalCost << endl; // Valor total da solução
        arquivoSaida << "" << calcularCustoRota(solucao.routes, c, solucao.route_size) << endl; // custo de roteamento
        arquivoSaida << "" << solucao.route_size.size() * r << endl; // custo associado a utilização dos veículos
        arquivoSaida << "" << cost_terc(p, solucao.terceirizados) << "\n" << endl; //custo de terceirização

        for (const int& elemento : solucao.terceirizados){
            arquivoSaida << elemento << " ";
        }arquivoSaida << "\n" << endl;
 
        arquivoSaida << "" << solucao.route_size.size(); // Número de rotas

        // Adicionar as rotas
        for(int i=0; i < solucao.route_size.size(); i++){
            arquivoSaida << endl;
            for (size_t j = 0; j < solucao.routes[i].size(); j++) {
                arquivoSaida << solucao.routes[i][j] << " ";
            
            }
        }   

    }

    // Fechar o arquivo
    arquivoSaida.close();
}