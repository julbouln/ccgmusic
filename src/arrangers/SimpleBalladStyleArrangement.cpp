#include "SimpleBalladStyleArrangement.h"
string SimpleBalladStyleArrangement::getScriptName() {
 return "Simple Ballad Style Arrangement";
}
void SimpleBalladStyleArrangement::arrange(Song *s) {
 int bars = s->getBars();
// s->addTrack("Melody",73,127,64,false);
// s->addTrack("Alt Voice",12,120,64,false);

 s->addTrack("Melody",GM_RAND_PIPE,127,64,false);
 s->addTrack("Alt Voice",GM_RAND_CHROMATIC_PERCUSSION,120,64,false);

 s->addTrack("Slow Strings",50,127,64,false);

 if(this->rndInt(0,1) == 0) {
  s->addTrack("Harph",47,127,64,false);
 }
 else {
//  s->addTrack("Guitar",26,127,64,false);
  s->addTrack("Guitar",GM_RAND_GUITAR,127,64,false);
   }
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 1) {
     s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),0.75);
    }
       if(s->getPart(i)->getArrHint() == 2) {
     s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.75);
    }
       if(s->getPart(i)->getArrHint() == 3) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),this->rndInt(1,2),this->createTime(0,0),1);
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),this->rndInt(1,2),this->createTime(0,0),1);
           s->addRenderEvent("Shortest Way Chords Smooth",this->rndInt(0,INT_MAX),2,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.5);
    }
    else {
           s->addRenderEvent("Simple Bass",this->rndInt(0,INT_MAX),2,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.5);
    }
 }
 s->addRenderEvent("Shortest Way Chords Smooth",this->rndInt(0,INT_MAX),3,0,bars,0,this->createTime(0,0),0.8);
}
