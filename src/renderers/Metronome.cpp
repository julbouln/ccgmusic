#include "Metronome.h"
void Metronome::render(RenderPart *p) {
 int test = p->getParam(RenderEvent::PITCH);
 if(test == 0) {
  test = 37;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       for(int u = 0;u < p->getUniquePart()->getMetrum();++u    ){
             int vel = 127;
             if(u != 0) {
        vel = 90;
       }
             p->addPercNote(this->createTime(i,u),this->createTime(i,u + 0.5),test,vel);
    }
 }
}
