#ifndef DATA_LOADER_H
#define DATA_LOADER_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datatype.h"

using namespace std;

InstanceData* readAndExtractData(const string& file);

#endif