#include "RandomBassExtended.h"
RandomBassExtended::RandomBassExtended() {
      first_pitch = 0;
      last_pitch = 0;
  }
void RandomBassExtended::SetFirstPitch(int f) {
 first_pitch = f;
 last_pitch = f;
}
int RandomBassExtended::GetNextPitch(int p) {
 int cur_pitch = p;
 if(cur_pitch - 7 > last_pitch) {
  cur_pitch -= 12;
 }
 last_pitch = cur_pitch + this->rndInt(-3,3);
 return cur_pitch;
}
void RandomBassExtended::render(RenderPart *p) {
 this->SetFirstPitch(p->getHarmonicEventPitch(0,0));
 int mode = this->rndInt(0,1);
 if(p->getParam(RenderEvent::MODE) > 0) {
  mode = p->getParam(RenderEvent::MODE) - 1;
 }
 if(mode == 0) {
     double delta = 0.5;
     for(int i = 0;i < p->getHarmonicEvents();++i   ){
           if(this->rndInt(0,5) == 0 || i == p->getHarmonicEvents() - 1) {
               p->addNote(p->getHarmonicEventStart(i),p->getHarmonicEventEnd(i),this->GetNextPitch(p->getHarmonicEventPitch(i,0)),this->rndInt(122,127));
      }
      else {
               p->addNote(p->getHarmonicEventStart(i),this->createTime(p->getHarmonicEventEnd(i).mBar,p->getHarmonicEventEnd(i).mPos - delta),this->GetNextPitch(p->getHarmonicEventPitch(i,0)),this->rndInt(122,127));
               p->addNote(this->createTime(p->getHarmonicEventEnd(i).mBar,p->getHarmonicEventEnd(i).mPos - delta),p->getHarmonicEventEnd(i),this->GetNextPitch(p->getHarmonicEventPitch(i,this->rndInt(0,2)) - 12 * this->rndInt(0,1)),this->rndInt(122,127));
      }
   }
 }
 else {
     double len = this->rndFloat(0.5,1.0);
     if(this->rndInt(0,1) == 0) {
    len = 0.98;
   }
     int len_mode = this->rndInt(0,1);
     double speed = 1;
     if(p->getTempo() < 90) {
    speed = 0.5;
   }
     for(int i = p->getStartBar();i < p->getEndBar();++i   ){
           for(double m = 0;m < p->getUniquePart()->getMetrum();m += speed      ){
                 Time t = this->createTime(i,m);
                 int vel = 127;
                 if((int)m % 2 == 1) {
          vel = 122;
         }
                 int harm = p->getHarmonic(t);
                 if(harm == p->getHarmonicEvents() - 1) {
                     p->addNote(p->getHarmonicEventStart(p->getHarmonicEvents() - 1),p->getHarmonicEventEnd(p->getHarmonicEvents() - 1),this->GetNextPitch(p->getHarmonicEventPitch(p->getHarmonicEvents() - 1,0)),this->rndInt(115,126));
                     return;
         }
                 Time t2 = t;
                 if(len_mode == 0) {
          t2.mPos += len * speed;
         }
         else {
          t2.mPos += this->rndFloat(0.5,1.0) * speed;
         }
                 if(this->rndInt(0,2) != 0) {
          p->addNote(t,t2,this->GetNextPitch(p->getHarmonicEventPitch(harm,0)),this->rndInt(vel - 15,vel));
         }
         else {
          p->addNote(t,t2,this->GetNextPitch(p->getHarmonicEventPitch(harm,this->rndInt(-2,2))),this->rndInt(vel - 15,vel));
         }
      }
   }
 }
}
