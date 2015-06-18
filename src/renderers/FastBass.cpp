#include "FastBass.h"
  FastBass::FastBass() {
      first_pitch = 0;
      last_pitch = 0;
  }

void FastBass::SetFirstPitch(int f) {
 first_pitch = f;
 last_pitch = f;
}
int FastBass::GetNextPitch(int p) {
 int cur_pitch = p;
 if(cur_pitch - 7 > last_pitch) {
  cur_pitch -= 12;
 }
 last_pitch = cur_pitch;
 return cur_pitch;
}
void FastBass::render(RenderPart *p) {
 this->SetFirstPitch(p->getHarmonicEventPitch(0,0));
 float speed = 0.5;
 if(p->getTempo() < 90) {
  speed /= 2.0;
 }
 if(p->getTempo() > 180) {
  speed *= 2.0;
 }
 float len = this->rndFloat(0.5,1.0);
 Time t = this->createTime(p->getStartBar(),0);
 int co = 4;
 if(this->rndInt(0,1) == 0) {
  co = 8;
 }
 int cnt = 0;
 while(t.mBar < p->getEndBar()){
     int harm = p->getHarmonic(t);
     ++cnt;
     if(this->rndInt(0,2) != 0) {
         if(cnt % co == 0) {
             p->addNote(t,this->createTime(t.mBar,t.mPos + speed * len),this->GetNextPitch(p->getHarmonicEventPitch(harm,this->rndInt(-1,1))),this->rndInt(120,126));
     }
     else {
      p->addNote(t,this->createTime(t.mBar,t.mPos + speed * len),this->GetNextPitch(p->getHarmonicEventPitch(harm,0)),this->rndInt(120,126));
     }
   }
   else {
         if(cnt % co == 0) {
             int up = this->rndInt(-1,1);
             p->addNote(t,this->createTime(t.mBar,t.mPos + speed * len / 2),this->GetNextPitch(p->getHarmonicEventPitch(harm,up)),this->rndInt(120,126));
             p->addNote(this->createTime(t.mBar,t.mPos + speed / 2),this->createTime(t.mBar,t.mPos + speed / 2 + ((speed / 2) * len)),this->GetNextPitch(p->getHarmonicEventPitch(harm,up)),this->rndInt(120,126));
     }
     else {
             p->addNote(t,this->createTime(t.mBar,t.mPos + speed * len / 2),this->GetNextPitch(p->getHarmonicEventPitch(harm,0)),this->rndInt(120,126));
             p->addNote(this->createTime(t.mBar,t.mPos + speed / 2),this->createTime(t.mBar,t.mPos + speed / 2 + ((speed / 2) * len)),this->GetNextPitch(p->getHarmonicEventPitch(harm,0)),this->rndInt(120,126));
     }
   }
     t.mPos += speed;
     if(t.mPos >= p->getUniquePart()->getMetrum() - 0.1) {
         t.mPos = 0;
         ++t.mBar;
   }
 }
}
