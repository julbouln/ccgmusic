#ifndef MUSICSCRIPT_H
#define MUSICSCRIPT_H
#include "Common.h"
#include "Seedable.h"
#include "Song.h"
#include "Time.h"
#include "RenderPart.h"
#include "Utils.h"

#include "MidiInstruments.h"

using namespace std;
class MusicScript : public Seedable {
 int seed;
 Song* song;

public:

static enum ChordType {
	MAJOR_TRIAD_CHORD=0,
	ADD_SIXTH_TRIAD_CHORD,
	MAJOR_SEVENTH_CHORD,
/*	MINOR_TRIAD_CHORD,
	SUS2_SEVENTH_CHORD,
	SUS4_SEVENTH_CHORD,
	ADD_SIXTH_NINE_CHORD,
	ADD2_CHORD,
	ADD4_CHORD,
	ADD9_CHORD,
*/	
	
	CHORDS_COUNT
} ChordTypes;

static enum ScaleType {
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

 	BLUES_SCALE,
 	NEAPOLITAN_MINOR_SCALE,
 	NEAPOLITAN_MAJOR_SCALE,
 	NEAPOLITAN_DORIAN_SCALE,
 	NEAPOLITAN_MIXOLYDIAN_SCALE,
 	ORIENTAL_SCALE,
 	ARABIAN_SCALE,
 	EGYPTIAN_SCALE,
 	PERSIAN_SCALE,
 	HUNGARIAN_MINOR,
 	HUNGARIAN_MAJOR,

 	SCALES_COUNT
 } ScaleTypes;

 static enum RomanType {
 	ZERO=0,
 	I,
 	II,
 	III,
 	IV,
 	V,
 	VI,
 	VII 	
 } RomanTypes;

 static int chords[CHORDS_COUNT][8];
 static int scales[SCALES_COUNT][7];

 static int fifths[7];
 static int progressionIntervals[7];

 static vector<int> getChord(int);
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
    float Length;
    vector<int> Pitches;
    int velfrom;
    int velto;
    vector<float> pattern;
};
 Pattern* newPattern(float,vector<int>,vector<float>,int,int);
 void realizePattern(RenderPart*,Pattern*);
 void setSong(Song*);
};
#endif // MUSICSCRIPT_H
