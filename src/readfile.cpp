#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> read_file(string file){

    // Path file
    file = "Inputs/" + file;

    // Abrindo o arquivo
    ifstream File(file);
    if(!File.is_open()){
        std::cout << "Erro ao abrir o arquivo.\n";
        return {};
    }

    // Usando um vetor de inteiros para armazenar os valores convertidos
    vector<int> valores;
    int inteiro;
    while(File >> inteiro){
        valores.push_back(inteiro);
    }

    // Fechando o arquivo
    File.close();

    return valores;
}

void extrai_dados(int *dados,int* n,int* k, int*Q, int* L, int* r,vector<int>&d, vector<int>&p, vector<vector<int>> &c){ // Se não colocar o "&" não passa o vector por referencia e ele n aplica as alteraçõoes no vetor d.
    
    *n = dados[0]; // Número de clientes
    *k = dados[1]; // Quantidade de veículos
    *Q = dados[2]; // Quantidade máxima de cada veículo
    *L = dados[3]; // Quantidade mínima de entrega sem terceirização
    *r = dados[4]; // Custo de cada veículo

    int aux = 5;

    // Array de demandas de cada cliente
    for (int i = 0; i < *n; i++){
        d.push_back(dados[aux]);
        aux++;
    }

    // Array de custo da terceirização
    for (int i = 0; i < (*n); i++){
        p.push_back(dados[aux]);
        aux++;
    }

    // Matriz de custo das arestas
    for (int i = 0; i < (*n)+1; i++){
        vector<int> linha;
        for (int j = 0; j < (*n)+1; j++){
            linha.push_back(dados[aux]);
            aux++;
        }c.push_back(linha);
    }
}

void print_array(int *arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }cout << endl;
}