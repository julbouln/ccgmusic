#include "RenderNote.h"

RenderNote::RenderNote(Time start,Time end,uint8_t pitch,uint8_t volume,uint8_t trackIndex,bool percussion) {
 this->start = start;
 this->end = end;
 this->pitch = pitch;
 this->volume = volume;
 this->trackIndex = trackIndex;
 this->percussion = percussion;
}
void RenderNote::translate(int bars) {
 start = start.translateCopy(bars);
 end = end.translateCopy(bars);
}
void RenderNote::translate(Time t) {
 start = start.translateCopy(t);
 end = end.translateCopy(t);
}
Time RenderNote::getStart() {
 return start;
}
Time RenderNote::getEnd() {
 return end;
}
int8_t RenderNote::getPitch() {
 return pitch;
}
int8_t RenderNote::getVolume() {
 return volume;
}

bool RenderNote::isPercussion() {
 return percussion;
}

 int8_t RenderNote::getTrackIndex() {
 	return trackIndex;
 }