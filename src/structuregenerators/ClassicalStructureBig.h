#ifndef CLASSICALSTRUCTUREBIG_H
#define CLASSICALSTRUCTUREBIG_H
#include "Common.h"
#include "MusicScript.h"
#include "StructureGenerator.h"
#include "Song.h"
using namespace std;
class ClassicalStructureBig : public StructureGenerator {
public:
 void generateStructure(Song*);
};
#endif // CLASSICALSTRUCTUREBIG_H
