#ifndef HARMONIC_H
#define HARMONIC_H
#include "Common.h"
#include "Time.h"
#include "Interval2D.h"
#include "Utils.h"

using namespace std;
class Harmonic {
 int *offsets;
 Time startTime;
 Time endTime;
 int8_t baseNote;
 int *chordData;
public:
 ~Harmonic();
 Harmonic();
 Interval2D toInterval2D(int);
 Harmonic* copy();
 int* getOffsets();
 Time getStartTime();
 Time getEndTime();
 int getBaseNote();
 int *getChordData();

 void setEndTime(Time);
 Harmonic(Time,int,int*);
 int* getScaleDegrees();
 void translate(int);
};
#endif // HARMONIC_H
