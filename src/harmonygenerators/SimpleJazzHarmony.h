#ifndef SIMPLEJAZZHARMONY_H
#define SIMPLEJAZZHARMONY_H
#include "Common.h"
#include "MusicScript.h"
#include "HarmonyGenerator.h"
#include "UniquePart.h"
using namespace std;
class SimpleJazzHarmony : public HarmonyGenerator {
public:
 void generateHarmony(UniquePart*);
};
#endif // SIMPLEJAZZHARMONY_H
