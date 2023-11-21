#ifndef SAVE_SOLUTION_H_
#define SAVE_SOLUTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datatype.h"

using namespace std;

int calcularCustoRota(const vector<vector<int>>& routes, const vector<vector<int>>& c);

int cost_terc(const vector<int>& p, const vector<int>& terceirizados);

void saveSolutionToFile(const string& instanceName, Solution* final_solution, InstanceData* dados);

#endif