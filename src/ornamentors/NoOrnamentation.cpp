#include "NoOrnamentation.h"
void NoOrnamentation::ornament(UniquePart *up,Part *p) {
 for(int i = 0;i < up->getEvents();++i ){
   p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i)));
 }
}
