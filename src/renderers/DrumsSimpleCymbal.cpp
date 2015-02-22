#include "DrumsSimpleCymbal.h"
void DrumsSimpleCymbal::render(RenderPart *p) {
 int pit = p->getParam(RenderEvent::PITCH);
 if(pit == 0) {
  pit = 49;
 }
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       p->addPercNote(this->createTime(i,0),this->createTime(i,1),pit,this->rndInt(115,127));
 }
}
