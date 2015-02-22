#ifndef TRACK_H
#define TRACK_H
#include "Common.h"
#include "RenderEvent.h"
#include "Utils.h"

using namespace std;
class Track {
 string name;
 int patch;
 int vol;
 int pan;
 bool percussion;
 vector<RenderEvent*> renderEvents;
public:
 ~Track();
 Track(string,int,int,int,bool);
 string getName();
 int getPatch();
 int getVol();
 int getPan();
 void addRenderEvent(RenderEvent*);
 bool isPercussion();
 void setAsPercussion();

 vector<RenderEvent*> *getRenderEvents();
};
#endif // TRACK_H
