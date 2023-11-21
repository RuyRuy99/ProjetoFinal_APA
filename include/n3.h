#ifndef N3_H_
#define N3_H_

#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

void reinsertionFunc(const vector<vector<int>>& c, vector<int>& rota1, int i, int j);

int costReinsertion(int total_cost, const vector<vector<int>>& c, const vector<int>& rota, int i, int j);

Solution* Reinsertion(Solution* current_solution, InstanceData* dados);

#endif