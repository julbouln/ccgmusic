#ifndef WIDERANDOMMELODY_H
#define WIDERANDOMMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "MelodyCreator.h"
#include "UniquePart.h"
using namespace std;
class WideRandomMelody : public MelodyCreator {
public:
 void createMelody(UniquePart*);
};
#endif // WIDERANDOMMELODY_H
