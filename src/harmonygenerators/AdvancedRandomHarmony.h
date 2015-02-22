#ifndef ADVANCEDRANDOMHARMONY_H
#define ADVANCEDRANDOMHARMONY_H
#include "Common.h"
#include "MusicScript.h"
#include "HarmonyGenerator.h"
#include "UniquePart.h"
using namespace std;
class AdvancedRandomHarmony : public HarmonyGenerator {
public:
 void generateHarmony(UniquePart*);
};
#endif // ADVANCEDRANDOMHARMONY_H
