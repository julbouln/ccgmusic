#include "ChordalMelody.h"
double ChordalMelody::GetNoteLength(RenderPart *p,int i) {
 Time t1 = p->getEventStart(i);
 Time t2 = p->getEventEnd(i);
 return (t2.mBar - t1.mBar) * p->getUniquePart()->getMetrum() + (t2.mPos - t1.mPos);
}
int ChordalMelody::abs(int v) {
 if(v < 0) {
  return -v;
 }
 return v;
}
double ChordalMelody::fabs(double v) {
 if(v < 0) {
  return -v;
 }
 return v;
}
void ChordalMelody::render(RenderPart *p) {
 for(int i = 0;i < p->getEvents();++i ){
       int note_pitch = p->getEventPitch(i);
       int poz = (int)p->getEventStart(i).mPos;
       bool strong = true;
       if(this->fabs(poz - p->getEventStart(i).mPos) > 0.1) {
     strong = false;
    }
       if(this->GetNoteLength(p,i) > 0.26) {
           Time t = p->getEventEnd(i);
           t.mPos -= 0.1;
           int harm = p->getHarmonic(t);
           for(int h = 0;h < p->getHarmonicComponents(harm);++h      ){
                 int off = 0;
                 int harm_pitch = p->getHarmonicEventPitch(harm,h);
                 while(harm_pitch + 12 < note_pitch){
                     ++off;
                     harm_pitch += 12;
         }
                 while(harm_pitch > note_pitch){
                     --off;
                     harm_pitch -= 12;
         }
                 int safe_dist = 2;
                 if(note_pitch != p->alignPitch(note_pitch,0)) {
          safe_dist = 3;
         }
                 if(this->abs(harm_pitch - note_pitch) > safe_dist) {
                     if(strong) {
            p->addNote(p->getEventStart(i),p->getEventEnd(i),harm_pitch,this->rndInt(85,110));
           }
           else {
            p->addNote(p->getEventStart(i),p->getEventEnd(i),harm_pitch,this->rndInt(75,100));
           }
         }
      }
    }
       if(strong) {
     p->addNote(p->getEventStart(i),p->getEventEnd(i),note_pitch,this->rndInt(118,127));
    }
    else {
     p->addNote(p->getEventStart(i),p->getEventEnd(i),note_pitch,this->rndInt(110,122));
    }
 }
}
