#ifndef ABSTRACTEVENT_H
#define ABSTRACTEVENT_H
#include "Common.h"
#include "Time.h"
#include "Interval2D.h"
using namespace std;
class ChromaticEvent;
class AbstractEvent {
 Time begin;
 Time end;
public:
 AbstractEvent(Time,Time);
 ~AbstractEvent();
 Interval2D toInterval2D(int);
 bool contains(Time,int);
 bool contains(Time,Time,Time,int);
 bool intersects(Time,Time,int);
 Interval2D intersect(Time,Time,int);
 AbstractEvent* translate(int);
 Time getStart();
 Time getEnd();
 bool operator<( const AbstractEvent& ) const;
};
#endif // ABSTRACTEVENT_H
