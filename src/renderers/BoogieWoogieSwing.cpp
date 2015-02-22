#include "BoogieWoogieSwing.h"
void BoogieWoogieSwing::render(RenderPart *p) {
 Time t = this->createTime(p->getStartBar(),0);
 double delta;
 double *delta_swing = new double[8];
 if(p->getTempo() > 90) {
  delta = 0.5;
 }
 else {
  delta = 0.25;
 }
 for(int i = 0;i < 8;++i ){
   delta_swing[i] = delta;
 }
 int vel[] = {127,118,125,115,127,115,127,127};
 for(int i = 0;i < 8;i += 2 ){
       if(this->rndInt(0,1) == 0) {
           delta_swing[i] *= 1.5;
           delta_swing[i + 1] *= 0.5;
    }
 }
 int scale[] = {0,7,2,3,3,4,-3,4};
 int diat_off[] = {0,0,0,0,1,0,0,0};
 int note = 0;
 int old_nhp = -1;
 double len_mult = 1.0;
 if(this->rndInt(0,1) == 0) {
  len_mult = 0.9;
 }
 while(t.mBar < p->getEndBar()){
     int nhp = p->getHarmonicEventPitch(p->getHarmonic(t),0);
     if(nhp != old_nhp) {
         note = 0;
         old_nhp = nhp;
   }
     Time t2 = Time();
     t2.mBar = t.mBar;
     t2.mPos = t.mPos + delta_swing[note] * len_mult;
     int chrPitch = p->alignPitch(nhp,scale[note]) + diat_off[note];
     p->addNote(t,t2,chrPitch,this->rndInt(vel[note] - 5,vel[note]));
     t.mPos += delta_swing[note];
     note = (note + 1) % 8;
     if(t.mPos >= p->getUniquePart()->getMetrum()) {
         ++t.mBar;
         t.mPos = 0;
         note = 0;
   }
 }
}
