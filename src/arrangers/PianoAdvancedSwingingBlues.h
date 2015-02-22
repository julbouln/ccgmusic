#ifndef PIANOADVANCEDSWINGINGBLUES_H
#define PIANOADVANCEDSWINGINGBLUES_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class PianoAdvancedSwingingBlues : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // PIANOADVANCEDSWINGINGBLUES_H
