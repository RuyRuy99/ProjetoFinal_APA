#ifndef TESTE_H_
#define TESTE_H_

using namespace std;

vector<int> read_file(const char* file);

void extrai_dados(int *dados,int* n,int* k, int*Q, int* L, int* r,vector<int>&d, vector<int>&p, vector<vector<int>> &c); // Se não colocar o "&" não passa o vector por referencia e ele n aplica as alteraçõoes no vetor d.

void print_array(int *arr, int size);


void swap(int *arr, int size);

#endif 