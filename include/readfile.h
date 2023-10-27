#ifndef READFILE_H_
#define READFILE_H_

using namespace std;

// Leitura do arquivo
vector<int> read_file(string file);

// Tratamento dos dados extraídos do arquivo
void extrai_dados(int *dados,int* n,int* k, int*Q, int* L, int* r,vector<int>&d, vector<int>&p, vector<vector<int>> &c); // Se não colocar o "&" não passa o vector por referencia e ele n aplica as alteraçõoes no vetor d.

void print_array(int *arr, int size);

#endif