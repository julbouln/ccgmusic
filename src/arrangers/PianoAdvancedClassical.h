#ifndef PIANOADVANCEDCLASSICAL_H
#define PIANOADVANCEDCLASSICAL_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class PianoAdvancedClassical : public Arranger {
public:
 string getScriptName();
 int ArrangeClassical1(Song*);
 void arrange(Song*);
};
#endif // PIANOADVANCEDCLASSICAL_H
