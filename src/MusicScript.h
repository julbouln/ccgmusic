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

static enum TriadChordType {
	MAJOR_TRIAD_CHORD=0,
	MAJ7_TRIAD_CHORD,
	SUS2_TRIAD_CHORD,
	SUS4_TRIAD_CHORD, 
	TRIAD_CHORDS_COUNT
} TriadChordTypes;

static enum QuadChordType {
	MAJ7_QUAD_CHORD=0,
	MAJ6_QUAD_CHORD,
	QUAD_CHORDS_COUNT
} QuadChordTypes;

static enum FifthChordType {
	MAJ7_FIFTH_CHORD=0,

	FIFTH_CHORDS_COUNT
} FifthChordTypes;

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
 	GYPSY_SCALE,
 	DOUBLE_HARMONIC_SCALE,
 	ENIGMATIC_SCALE,
 	FLAMENCO_SCALE,
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

 static int triadChords[TRIAD_CHORDS_COUNT][3];
 static int quadChords[QUAD_CHORDS_COUNT][4];
 static int fifthChords[FIFTH_CHORDS_COUNT][5];

 static int scales[SCALES_COUNT][7];

 static vector<int> triadChord(int);
 static vector<int> quadChord(int);
 static vector<int> fifthChord(int);

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
