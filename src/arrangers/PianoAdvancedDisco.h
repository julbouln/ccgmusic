#ifndef PIANOADVANCEDDISCO_H
#define PIANOADVANCEDDISCO_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class PianoAdvancedDisco : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // PIANOADVANCEDDISCO_H
