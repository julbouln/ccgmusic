#ifndef UNIQUEPART_H
#define UNIQUEPART_H
#include "Common.h"
#include "UniquePhrase.h"
#include "Sentence.h"
#include "Harmonic.h"
#include "Event.h"
//#include "Song.h"
#include "Time.h"
//#include "ArrayUtils.h"
#include "Utils.h"

#define INT_MAX 32767

using namespace std;
class Song;
class UniquePart {
 int metrum;
 int structureSeed;
 int rythmSeed;
 int harmonySeed;
 int melodySeed;
 int ornamentationSeed;
 string structureScript;
 string rythmScript;
 string harmonyScript;
 string melodyScript;
 string ornamentationScript;
 vector<UniquePhrase*> uniquePhrases;
 vector<Sentence*> sentences;
 vector<Harmonic*> harmonics;
 vector<Event*> events;
 map<Event*,Harmonic*> eventHarmony;
public:
 ~UniquePart();
 UniquePart();
 void randomize(Song*);
 vector<Event*> *getEventList();
 vector<Harmonic*> *getHarmonicList();
 void assignEventsToHarmony();
 void setSentences(int);
 int getSentences();
 Sentence* getSentence(int);
 void setUniquePhrases(int);
 int getUniquePhrases();
 UniquePhrase* getUniquePhrase(int);
 void setMetrum(int);
 int getMetrum();
 int getBars();
 bool endsSong();
 int getEvents();
 Time getEventStart(int);
 Time getEventEnd(int);
 int getEventPitch(int);
 int setEventPitch(int,int);
 void setScriptStructure(string);
 void setScriptRhythm(string);
 void setScriptMelody(string);
 void setScriptHarmony(string);
 void setScriptOrnamentation(string);
 string getScriptStructure();
 string getScriptRhythm();
 string getScriptMelody();
 string getScriptHarmony();
 string getScriptOrnamentation();
 int getScriptStructureSeed();
 int getScriptRhythmSeed();
 int getScriptMelodySeed();
 int getScriptHarmonySeed();
 int getScriptOrnamentationSeed();
 void setScriptStructureSeed(int);
 void setScriptRhythmSeed(int);
 void setScriptMelodySeed(int);
 void setScriptHarmonySeed(int);
 void setScriptOrnamentationSeed(int);
 int getEventBasis(int);
 void addHarmonic(Time,int,int*);
 int alignPitchToHarm(int,int);
 void addEvent(Event*);
 Harmonic* getEventHarmonic(Event*);
};
#endif // UNIQUEPART_H
