#ifndef MODERNSONGSTRUCTURE_H
#define MODERNSONGSTRUCTURE_H
#include "Common.h"
#include "MusicScript.h"
#include "StructureGenerator.h"
#include "Song.h"
using namespace std;
class ModernSongStructure : public StructureGenerator {
public:
 void generateStructure(Song*);
};
#endif // MODERNSONGSTRUCTURE_H
