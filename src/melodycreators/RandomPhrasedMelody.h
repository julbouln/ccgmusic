#ifndef RANDOMPHRASEDMELODY_H
#define RANDOMPHRASEDMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "MelodyCreator.h"
#include "UniquePart.h"
#include "Time.h"
#include "UniquePhrase.h"
using namespace std;
class RandomPhrasedMelody : public MelodyCreator {
public:
 double GetEventLength(UniquePart*,int);
 void createMelody(UniquePart*);
};
#endif // RANDOMPHRASEDMELODY_H
