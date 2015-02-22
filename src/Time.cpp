#include "Time.h"

Time::Time() {
}
Time::Time(int bar,double pos) {
 this->mBar = bar;
 this->mPos = pos;
}
double Time::getPosition(int metrum) {
 return mBar + mPos / metrum;
}
Time Time::copy() {
 return Time(mBar,mPos);
}
void Time::translate(int bars) {
 mBar += bars;
}
void Time::translate(Time t) {
 mBar += t.mBar;
 mPos += t.mPos;
}
Time Time::translateCopy(int bars) {
 Time copy = this->copy();
 copy.translate(bars);
 return copy;
}
Time Time::translateCopy(Time t) {
 Time copy = this->copy();
 copy.translate(t);
 return copy;
}
