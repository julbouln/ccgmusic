#ifndef SIMPLERANDOMHARMONY_H
#define SIMPLERANDOMHARMONY_H
#include "Common.h"
#include "MusicScript.h"
#include "HarmonyGenerator.h"
#include "UniquePart.h"
using namespace std;
class SimpleRandomHarmony : public HarmonyGenerator {
public:
 void generateHarmony(UniquePart*);
};
#endif // SIMPLERANDOMHARMONY_H
