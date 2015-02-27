#include "PianoAdvancedSwingingBlues.h"
string PianoAdvancedSwingingBlues::getScriptName() {
 return "Piano Advanced Swinging Blues";
}
void PianoAdvancedSwingingBlues::arrange(Song *s) {
 int bars = s->getBars();
 s->addTrack("Melody",this->rndInt(2,4),127,64,false);
 s->addTrack("Alt Mel",this->rndInt(2,4),127,64,false);
 s->addTrack("Acc",this->rndInt(1,4),127,64,false);
 s->addTrack("Bass",this->rndInt(1,4),127,64,false);
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 0) {
           s->addRenderEvent("Random Bass",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
    }
       if(s->getPart(i)->getArrHint() == 1) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),1);
           s->addRenderEvent("Random Bass",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
    }
       if(s->getPart(i)->getArrHint() == 2) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),1);
           s->addRenderEvent("Random Bass",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
    }
       if(s->getPart(i)->getArrHint() == 3) {
           s->addRenderEvent("Chordal Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),1);
           s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),3,this->createTime(0,0),0.8);
           s->addRenderEvent("Swinging Blues",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i) - 1,1,this->createTime(0,0),0.75);
           s->addRenderEvent("Random Bass",1,3,s->getPartStartBar(i),s->getPartEndBar(i),-1,this->createTime(0,0),1);
    }
 }
 s->addRenderEvent("Swinging Blues",this->rndInt(0,INT_MAX),2,s->getPartEndBar(0) - 1,s->getPartEndBar(0),0,this->createTime(-(s->getPartEndBar(0) - s->getPartStartBar(0)),0),0.5);
 s->addRenderEvent("Swinging Blues",this->rndInt(0,INT_MAX),2,0,bars - 1,0,this->createTime(0,0),0.8);
 s->addRenderEvent("Simple Chords",this->rndInt(0,INT_MAX),2,bars - 1,bars,0,this->createTime(0,0),1);
}
