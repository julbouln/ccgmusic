#include "RandomStaticRythm.h"

void RandomStaticRythm::generateRythm(UniquePhrase *up) {
 int bars = up->getBars();
 if(up->endsSentence()) {
  bars--;
 }
 Time poz = Time(0,0);
 int start = this->rndInt(0,4);
 if(start == 0) {
     poz.mBar = 0;
     poz.mPos = -1;
 }
 if(start == 1) {
     poz.mBar = 0;
     poz.mPos = -0.5;
 }
 if(start == 2) {
     poz.mBar = 0;
     poz.mPos = 0;
 }
 if(start == 3) {
     poz.mBar = 0;
     poz.mPos = 0.5;
 }
 if(start == 4) {
     poz.mBar = 0;
     poz.mPos = 1;
 }
 double delta;
 int mode = this->rndInt(0,3);
 if(mode == 0) {
  delta = 2;
 }
 if(mode == 1) {
  delta = 1;
 }
 if(mode == 2) {
  delta = 0.5;
 }
 if(mode == 3 && this->getSongTempo() < 130) {
  delta = 0.25;
 }
 else {
  delta = 0.5;
 }
 while(poz.mBar < bars){
     Time t2 = poz;
     t2.mPos += delta;
     if(t2.mPos >= up->getMetrum()) {
    t2.mPos = up->getMetrum();
   }
     up->addEvent(poz,t2);
     poz.mPos += delta;
     if(poz.mPos >= up->getMetrum()) {
         poz.mPos = 0;
         ++poz.mBar;
   }
 }
 if(up->endsSentence()) {
  up->addEvent(this->createTime(up->getBars() - 1,0),this->createTime(up->getBars() - 1,up->getMetrum()));
 }
}
