#include "Harmonic.h"

Harmonic::~Harmonic() {
      delete offsets;
      delete chordData;
}

Harmonic::Harmonic() {
}
Interval2D Harmonic::toInterval2D(int metrum) {
 return Interval2D(startTime.getPosition(metrum),endTime.getPosition(metrum));
}
Harmonic* Harmonic::copy() {
 Harmonic *result = new Harmonic();

 result->offsets=new int[Utils::arrayLength(offsets)];
 for(int i=0;i < Utils::arrayLength(offsets);i++) {
      result->offsets[i]=offsets[i];
 }
 
 result->startTime = startTime;
 result->endTime = endTime;
 result->baseNote = baseNote;

 result->chordData = new int[Utils::arrayLength(chordData)];
for(int i=0;i < Utils::arrayLength(chordData);i++) {
      result->chordData[i]=chordData[i];
 }
 return result;
}
int* Harmonic::getOffsets() {
 return offsets;
}

Time Harmonic::getStartTime() {
 return startTime;
}
Time Harmonic::getEndTime() {
 return endTime;
}
int Harmonic::getBaseNote() {
 return baseNote;
}
int * Harmonic::getChordData() {
 return chordData;
}

void Harmonic::setEndTime(Time t) {
 endTime = t;
}
Harmonic::Harmonic(Time time,int baseNote,int * chordData) {
 this->startTime = time;
 this->baseNote = baseNote;
 this->chordData = chordData;
 offsets = new int[Utils::arrayLength(chordData)];

 for(int i = 0;i < Utils::arrayLength(chordData);++i ){
       switch(chordData[i]){
      case 1:
       offsets[i] = 0;
       break;
      case 2:
       offsets[i] = 1;
       break;
      case 3:
       offsets[i] = 2;
       break;
      case 4:
       offsets[i] = 3;
       break;
      case 5:
       offsets[i] = 4;
       break;
      case 6:
       offsets[i] = 5;
       break;
      case 7:
       offsets[i] = 6;
       break;
    }
 }
}
int* Harmonic::getScaleDegrees() {

 int *result = new int[Utils::arrayLength(offsets)];
 for(int i = 0;i < Utils::arrayLength(offsets);++i ){
       result[i] = (baseNote - 1 + offsets[i]) % 7;
 }
 return result;
}
void Harmonic::translate(int bars) {
 startTime = startTime.translateCopy(bars);
 endTime = endTime.translateCopy(bars);
}
