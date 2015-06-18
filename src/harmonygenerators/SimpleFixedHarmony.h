#ifndef SIMPLEFIXEDHARMONY_H
#define SIMPLEFIXEDHARMONY_H
#include "Common.h"
#include "MusicScript.h"
#include "HarmonyGenerator.h"
#include "UniquePart.h"
using namespace std;
class SimpleFixedHarmony : public HarmonyGenerator {
public:
 void generateHarmony(UniquePart*);
private:
	static int progressions[][8];
	vector<int> rndChord();
};
#endif // SIMPLEFIXEDHARMONY_H
