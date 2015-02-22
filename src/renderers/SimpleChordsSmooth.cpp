#include "SimpleChordsSmooth.h"
void SimpleChordsSmooth::render(RenderPart *p) {
 int div = 20;
 int speed = this->rndInt(0,2);
 if(speed == 0) {
  div = 20;
 }
 if(speed == 1) {
  div = 40;
 }
 if(speed == 2) {
  div = 12;
 }
 for(int i = 0;i < p->getHarmonicEvents();++i ){
       for(int f = 0;f < 3;++f    ){
             Time t1 = p->getHarmonicEventStart(i);
             Time t2 = p->getHarmonicEventEnd(i);
             t1.mPos -= (p->getHarmonicComponents(i) - f) / 20.0;
             t2.mPos -= (p->getHarmonicComponents(i) - f) / 20.0;
             p->addNote(t1,t2,p->getHarmonicEventPitch(i,f),127);
    }
 }
}
