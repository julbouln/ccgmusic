#ifndef TIME_H
#define TIME_H
#include "Common.h"
using namespace std;
class Time {
public:
 int8_t mBar;
 double mPos;

 Time();
 Time(int,double);
 double getPosition(int);
 Time copy();
 void translate(int);
 void translate(Time);
 Time translateCopy(int);
 Time translateCopy(Time);
};
#endif // TIME_H
