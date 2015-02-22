#ifndef RENDERPART_H
#define RENDERPART_H
#include "Common.h"
#include "ChromaticEvent.h"
#include "Harmonic.h"
#include "Part.h"
#include "UniquePart.h"
#include "RenderEvent.h"
#include "Note.h"
#include "PercussionNote.h"
#include "Song.h"
#include "Time.h"
#include "Interval2D.h"
#include "Utils.h"

using namespace std;
class RenderPart {
 int trackIndex;
 vector<ChromaticEvent*> chromaticEvents;
 vector<Harmonic*> harmonics;
 Part *part;
 UniquePart *uniquePart;
 RenderEvent *renderEvent;
 vector<Note*> notes;
 Song *song;
public:
 int getTrackIndex();
 vector<Note*> *getNotes();
 void setData(Part*,UniquePart*,RenderEvent*,Song*);
 ~RenderPart();
 RenderPart(int);
 int getEvents();
 int getHarmonic(Time);
 Time getEventStart(int);
 Time getEventEnd(int);
 int getEventPitch(int);
 int getHarmonicEvents();
 int getHarmonicComponents(int);
 int getHarmonicEventPitch(int,int);
 Time getHarmonicEventStart(int);
 Time getHarmonicEventEnd(int);
 int alignPitch(int,int);
 int computePitch(int);
 void addNote(Time,Time,int,int);
 void addPercNote(Time,Time,int,int);
 int getTempo();
 int getArrHint();
 int getStartBar();
 int getEndBar();
 UniquePart* getUniquePart();
 int getParam(int);
 void translateNotes(int);
 void translateNotes(Time);
 Part* getPart();
 bool isDrumPart();
};
#endif // RENDERPART_H
