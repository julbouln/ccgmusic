#ifndef RANDOMSTRUCTURE_H
#define RANDOMSTRUCTURE_H
#include "Common.h"
#include "MusicScript.h"
#include "StructureGenerator.h"
#include "Song.h"
#include "Part.h"
using namespace std;
class RandomStructure : public StructureGenerator {
public:
 void generateStructure(Song*);
};
#endif // RANDOMSTRUCTURE_H
