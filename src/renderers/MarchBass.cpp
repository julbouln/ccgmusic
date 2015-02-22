#include "MarchBass.h"
void MarchBass::render(RenderPart *p) {
 double step = 1.0;
 if(p->getTempo() < 70) {
  step /= 2.0;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       int n = 0;
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += step    ){
             if(m + step >= p->getUniquePart()->getMetrum() && this->rndInt(0,2) != 0) {
                 Time t = this->createTime(i,m);
                 int harm = p->getHarmonic(t);
                 int basis = p->getHarmonicEventPitch(harm,2) - 12;
                 double len = step / 3.0;
                 p->addNote(t,this->createTime(i,m + len),p->alignPitch(p->getHarmonicEventPitch(harm,0),-3),95);
                 p->addNote(this->createTime(i,m + len),this->createTime(i,m + len * 2),p->alignPitch(p->getHarmonicEventPitch(harm,0),-2),100);
                 p->addNote(this->createTime(i,m + len * 2),this->createTime(i,m + step),p->alignPitch(p->getHarmonicEventPitch(harm,0),-1),105);
       }
       else {
                 Time t = this->createTime(i,m);
                 int harm = p->getHarmonic(t);
                 int basis = p->getHarmonicEventPitch(harm,0);
                 if(this->rndInt(0,3) == 0) {
          n = this->rndInt(0,1);
         }
                 if(n == 1) {
          basis = p->getHarmonicEventPitch(harm,2) - 12;
         }
                 Time end = t;
                 end.mPos += step * 0.3;
                 p->addNote(t,end,basis,this->rndInt(100,119));
                 if(n == 0) {
          n = 1;
         }
         else {
          n = 0;
         }
       }
    }
 }
}
