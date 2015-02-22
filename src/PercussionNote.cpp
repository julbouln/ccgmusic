#include "PercussionNote.h"
PercussionNote::PercussionNote(Time start,Time end,int key,int volume,int trackIndex) {
 this->start = start;
 this->end = end;
 this->key = (int)key;
 this->volume = (int)volume;
  this->trackIndex = trackIndex;

}
void PercussionNote::translate(int bars) {
 start = start.translateCopy(bars);
 end = end.translateCopy(bars);
}
void PercussionNote::translate(Time t) {
 start = start.translateCopy(t);
 end = end.translateCopy(t);
}
Time PercussionNote::getStart() {
 return start;
}
Time PercussionNote::getEnd() {
 return end;
}
int PercussionNote::getKey() {
 return key;
}
int PercussionNote::getVolume() {
 return volume;
}

 int PercussionNote::getTrackIndex() {
 	return trackIndex;
 }