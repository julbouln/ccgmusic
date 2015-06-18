#include "Interval2D.h"
Interval2D::Interval2D() {
  lower = 0.0;
  upper = 1.0;
}
Interval2D::Interval2D(double lower,double upper) {
 this->lower = lower;
 this->upper = upper;
 if(lower > upper) {
     lower = upper;
 }
}
bool Interval2D::within(Interval2D interval) {
 return interval.lower >= lower && interval.upper <= upper;
}

double Interval2D::distanceBetween(Interval2D interval) {
 if(this->intersects(interval)) {
     return 0.0;
 }
 else {
  if(interval.lower >= upper) {
       return interval.lower - upper;
  }
  else {
   if(interval.upper <= lower) {
         return lower - interval.upper;
   }
   else {
      printf("ERROR found a distanceBetween() case that is impossible\n");
//         cout  << (this->toString() + " found a distanceBetween() case that is impossible :) " + this->toString() + " " + interval) << endl;
         return 0.0;
   }
  }
 }
}
Interval2D Interval2D::intersect(Interval2D interval) {
 Interval2D r=Interval2D(this->lower,this->upper);
 if(this->intersects(interval)) {
     r.lower = max(r.lower,interval.lower);
     r.upper = min(r.upper,interval.upper);
 }
 else {
     r.upper = r.lower;
 }
 return r;
}

bool Interval2D::intersects(Interval2D interval) {
 if(interval.upper < lower || upper < interval.lower) {
     return false;
 }
 else {
     return true;
 }
}
Interval2D Interval2D::merge(Interval2D interval) {
   Interval2D r=Interval2D(this->lower,this->upper);

 r.lower = min(r.lower,interval.lower);
 r.upper = max(r.upper,interval.upper);
 return r;
}

bool Interval2D::contains(double p) {
 return p >= lower && p <= upper;
}
double Interval2D::getLength() {
 return abs(upper - lower);
}
Interval2D Interval2D::getIntervalBefore(double point) {
 return Interval2D(lower,min(upper,point));
}
Interval2D Interval2D::getIntervalAfter(double point) {
 return Interval2D(min(upper,point),upper);
}
