#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datatype.h"

using namespace std;

InstanceData* readAndExtractData(const string& file){
    // Criar uma nova instância de InstanceData dinamicamente
    InstanceData* data = new InstanceData();

    // Caminho do arquivo
    string filePath = "inputs/" + file + ".txt";

    // Abrindo o arquivo
    ifstream File(filePath);
    if (!File.is_open()) {
        cout << "Erro ao abrir o arquivo.\n";
        delete data;  // Lembre-se de liberar a memória alocada em caso de falha
        return nullptr;
    }

    vector<int> valores;
    int inteiro;
    while (File >> inteiro) {
        valores.push_back(inteiro);
    }

    // Fechando o arquivo
    File.close();

    // Extrair os dados do vetor `valores`
    int aux = 0;

    data->n = valores[aux++]; // Número de clientes
    data->k = valores[aux++]; // Quantidade de veículos
    data->Q = valores[aux++]; // Quantidade máxima de cada veículo
    data->L = valores[aux++]; // Quantidade mínima de entrega sem terceirização
    data->r = valores[aux++]; // Custo de cada veículo

    // Demanda de cada cliente
    for (int i = 0; i < data->n; i++) {
        data->d.push_back(valores[aux++]);
    }

    // Custo da terceirização
    for (int i = 0; i < data->n; i++) {
        data->p.push_back(valores[aux++]);
    }

    // Matriz de custo das arestas
    for (int i = 0; i < data->n + 1; i++) {
        vector<int> linha;
        for (int j = 0; j < data->n + 1; j++) {
            linha.push_back(valores[aux++]);
        }
        data->c.push_back(linha);
    }

    // Retornar o ponteiro para o objeto InstanceData
    return data;
};