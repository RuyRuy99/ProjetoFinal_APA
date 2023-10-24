#ifndef VND_H
#define VND_H
#include "datatype.h"

bool is_better(Solution solution1, Solution solution2);

Solution best_neighbor(Solution vizinha , int r, int key, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c);

Solution vnd(Solution initial_solution, int r, int Q, int L, vector<int> d, vector<int> p, vector<vector<int>> c);

#endif