#include "Note.h"
Note::~Note() {
}

Note::Note(Time start,Time end,int pitch,int volume,int trackIndex,bool percussion) {
 this->start = start;
 this->end = end;
 this->pitch = (int)pitch;
 this->volume = (int)volume;
 this->trackIndex = (int)trackIndex;
 this->percussion = percussion;
}
void Note::translate(int bars) {
 start = start.translateCopy(bars);
 end = end.translateCopy(bars);
}
void Note::translate(Time t) {
 start = start.translateCopy(t);
 end = end.translateCopy(t);
}
Time Note::getStart() {
 return start;
}
Time Note::getEnd() {
 return end;
}
int Note::getPitch() {
 return (int)pitch;
}
int Note::getVolume() {
 return (int)volume;
}

bool Note::isPercussion() {
 return percussion;
}

 int Note::getTrackIndex() {
 	return (int)trackIndex;
 }