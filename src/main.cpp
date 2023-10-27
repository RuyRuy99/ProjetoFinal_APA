#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "readfile.h"
#include "datatype.h"
#include "construtor.h"
#include "guloso.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "vnd.h"
#include "ILS.h"
#include "file_exit.h"
#include "checksolution.h"


using namespace std;


int main(void){

    int n;// Número de clientes
    int k; // Quantidade de veículos
    int Q; // Quantidade máxima de cada veículo
    int L; // Quantidade mínima de entrega sem terceirização
    int r; // Custo de cada veículo

    // Vetores para armazenar os dados
    vector<int> dados;
    // Vetor de demandas dos clientes
    vector<int> d;
    // Vetor de custo de terceirização dos clientes
    vector<int> p;
    // Matriz de custo de transporte entre os clientes
    vector<vector<int>> c;

    //Nome do arquivo
    string instance = "n9k5_C.txt";
    dados = read_file(instance);

    // Extração dos dados
    extrai_dados(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);
    
    // -- CONSTRUTOR --

    // Relógio start
    auto start = chrono::steady_clock::now();
    // Heuristica construtiva
    Solution result = buildSolution(n, k, r, Q, L, c, d, p);
    // Relógio stop
    auto stop = chrono::steady_clock::now();
    // Tempo de execução
    cout << "TEMPO EXECUCAO GULOSO: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " ms" << endl;
    //printSolution(result);
    
    // -- VND --

    // Relógio start
    auto start2 = chrono::steady_clock::now();
    cout << "EXECUTANDO O VND" << endl;
    Solution result6 = vnd(result, r, Q, L, d, p, c);
    // Relógio stop
    auto stop2 = chrono::steady_clock::now();
    // Tempo de execução
    cout << "TEMPO EXECUCAO VND: " << chrono::duration_cast<chrono::milliseconds>(stop2 - start2).count() << " ms" << endl;
    //printSolution(result6);
    cout << "Custo total:" << result6.totalCost << endl;
    //doublecheck(result6, Q, L, r, d, p, c);
    
    // -- ILS --

    //relogio start
    auto start3 = chrono::steady_clock::now();
    cout << "EXECUTANDO O ILS" << endl;
    Solution ils = ILS(result, r, Q, L, d, p, c);
    //relogio stop
    auto stop3 = chrono::steady_clock::now();
    //tempo de execução
    cout << "TEMPO EXECUCAO ILS: " << chrono::duration_cast<chrono::milliseconds>(stop3 - start3).count() << " ms" << endl;
    //printSolution(ils);
    cout << "Custo total:" << ils.totalCost << endl;
    //doublecheck(ils, Q, L, r, d, p, c);

    // Arquivo de saída
    file_exit(instance, r, c, p, result);

    return 0;
}