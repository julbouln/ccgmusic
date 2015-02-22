#include "AccentedMelody.h"
void AccentedMelody::render(RenderPart *p) {
 double max_len = 0.25;
 for(int i = 0;i < p->getEvents();++i ){
       Time t = p->getEventStart(i);
       int poz = (int)t.mPos;
       if((poz == 0 || poz == 2) && t.mPos - poz < 0.1) {
           p->addNote(p->getEventStart(i),p->getEventEnd(i),p->getEventPitch(i),this->rndInt(124,127));
    }
    else {
           double len = (p->getEventEnd(i).mBar - p->getEventStart(i).mBar) * p->getUniquePart()->getMetrum() + (p->getEventEnd(i).mPos - p->getEventStart(i).mPos);
           if(len > max_len) {
               p->addNote(p->getEventStart(i),this->createTime(p->getEventStart(i).mBar,p->getEventStart(i).mPos + max_len),p->getEventPitch(i),this->rndInt(85,105));
      }
      else {
       p->addNote(p->getEventStart(i),p->getEventEnd(i),p->getEventPitch(i),this->rndInt(85,105));
      }
    }
 }
}
