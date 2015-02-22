#ifndef CLASSICALSTRUCTURESMALL_H
#define CLASSICALSTRUCTURESMALL_H
#include "Common.h"
#include "MusicScript.h"
#include "StructureGenerator.h"
#include "Song.h"
#include "UniquePart.h"
#include "Part.h"
using namespace std;
class ClassicalStructureSmall : public StructureGenerator {
public:
 void generateStructure(Song*);
};
#endif // CLASSICALSTRUCTURESMALL_H
