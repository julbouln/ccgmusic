#ifndef SONG_H
#define SONG_H
#include "Common.h"
#include "Seedable.h"
#include "Track.h"
#include "UniquePart.h"
#include "Part.h"
#include "TempoMod.h"
#include "RenderEvent.h"
#include "RenderNote.h"

//#include "SongCreator.h"
#include "Time.h"
#include "Utils.h"

using namespace std;
class SongCreator;
class Song : public Seedable
{
    int seed;
    vector<Track *> tracks;
    vector<UniquePart *> uniqueParts;
    vector<Part *> parts;
    vector<TempoMod *> tempoMods;
    int tempo;
    RenderEvent *latestRenderEvent;
    SongCreator *creator;

    vector<RenderNote*> notes;

public:
    vector<RenderEvent*> renderEvents;
    vector<RenderNote *> *getNotes();
    void sortNotes();
    void clearNotes();

    Song();
    ~Song();
    Song(SongCreator *);
    SongCreator *getCreator();
    int getTempo();
    void setTempo(int);
    void setSeed(int);
    vector<Track *> *getTracks();
    void setUniqueParts(int);
    int getUniqueParts();
    UniquePart *getUniquePart(int);
    void setParts(int);
    int getParts();
    Part *getPart(int);
    int getBars();
    int getPartStartBar(int);
    int getPartEndBar(int);
    void addTrack(string, int, int, int, bool);
    void addRenderEvent(string, int, int, int, int, int8_t, Time, float);
    void addRenderEvent(RenderEvent *);

    void setParam(int, int);
    void addTempoMod(Time, double);
    vector<TempoMod *> *getTempoMods();

    void sortRenderEvents();
};
#endif // SONG_H
