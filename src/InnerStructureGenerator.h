#ifndef INNERSTRUCTUREGENERATOR_H
#define INNERSTRUCTUREGENERATOR_H
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "UniquePart.h"
#include "MusicScript.h"

using namespace std;
class InnerStructureGenerator : public MusicScript{
public:
 virtual ~InnerStructureGenerator() {};
 virtual void generateInnerStructure(UniquePart*){};
};
#endif // INNERSTRUCTUREGENERATOR_H
