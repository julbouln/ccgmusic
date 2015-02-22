#include "DrumsDanceSnareAttack.h"
void DrumsDanceSnareAttack::render(RenderPart *p) {
 double speed = 0.25;
 double vel_from = 30 + this->rndInt(0,20);
 double vel_off = 90 - vel_from;
 double delta = (p->getEndBar() - p->getStartBar()) * p->getUniquePart()->getMetrum();
 double alpha = 0;
 int speed_up = this->rndInt(0,2);
 int mode = this->rndInt(0,1);
 if(p->getTempo() < 90) {
  speed /= 2.0;
 }
 if(p->getEndBar() - p->getStartBar() < 3) {
  speed_up = 0;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       Time t = this->createTime(i,0);
       while(t.mPos < p->getUniquePart()->getMetrum()){
           Time t2 = this->createTime(i,t.mPos + 0.1);
           p->addPercNote(t,t2,38,(int)(vel_from + ((alpha / delta) * vel_off)));
           if(mode == 0) {
       p->addPercNote(t,t2,42,(int)(vel_from + ((alpha / delta) * vel_off)));
      }
           t.mPos += speed;
           alpha += speed;
           if(speed_up == 1 && i == p->getEndBar() - 1 && t.mPos > p->getUniquePart()->getMetrum() / 2.0) {
               speed_up = 0;
               speed /= 2.0;
      }
    }
       if(speed_up == 2 && i == p->getEndBar() - 2) {
           speed_up = 0;
           speed /= 2.0;
    }
 }
 p->addPercNote(this->createTime(p->getEndBar(),0),this->createTime(p->getEndBar(),0.1),49,120);
 p->addPercNote(this->createTime(p->getEndBar(),0),this->createTime(p->getEndBar(),0.1),57,120);
}
