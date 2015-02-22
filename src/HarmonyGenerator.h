#ifndef HARMONYGENERATOR_H
#define HARMONYGENERATOR_H
#include "Common.h"
#include "MusicScript.h"
#include "UniquePart.h"
using namespace std;
class HarmonyGenerator : public MusicScript
{
public:
    virtual ~HarmonyGenerator() {};
    virtual void generateHarmony(UniquePart *) {};
};
#endif // HARMONYGENERATOR_H
