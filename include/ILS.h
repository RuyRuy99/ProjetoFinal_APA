#ifndef ILS_H
#define ILS_H
#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

Solution pertubacao(Solution solucao, int Q, vector<int> d, vector<vector<int>> c);

Solution ILS(Solution solucao_inicial, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif