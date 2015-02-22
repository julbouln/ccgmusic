#include "QuickIntroBass.h"
void QuickIntroBass::render(RenderPart *p) {
 int upto = p->getHarmonicEventPitch(0,0);
 Time t1 = Time();
 t1.mBar = p->getStartBar();
 t1.mPos = -1.5;
 double len = this->rndFloat(0.25,0.5);
 if(this->rndInt(0,1) == 0) {
     Time t2 = Time();
     t2 = t1;
     t2.mPos += len;
     p->addNote(t1,t2,upto - 3,102);
     t1.mPos += 0.5;
     t2.mPos = t1.mPos + len;
     p->addNote(t1,t2,upto - 2,110);
     t1.mPos += 0.5;
     t2.mPos = t1.mPos + len;
     p->addNote(t1,t2,upto - 1,115);
     t1.mPos = 0;
     t2.mPos = len;
     p->addNote(t1,t2,upto,127);
 }
 else {
     Time t2;
     t2 = t1;
     t2.mPos += len;
     p->addNote(t1,t2,p->alignPitch(upto,-3),102);
     t1.mPos += 0.5;
     t2.mPos = t1.mPos + len;
     p->addNote(t1,t2,p->alignPitch(upto,-2),102);
     t1.mPos += 0.5;
     t2.mPos = t1.mPos + len;
     p->addNote(t1,t2,p->alignPitch(upto,-1),102);
     t1.mPos = 0;
     t2.mPos = len;
     p->addNote(t1,t2,upto,127);
 }
}
