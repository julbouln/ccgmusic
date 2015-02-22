#include "ShortestWayChordsSmooth.h"
void ShortestWayChordsSmooth::SetFirstChord(RenderPart *p,int h) {
 przew = this->rndInt(-1,1);
 low = p->getHarmonicEventPitch(h,przew);
 high = p->getHarmonicEventPitch(h,przew + p->getHarmonicComponents(h) - 1);
}
int ShortestWayChordsSmooth::GetDist(RenderPart *p,int harm,int pr) {
 int l = p->getHarmonicEventPitch(harm,pr);
 int h = p->getHarmonicEventPitch(harm,pr + p->getHarmonicComponents(harm) - 1);
 int dist = 0;
 if(l < low) {
  dist += low - l;
 }
 else {
  dist += l - low;
 }
 if(h < high) {
  dist += high - h;
 }
 else {
  dist += h - high;
 }
 return dist;
}
void ShortestWayChordsSmooth::PlaceNextChord(RenderPart *p,Time t1,Time t2,double speed) {
 int harm = p->getHarmonic(t1);
 int pr = 0;
 int dist = this->GetDist(p,harm,pr);
 while(this->GetDist(p,harm,pr - 1) < dist){
     dist = this->GetDist(p,harm,pr - 1);
     --pr;
 }
 while(this->GetDist(p,harm,pr + 1) <= dist){
     dist = this->GetDist(p,harm,pr + 1);
     ++pr;
 }
 przew = pr;
 low = p->getHarmonicEventPitch(harm,przew);
 high = p->getHarmonicEventPitch(harm,przew + p->getHarmonicComponents(harm) - 1);
 t1.mPos -= speed * ((p->getHarmonicComponents(harm)) - 1);
 t2.mPos -= speed * ((p->getHarmonicComponents(harm)) - 1);
 for(int f = 0;f < p->getHarmonicComponents(harm);++f ){
       t1.mPos += speed;
       t2.mPos += speed;
       int pitch = p->getHarmonicEventPitch(harm,przew + f);
       p->addNote(t1,t2,pitch,this->rndInt(105,125));
 }
}
void ShortestWayChordsSmooth::render(RenderPart *p) {
 this->SetFirstChord(p,0);
 double speed = this->rndFloat(0.05,0.1);
 if(p->getTempo() > 110) {
  speed *= 1.8;
 }
 for(int i = 0;i < p->getHarmonicEvents();++i ){
       Time t1 = p->getHarmonicEventStart(i);
       Time t2 = p->getHarmonicEventEnd(i);
       this->PlaceNextChord(p,t1,t2,speed);
 }
}
