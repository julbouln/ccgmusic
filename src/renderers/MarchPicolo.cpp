#include "MarchPicolo.h"
void MarchPicolo::render(RenderPart *p) {
 double step = 1.0;
 if(p->getTempo() < 70) {
  step /= 2.0;
 }
 int base = this->rndInt(-2,2);
 int mode = this->rndInt(0,1);
 int up = 1;
 int down = this->rndInt(1,2);
 int n = this->rndInt(0,1);
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       int w = 0;
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += step    ){
             int harm = p->getHarmonic(this->createTime(i,m));
             int pitch = p->getHarmonicEventPitch(harm,base);
             if(m + step >= p->getUniquePart()->getMetrum() && n == 0) {
                 for(int t = 0;t < 6;++t         ){
                       pitch = p->alignPitch(p->getHarmonicEventPitch(harm,base),t % 2);
                       if(t == 0) {
             p->addNote(this->createTime(i,m + step / 6.0 * t),this->createTime(i,m + 0.1 + step / 6.0 * t),pitch,this->rndInt(80,110));
            }
            else {
             p->addNote(this->createTime(i,m + step / 6.0 * t),this->createTime(i,m + 0.1 + step / 6.0 * t),pitch,this->rndInt(60,80));
            }
         }
       }
       else {
                 p->addNote(this->createTime(i,m),this->createTime(i,m + 0.1),pitch,this->rndInt(90,110));
                 if(n == 0 || w % 2 == 0) {
                     if(mode == 0) {
                         pitch = p->getHarmonicEventPitch(harm,base + up);
                         p->addNote(this->createTime(i,m + step * 2.0 / 6.0),this->createTime(i,m + 0.1 + step * 2.0 / 6.0),pitch,this->rndInt(80,95));
                         pitch = p->getHarmonicEventPitch(harm,base - down);
                         p->addNote(this->createTime(i,m + step * 4.0 / 6.0),this->createTime(i,m + 0.1 + step * 4.0 / 6.0),pitch,this->rndInt(80,95));
           }
           else {
                         pitch = p->getHarmonicEventPitch(harm,base - down);
                         p->addNote(this->createTime(i,m + step * 2.0 / 6.0),this->createTime(i,m + 0.1 + step * 2.0 / 6.0),pitch,this->rndInt(80,95));
                         pitch = p->getHarmonicEventPitch(harm,base + up);
                         p->addNote(this->createTime(i,m + step * 4.0 / 6.0),this->createTime(i,m + 0.1 + step * 4.0 / 6.0),pitch,this->rndInt(80,95));
           }
         }
       }
             ++w;
    }
       if(n == 0) {
     n = 1;
    }
    else {
     n = 0;
    }
 }
}
