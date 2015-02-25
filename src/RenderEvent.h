#ifndef RENDEREVENT_H
#define RENDEREVENT_H
#include "Common.h"
#include "Time.h"
using namespace std;
class RenderEvent {
 string scriptName;
 int seed;
 int initialStep;
 int finalStep;
 int octave;
 Time timeOffset;
 float volMult;
 map<int,int> parameters;
public:
 int trackId;
enum ParamType {
 	SNARE=0,
 	FOOT,
 	CYMBAL,
 	FOOT_SNARE,
 	CHORUS_HIHAT,
 	VERSE_HIHAT,
 	INTRO_HIHAT,
 	TRANSITION,
 	PITCH,
 	MODE,
 	PARAMS_COUNT
 } ParamsType;

 ~RenderEvent();
 RenderEvent();
 RenderEvent(string,int,int,int,int,Time,double,int);
 int getParam(int);
 void setParam(int,int);
 string getScriptName();
 int getSeed();
 int getInitialStep();
 int getFinalStep();
 int getOctave();
 Time getTimeOffset();
 double getVolMult();

class Comparator {
	public:
 bool operator() ( const RenderEvent *lev, const RenderEvent *rev) {
	return (*lev).initialStep < (*rev).initialStep;
};

};

};
#endif // RENDEREVENT_H
