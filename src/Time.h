#ifndef TIME_H
#define TIME_H
#include "Common.h"
using namespace std;
class Time {
public:
 int8_t mBar;
 float mPos;

 Time();
 Time(int8_t,float);
 double getPosition(int);
 Time copy();
 void translate(int);
 void translate(Time);
 Time translateCopy(int);
 Time translateCopy(Time);

 string toString();
};
#endif // TIME_H
