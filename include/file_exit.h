#ifndef FILE_EXIT_H
#define FILE_EXIT_H

#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

int cost_terc(vector<int> p, vector<int> &terceirizados);

int calcularCustoRota(vector<vector<int>> routes, vector<vector<int>> c);

void file_exit(string instance,int r, vector<vector<int>> c, vector<int> p, Solution solucao);

#endif