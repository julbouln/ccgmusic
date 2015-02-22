#ifndef RANDOMRIFFHARMONY_H
#define RANDOMRIFFHARMONY_H
#include "Common.h"
#include "MusicScript.h"
#include "HarmonyGenerator.h"
#include "UniquePart.h"
using namespace std;
class RandomRiffHarmony : public HarmonyGenerator {
public:
	class Offset {
	public:
    int bar;
    double pos;
	};
 void generateHarmony(UniquePart*);
};
#endif // RANDOMRIFFHARMONY_H
