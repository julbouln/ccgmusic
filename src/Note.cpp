#include "Note.h"

Note::Note(Time start,Time end,int8_t pitch,int8_t volume,int8_t trackIndex,bool percussion) {
 this->start = start;
 this->end = end;
 this->pitch = pitch;
 this->volume = volume;
 this->trackIndex = trackIndex;
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
int8_t Note::getPitch() {
 return pitch;
}
int8_t Note::getVolume() {
 return volume;
}

bool Note::isPercussion() {
 return percussion;
}

 int8_t Note::getTrackIndex() {
 	return trackIndex;
 }