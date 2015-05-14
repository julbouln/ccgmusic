#ifndef MUSICSCRIPT_H
#define MUSICSCRIPT_H
#include "Common.h"
#include "Seedable.h"
#include "Song.h"
#include "Time.h"
#include "RenderPart.h"
#include "Utils.h"
using namespace std;
class MusicScript : public Seedable {
 int seed;
 Song* song;

public:

 enum ScaleType {
 	MAJOR_SCALE=0,
 	IONIAN_SCALE,
 	DORIAN_SCALE,
 	PHRYGIAN_SCALE,
 	LYDIAN_SCALE,
 	MIXOLYDIAN_SCALE,
 	AEOLIEN_SCALE,
 	LOCRIAN_SCALE,
 	NATURAL_MINOR_SCALE,
 	HARMONIC_MINOR_SCALE,
 	MELODIC_MINOR_SCALE,
 	ACCOUSTIC_SCALE,
 	SCALES_COUNT
 } ScaleTypes;

 static int scales[SCALES_COUNT][7];

 static int* getScaleOffsets(int);
 ~MusicScript();
 MusicScript();
 void setSeed(int);
 int getSeed();
 void resetSeed();
 int rndInt(int,int);
 double rndFloat(double,double);
 Time createTime(int,double);
 int getRandomScale();
 int getSongTempo();
 int getRandom(int[]);
 class Pattern {
 public:
    double Length;
    int* Pitches;
    int velfrom;
    int velto;
    double* pattern;
};
 Pattern* newPattern(double,int[],double[],int,int);
 void realizePattern(RenderPart*,Pattern*);
 void setSong(Song*);
};
#endif // MUSICSCRIPT_H
