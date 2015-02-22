#include "SimpleChords.h"
void SimpleChords::render(RenderPart *p) {
 for(int i = 0;i < p->getHarmonicEvents();++i ){
       for(int f = 0;f < p->getHarmonicComponents(i);++f    ){
             p->addNote(p->getHarmonicEventStart(i),p->getHarmonicEventEnd(i),p->getHarmonicEventPitch(i,f),127);
    }
 }
}
