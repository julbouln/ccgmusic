#ifndef INTERVAL2D_H
#define INTERVAL2D_H
#include "Common.h"

using namespace std;
class Interval2D {
 double lower;
 double upper;
public:
 Interval2D();
 Interval2D(double,double);
 bool within(Interval2D);
 Interval2D copy();
 double distanceBetween(Interval2D);
 Interval2D intersect(Interval2D);
 Interval2D intersectCopy(Interval2D);
 bool intersects(Interval2D);
 Interval2D merge(Interval2D);
 bool contains(double);
 double getLength();
 Interval2D getIntervalBefore(double);
 Interval2D getIntervalAfter(double);
};
#endif // INTERVAL2D_H
