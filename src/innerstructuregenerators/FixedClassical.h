#ifndef FIXEDCLASSICAL_H
#define FIXEDCLASSICAL_H
#include "Common.h"
#include "MusicScript.h"
#include "InnerStructureGenerator.h"
#include "UniquePart.h"
using namespace std;
class FixedClassical : public InnerStructureGenerator {
public:
 void generateInnerStructure(UniquePart*);
};
#endif // FIXEDCLASSICAL_H
