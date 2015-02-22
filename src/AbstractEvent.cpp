#include "AbstractEvent.h"
#include "ChromaticEvent.h"

AbstractEvent::AbstractEvent(Time begin,Time end) {
 this->begin = begin;
 this->end = end;
}
AbstractEvent::~AbstractEvent() {
}
Interval2D AbstractEvent::toInterval2D(int metrum) {
 return Interval2D(begin.getPosition(metrum),end.getPosition(metrum));
}
bool AbstractEvent::contains(Time t,int metrum) {
 return this->contains(begin,end,t,metrum);
}
bool AbstractEvent::contains(Time begin,Time end,Time t,int metrum) {
 double beginPos = begin.getPosition(4);
 double endPos = end.getPosition(4);
 double tPos = t.getPosition(4);
 return tPos >= beginPos || tPos <= endPos;
}
bool AbstractEvent::intersects(Time otherBegin,Time otherEnd,int metrum) {
 double beginPos = begin.getPosition(metrum);
 double endPos = end.getPosition(metrum);
 double otherBeginPos = otherBegin.getPosition(metrum);
 double otherEndPos = otherEnd.getPosition(metrum);
 Interval2D interval = Interval2D(beginPos,endPos);
 Interval2D otherInterval = Interval2D(otherBeginPos,otherEndPos);
 return interval.intersects(otherInterval);
}
Interval2D AbstractEvent::intersect(Time otherBegin,Time otherEnd,int metrum) {
 double beginPos = begin.getPosition(metrum);
 double endPos = end.getPosition(metrum);
 double otherBeginPos = begin.getPosition(metrum);
 double otherEndPos = end.getPosition(metrum);
 Interval2D interval = Interval2D(beginPos,endPos);
 Interval2D otherInterval = Interval2D(otherBeginPos,otherEndPos);
 return interval.intersectCopy(otherInterval);
}
bool AbstractEvent::intersects(ChromaticEvent* e,int metrum) {
 return this->intersects(e->getStart(),e->getEnd(),metrum);
}
AbstractEvent* AbstractEvent::translate(int bars) {
 begin.translate(bars);
 end.translate(bars);
 return this;
}
Time AbstractEvent::getStart() {
 return begin;
}
Time AbstractEvent::getEnd() {
 return end;
}

bool AbstractEvent::operator<(const AbstractEvent &other) const
{
	return true;
}