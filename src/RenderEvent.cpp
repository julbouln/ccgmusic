#include "RenderEvent.h"

RenderEvent::RenderEvent()
{
}

RenderEvent::~RenderEvent() {
	parameters.clear();
}

RenderEvent::RenderEvent(string scriptName,int seed,int initialBar,int finalBar,int8_t octave,Time timeOffset,float volMult, int trackId) {
 this->scriptName = scriptName;
 this->seed = seed;
 this->initialStep = (uint8_t)initialBar;
 this->finalStep = (uint8_t)finalBar;
 this->octave = octave;
 this->timeOffset = timeOffset;
 this->volMult = volMult;
 this->trackId = trackId;
// printf("RenderEvent::RenderEvent initialStep:%d finalStep:%d octave:%d \n",initialStep,finalStep,octave);
}
int RenderEvent::getParam(int param) {

	if (parameters.count(param) > 0) {
		return parameters.at(param);
	}
	else {
		return 0;
	}
}

void RenderEvent::setParam(int param,int value) {

 parameters[param]=value;
}
string RenderEvent::getScriptName() {
 return scriptName;
}
int RenderEvent::getSeed() {
 return seed;
}
int RenderEvent::getInitialStep() {
 return initialStep;
}
int RenderEvent::getFinalStep() {
 return finalStep;
}
int RenderEvent::getOctave() {
 return octave;
}
Time RenderEvent::getTimeOffset() {
 return timeOffset;
}
double RenderEvent::getVolMult() {
 return volMult;
}

