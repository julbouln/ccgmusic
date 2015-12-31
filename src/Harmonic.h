#ifndef HARMONIC_H
#define HARMONIC_H
#include "Common.h"
#include "Time.h"
#include "Interval2D.h"
#include "Utils.h"

using namespace std;
class Harmonic {
 Time startTime;
 Time endTime;
 int8_t baseNote;
 int chord;

public:
 ~Harmonic();
 Harmonic();
 Interval2D toInterval2D(int);
 vector<int> getOffsets();
 Time getStartTime();
 Time getEndTime();
 int getBaseNote();

 void setEndTime(Time);
 Harmonic(Time,int,int);
 vector<int> getScaleDegrees();
 void translate(int);
};
#endif // HARMONIC_H
