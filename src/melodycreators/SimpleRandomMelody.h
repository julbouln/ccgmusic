#ifndef SIMPLERANDOMMELODY_H
#define SIMPLERANDOMMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "MelodyCreator.h"
#include "UniquePart.h"
using namespace std;
class SimpleRandomMelody : public MelodyCreator {
public:
 void createMelody(UniquePart*);
};
#endif // SIMPLERANDOMMELODY_H
