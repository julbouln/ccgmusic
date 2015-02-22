#ifndef PIANOADVANCEDBOOGIEWOOGIE_H
#define PIANOADVANCEDBOOGIEWOOGIE_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class PianoAdvancedBoogieWoogie : public Arranger {
public:
 string getScriptName();
 int ArrangeBoogieWoogie(Song*);
 void arrange(Song*);
};
#endif // PIANOADVANCEDBOOGIEWOOGIE_H
