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
int calcularCustoRota(vector<vector<int>> routes, vector<vector<int>> c){
    
    int custo = 0;
    for(int i=0; i < routes.size(); i++){
        for(int j = 0; j < routes[i].size()-1; j++){
            int origem = routes[i][j];
            int destino = routes[i][j + 1];
            custo += c[origem][destino];
        }
    }

    return custo;
}

void file_exit(string instance,int r, vector<vector<int>> c, vector<int> p, Solution solucao){

    // Nome do arquivo de saida
    string output_dir = "outputs/";
    output_dir += instance;

    // Objeto de fluxo de saída (ofstream)
    ofstream arquivoSaida(output_dir);

    // Verificando se o arquivo foi aberto com sucesso
    if (!arquivoSaida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saida." << endl;
        return;
    
    }else{

        // Valor total da solução
        arquivoSaida << "" << solucao.totalCost << endl;
        // custo de roteamento
        arquivoSaida << "" << calcularCustoRota(solucao.routes, c) << endl;
        // custo associado a utilização dos veículos 
        arquivoSaida << "" << solucao.routes.size() * r << endl; 
        //custo de terceirização
        arquivoSaida << "" << cost_terc(p, solucao.terceirizados) << "\n" << endl;

        // Lista de clientes terceirizados
        for (const int& elemento : solucao.terceirizados){
            arquivoSaida << elemento << " ";
        }arquivoSaida << "\n" << endl;

        // Quantidade de rotas
        arquivoSaida << "" << solucao.routes.size() << endl;

        // Adicionar as rotas
        for(int i=0; i < solucao.routes.size(); i++){
            for (size_t j = 0; j < solucao.routes[i].size(); j++) {
                arquivoSaida << solucao.routes[i][j] << " "; 
            }arquivoSaida << endl;
        }   
    }

    // Fechar o arquivo
    arquivoSaida.close();
}