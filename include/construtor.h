#ifndef CONSTRUTOR_H_
#define CONSTRUTOR_H_
#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

// Construtor da solução inicial
Solution buildSolution(int n, int k, int r, int Q, int L, vector<vector<int>> c, vector<int> d, vector<int> p);

#endif