#include "SimpleLatinStyleArrangement.h"
string SimpleLatinStyleArrangement::getScriptName() {
 return "Simple Latin Style Arrangement";
}
void SimpleLatinStyleArrangement::arrange(Song *s) {
 int bars = s->getBars();
 int patches[] = {109,107,106,12,11,13,19,76,78,80,72,65,47,24,23,73,73,73};
 s->addTrack("Melody",this->getRandom(patches),127,64,false);
 s->addTrack("Alt Voice",2,127,64,false);
 s->addTrack("Fill",50,127,64,false);
 s->addTrack("Bass",33,127,64,false);
 if(this->rndInt(0,1) != 0) {
  s->addTrack("Accomp",this->rndInt(1,6),127,64,false);
 }
 else {
  s->addTrack("Accomp",25,127,64,false);
 }
 s->addTrack("Drums",1,127,64,true);
 int chorus_seed = this->rndInt(0,32000);
 int normal_seed = this->rndInt(0,32000);
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 0) {
    }
       if(s->getPart(i)->getArrHint() == 1) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,32000),0,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),0.95);
    }
       if(s->getPart(i)->getArrHint() == 2) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,32000),1,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),0.95);
    }
       if(s->getPart(i)->getArrHint() == 3) {
           s->addRenderEvent("Simple Melody",this->rndInt(0,32000),0,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),1.0);
           s->addRenderEvent("Chordal Melody",this->rndInt(0,32000),1,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),1.0);
           s->addRenderEvent("Latin Chords",chorus_seed,4,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.9);
           s->addRenderEvent("Latin Bass",this->rndInt(0,32000),3,s->getPartStartBar(i),s->getPartEndBar(i),-1,this->createTime(0,0),1.0);
           s->addRenderEvent("Shortest Way Chords Simple",this->rndInt(0,32000),2,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.65);
           s->addRenderEvent("Drums - Latin",chorus_seed,5,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.85);
    }
    else {
           s->addRenderEvent("Latin Chords",normal_seed,4,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.75);
           s->addRenderEvent("Latin Bass",this->rndInt(0,32000),3,s->getPartStartBar(i),s->getPartEndBar(i),-1,this->createTime(0,0),0.95);
           s->addRenderEvent("Shortest Way Chords Simple",this->rndInt(0,32000),2,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.5);
           s->addRenderEvent("Drums - Latin",normal_seed,5,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.8);
    }
 }
}
