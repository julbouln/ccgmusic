#include "SimpleBass.h"
void SimpleBass::render(RenderPart *p) {
 for(int i = 0;i < p->getHarmonicEvents();++i ){
       Time start = p->getHarmonicEventStart(i);
       while(i + 1 < p->getHarmonicEvents() && p->getHarmonicEventPitch(i + 1,0) == p->getHarmonicEventPitch(i,0)){
           ++i;
    }
       Time end = p->getHarmonicEventEnd(i);
       int pitch = p->getHarmonicEventPitch(i,0);
       p->addNote(start,end,p->getHarmonicEventPitch(i,0),127);
 }
}
