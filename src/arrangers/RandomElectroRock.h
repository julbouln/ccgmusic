#ifndef RANDOMELECTROROCK_H
#define RANDOMELECTROROCK_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class RandomElectroRock : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
private:
 string rndMelody();
 string rndBass();
 string rndChords();
 int rndStep();

};
#endif // RANDOMELECTROROCK_H
