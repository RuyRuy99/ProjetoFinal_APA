#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> read_file(const char* file){

    // Abrindo o arquivo
    ifstream File(file);
    if(!File.is_open()){
        std::cout << "Erro ao abrir o arquivo.\n";
        return {};
    }

    //Usando um vetor de inteiros para armazenar os valores convertidos
    vector<int> valores;
    int inteiro;
    while(File >> inteiro){
        valores.push_back(inteiro);
    }

    // Fechando o arquivo
    File.close();

    return valores;
}

void alguma_coisa(int *dados, vector<int>&d, vector<int>&p, vector<vector<int>> &c){ // Se não colocar o "&" não passa o vector por referencia e ele n aplica as alteraçõoes no vetor d.
    int n = dados[0]; // Número de clientes
    int k = dados[1]; // Quantidade de veículos
    int Q = dados[2]; // Quantidade máxima de cada veículo
    int L = dados[3]; // Quantidade mínima de entrega sem terceirização
    int r = dados[4]; // Custo de cada veículo

    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    cout << "Q = " << Q << endl;
    cout << "L = " << L << endl;
    cout << "r = " << r << endl;

    // Array de demandas de cada cliente
    int aux = 5;
    //Neste caso vamos passar o vector por referencia e preencher
    for (int i = 0; i < n; i++){
        d.push_back(dados[aux]);
        aux++;
    }

    //show the vector d
    cout << "VETOR D DENTRO DA FUNÇÃO: ";
    for (int i = 0; i < d.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;

    // Array de custo da terceirização
    for (int i = 0; i < n; i++){
        p.push_back(dados[aux]);
        aux++;
    }

    //show the vector p
    cout << "VETOR P DENTRO DA FUNÇÃO: ";
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    cout << endl;

    // Matriz de custo das arestas
    for (int i = 0; i < n+1; i++){
        vector<int> linha;
        for (int j = 0; j < n+1; j++){
            linha.push_back(dados[aux]);
            aux++;
        }
        c.push_back(linha);
    }
    //Matriz dentro da função
    cout << "MATRIZ C DENTRO DA FUNÇÃO: " << endl;
    for (int i = 0; i < c.size(); i++){
        for (int j = 0; j < c[i].size(); j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}



void swap(int *arr, int size){ // AJEITAR O TIPO DO ARGUMENTO DA FUNÇÃO.
    int aux = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = aux;
}