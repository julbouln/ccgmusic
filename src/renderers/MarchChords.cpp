#include "MarchChords.h"
void MarchChords::PlaceNextChord(RenderPart *p,Time t1) {
 int harm = p->getHarmonic(t1);
 for(int f = 0;f < p->getHarmonicComponents(harm);f++){
       int pit = p->computePitch(p->getHarmonicEventPitch(harm,f));
       while(pit > 70){
     pit -= 12;
    }
       while(pit < 48){
     pit += 12;
    }
       Time end = t1;
       end.mPos += this->rndFloat(0.12,0.18);
       p->addPercNote(t1,end,pit,this->rndInt(85,95));
 }
}
void MarchChords::render(RenderPart *p) {
 double step = 1.0;
 if(p->getTempo() < 70) {
  step /= 2.0;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       if(i % 2 == 1 && this->rndInt(0,1) == 0) {
           for(double m = 0;m < p->getUniquePart()->getMetrum();m += step){
                 if(m > 0) {
          this->PlaceNextChord(p,this->createTime(i,m));
         }
                 this->PlaceNextChord(p,this->createTime(i,m + step * 4.0 / 6.0));
                 if(this->rndInt(0,1) == 0 && m + step < p->getUniquePart()->getMetrum()) {
          this->PlaceNextChord(p,this->createTime(i,m + step * 8.0 / 6.0));
         }
      }
    }
    else {
           for(double m = 0;m < p->getUniquePart()->getMetrum();m += step){
                 this->PlaceNextChord(p,this->createTime(i,m + step * 4.0 / 6.0));
      }
    }
 }
}
