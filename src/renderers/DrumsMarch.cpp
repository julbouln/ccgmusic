#include "DrumsMarch.h"
void DrumsMarch::DoSnare(RenderPart *p) {
 double step = 1.0;
 if(p->getTempo() < 70) {
  step /= 2.0;
 }
 double len = p->getUniquePart()->getMetrum() / step;
 int pat_len = (int)(this->rndInt(1,2) * len);
 int *pattern = new int[pat_len];
 for(int i = 0;i < pat_len;++i ){
   pattern[i] = this->rndInt(0,2);
 }
 int n = 0;
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += step    ){
             p->addPercNote(this->createTime(i,m),this->createTime(i,m + 0.1),40,127);
             int doit = pattern[n % pat_len];
             if(this->rndInt(0,2) == 0) {
        doit = this->rndInt(0,2);
       }
             if(doit == 0 || doit == 1) {
        p->addPercNote(this->createTime(i,m + step * 5.0 / 8.0),this->createTime(i,m + 0.1 + step * 5.0 / 8.0),38,this->rndInt(90,100));
       }
             if(doit == 1) {
        p->addPercNote(this->createTime(i,m + step * 2.5 / 8.0),this->createTime(i,m + 0.1 + step * 2.5 / 8.0),40,this->rndInt(80,100));
       }
             if(doit == 2) {
                 p->addPercNote(this->createTime(i,m + step * 4.0 / 6.0),this->createTime(i,m + 0.1 + step * 4.0 / 6.0),40,this->rndInt(80,90));
                 p->addPercNote(this->createTime(i,m + step * 5.0 / 6.0),this->createTime(i,m + 0.1 + step * 5.0 / 6.0),38,this->rndInt(90,100));
       }
             ++n;
    }
 }
}
void DrumsMarch::DoFoot(RenderPart *p) {
 double step = 1.0;
 if(p->getTempo() < 70) {
  step /= 2.0;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += step    ){
      p->addPercNote(this->createTime(i,m),this->createTime(i,m + 0.1),36,this->rndInt(75,95));
    }
       if(this->rndInt(0,1) == 0) {
     p->addPercNote(this->createTime(i,p->getUniquePart()->getMetrum() - step * 0.25),this->createTime(i,p->getUniquePart()->getMetrum() - step * 0.1),36,this->rndInt(65,85));
    }
 }
}
void DrumsMarch::DoCymbal(RenderPart *p) {
 double step = 1.0;
 if(p->getTempo() < 70) {
  step /= 2.0;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       int n = 0;
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += step    ){
             if(n == 0 || (n == 1 && this->rndInt(0,1) == 0)) {
        p->addPercNote(this->createTime(i,m),this->createTime(i,m + 0.1),59,this->rndInt(85,115));
       }
             if(n == 0) {
        n = 1;
       }
       else {
        n = 0;
       }
    }
 }
}
void DrumsMarch::render(RenderPart *p) {
 if(p->getParam(RenderEvent::SNARE) > 0) {
  this->DoSnare(p);
 }
 if(p->getParam(RenderEvent::FOOT) > 0) {
  this->DoFoot(p);
 }
 if(p->getParam(RenderEvent::CYMBAL) > 0) {
  this->DoCymbal(p);
 }
}
