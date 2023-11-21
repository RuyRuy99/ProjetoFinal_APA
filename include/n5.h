#ifndef N5_H_
#define N5_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"

using namespace std;


int calculaTerc(Solution* solucao, vector<int>& v, int i, InstanceData* dados);

void updateRoutes(vector<int>& v, int i, Solution* solucao, InstanceData* dados);

Solution* remove(Solution* current_solution, InstanceData* dados);

#endif