#ifndef PIANOSIMPLEARRANGEMENT_H
#define PIANOSIMPLEARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class PianoSimpleArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // PIANOSIMPLEARRANGEMENT_H
