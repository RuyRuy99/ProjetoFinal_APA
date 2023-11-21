#ifndef ILS_H
#define ILS_H

#include <iostream>
#include <vector>
#include "datatype.h"
#include "vnd.h"

using namespace std;

Solution* perturbacao(const Solution* solucao, InstanceData* dados);

Solution* ils(Solution* initial_solution, InstanceData* dados);

#endif