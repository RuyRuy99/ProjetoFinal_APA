#ifndef VND_H
#define VND_H

#include <iostream>
#include <fstream>
#include <vector>
#include "datatype.h"


bool is_better(Solution solution1, Solution solution2);

Solution* best_neighbor(const Solution* current_solution, InstanceData* instanceData, int key);

Solution* vnd(Solution* current_solution, InstanceData* instanceData);

#endif