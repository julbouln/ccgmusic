#ifndef ONEPARTSIMPLESTRUCTURE_H
#define ONEPARTSIMPLESTRUCTURE_H
#include "Common.h"
#include "MusicScript.h"
#include "StructureGenerator.h"
#include "Song.h"
using namespace std;
class OnePartSimpleStructure : public StructureGenerator {
public:
 void generateStructure(Song*);
};
#endif // ONEPARTSIMPLESTRUCTURE_H
