#include "PianoSimpleArrangement.h"
string PianoSimpleArrangement::getScriptName() {
 return "Piano Simple Arrangement";
}
void PianoSimpleArrangement::arrange(Song *s) {
 int bars = s->getBars();
 s->addTrack("Melody",1,127,64,false);
 s->addTrack("Alt Voice",2,127,64,false);
 s->addTrack("Chords",1,127,64,false);
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 1) {
     s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
    }
       if(s->getPart(i)->getArrHint() == 2) {
     s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
    }
       if(s->getPart(i)->getArrHint() == 3) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0.05),0.8);
    }
 }
 s->addRenderEvent("Simple Chords",this->rndInt(0,INT_MAX),2,0,bars,0,this->createTime(0,0),0.8);
}
