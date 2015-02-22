#include "RandomBass.h"
  RandomBass::RandomBass() {
      first_pitch = 0;
      last_pitch = 0;
  }

void RandomBass::SetFirstPitch(int f) {
 first_pitch = f;
 last_pitch = f;
}
int RandomBass::GetNextPitch(int p) {
 int cur_pitch = p;
 if(cur_pitch - 7 > last_pitch) {
  cur_pitch -= 12;
 }
 last_pitch = cur_pitch;
 return cur_pitch;
}
void RandomBass::render(RenderPart *p) {
 this->SetFirstPitch(p->getHarmonicEventPitch(0,0));
 double len = this->rndFloat(0.5,1.0);
 if(this->rndInt(0,1) == 0) {
  len = 0.98;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       for(int m = 0;m < p->getUniquePart()->getMetrum();++m    ){
             Time t = this->createTime(i,m);
             int vel = 127;
             if(m % 2 == 1) {
        vel = 115;
       }
             int harm = p->getHarmonic(t);
             if(harm == p->getHarmonicEvents() - 1) {
                 p->addNote(p->getHarmonicEventStart(p->getHarmonicEvents() - 1),p->getHarmonicEventEnd(p->getHarmonicEvents() - 1),this->GetNextPitch(p->getHarmonicEventPitch(p->getHarmonicEvents() - 1,0)),this->rndInt(115,126));
                 return;
       }
             Time t2 = t;
             t2.mPos += len;
             int nextPitch = this->GetNextPitch(p->getHarmonicEventPitch(harm,0));
             p->addNote(t,t2,nextPitch,this->rndInt(vel - 15,vel));
    }
 }
}
