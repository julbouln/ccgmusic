#include "Harmonic.h"
#include "MusicScript.h"

Harmonic::~Harmonic() {
}

Harmonic::Harmonic() {
}
Interval2D Harmonic::toInterval2D(int metrum) {
 return Interval2D(startTime.getPosition(metrum),endTime.getPosition(metrum));
}

vector<int> Harmonic::getOffsets() {
	return MusicScript::getChord(chord);
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

// baseNote == scale degree
Harmonic::Harmonic(Time time,int baseNote,int chord) {
 this->startTime = time;
 this->baseNote = baseNote;
 this->chord = chord; 
}

vector<int> Harmonic::getScaleDegrees() {
	vector<int> scales;
	vector<int> chordData=MusicScript::getChord(chord);

	for(int i=0;i<chordData.size();i++) 
	 	scales.push_back((baseNote - 1 + chordData.at(i)) % 7);

	return scales;
}
void Harmonic::translate(int bars) {
 startTime = startTime.translateCopy(bars);
 endTime = endTime.translateCopy(bars);
}
