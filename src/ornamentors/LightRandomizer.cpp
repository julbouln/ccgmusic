#include "LightRandomizer.h"

void LightRandomizer::ornament(UniquePart *up,Part *p) {
 bool skip = false;

 for(int i = 0;i < up->getEvents();++i ){
    if(i < up->getEvents() - 1 && !skip) {
      Time t = up->getEventStart(i);
      int poz = (int)t.mPos;
      double tmp = t.mPos - poz;
      if(abs(tmp) < 0.1) {
        p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i)));
      } else {
        skip = true;
          if(i > 0 && i < up->getEvents() - 1) {
            if(up->getEventPitch(i) != up->getEventPitch(i + 1) && up->getEventPitch(i) != up->getEventPitch(i - 1)) {
              p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i)));
              skip = false;
            }
          }

        if(skip) {
          if(up->getEventPitch(i) == up->getEventPitch(i + 1)) {
            if(this->rndInt(0,1) == 0) {
             p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i) + 1));
            } else {
             p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i) - 1));
            }
          }
          if(up->getEventPitch(i) > up->getEventPitch(i + 1)) {
            if(this->rndInt(0,1) == 0) {
             p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i) - 1));
            } else {
             p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i + 1) + 1));
            }
          }
          if(up->getEventPitch(i) < up->getEventPitch(i + 1)) {
            if(this->rndInt(0,1) == 0) {
             p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i) + 1));
            } else {
             p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i + 1)) - 1);
            }
          }
        }
      }
    } else {
      p->addEvent(up->getEventStart(i),up->getEventEnd(i),p->computePitch(up->getEventPitch(i)));
      skip = false;
    }
 }
}
