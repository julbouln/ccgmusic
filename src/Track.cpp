#include "Track.h"
Track::~Track() {
//	printf("delete Track %x\n",this);
	Utils::deleteVector(renderEvents);
}

Track::Track(string name,int patch,int vol,int pan, bool percussion) {
 this->name = name;
 this->patch = patch;
 this->vol = vol;
 this->pan = pan;
 this->percussion=percussion;
}
string Track::getName() {
 return name;
}
int Track::getPatch() {
 return patch;
}
int Track::getVol() {
 return vol;
}
int Track::getPan() {
 return pan;
}
void Track::addRenderEvent(RenderEvent *event) {
 renderEvents.push_back(event);
}
vector<RenderEvent*> *Track::getRenderEvents() {
 return &renderEvents;
}

bool Track::isPercussion() {
	return percussion;
}

void Track::setAsPercussion() {
	percussion=true;
}