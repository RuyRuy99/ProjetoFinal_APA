#ifndef TESTE_H_
#define TESTE_H_

using namespace std;

// Ler os dados do arquivo
vector<int> read_file(const char* file);

// Separar os dados 
void alguma_coisa(int *dados,int* n,int* k, int*Q, int* L, int* r,vector<int>&d, vector<int>&p, vector<vector<int>> &c); // Se não colocar o "&" não passa o vector por referencia e ele n aplica as alteraçõoes no vetor d.

// Efetuar a trocar
void swap(int *arr, int size);

#endif 