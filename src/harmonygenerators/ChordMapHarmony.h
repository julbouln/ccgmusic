#ifndef CHORDMAPHARMONY_H
#define CHORDMAPHARMONY_H
#include "Common.h"
#include "MusicScript.h"
#include "HarmonyGenerator.h"
#include "UniquePart.h"
using namespace std;
class ChordMapHarmony : public HarmonyGenerator {
public:
 void generateHarmony(UniquePart*);
};
#endif // CHORDMAPHARMONY_H
