#include "Harmonic.h"

Harmonic::~Harmonic() {
	offsets.clear();
//      delete offsets;
  //    delete chordData;
}

Harmonic::Harmonic() {
}
Interval2D Harmonic::toInterval2D(int metrum) {
 return Interval2D(startTime.getPosition(metrum),endTime.getPosition(metrum));
}
Harmonic* Harmonic::copy() {
 Harmonic *result = new Harmonic();

 result->offsets=offsets;
 result->startTime = startTime;
 result->endTime = endTime;
 result->baseNote = baseNote;

 return result;
}
vector<int> Harmonic::getOffsets() {
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

void Harmonic::setEndTime(Time t) {
 endTime = t;
}
Harmonic::Harmonic(Time time,int baseNote,vector<int> chordData) {
 this->startTime = time;
 this->baseNote = baseNote;
// offsets=chordData;
 for(int i=0;i<chordData.size();i++) 
 	offsets.push_back(chordData.at(i) - 1);

}
vector<int> Harmonic::getScaleDegrees() {
	vector<int> result;
//	printf("Harmonic::getScaleDegrees %d\n",baseNote);
	for(int i=0;i<offsets.size();i++) {
		int t=offsets.at(i);
//		int t=Utils::half2tone(offsets.at(i));
//		if(t==-1)
//			printf("ERROR invalid tone %d %d\n",i,offsets.at(i));
//       int scale=(baseNote - 1 + offsets.at(i)) % 7;
       int scale=(baseNote - 1 + t) % 7;

  //     printf("Harmonic::getScaleDegrees scale %d(%s) %d %d\n",baseNote-1,Utils::midiToNote(baseNote-1).c_str(),offsets.at(i),scale);

       result.push_back(scale);
	}

 return result;
}
void Harmonic::translate(int bars) {
 startTime = startTime.translateCopy(bars);
 endTime = endTime.translateCopy(bars);
}
