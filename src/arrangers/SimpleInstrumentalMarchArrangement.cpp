#include "SimpleInstrumentalMarchArrangement.h"
string SimpleInstrumentalMarchArrangement::getScriptName() {
 return "Simple Instrumental March Arrangement";
}
void SimpleInstrumentalMarchArrangement::arrange(Song *s) {
 int bars = s->getBars();
 if(this->rndInt(0,3) != 0) {
  s->addTrack("Drums",49,120,64,true);
 }
 else {
  s->addTrack("Drums",1,120,64,true);
 }
 s->addTrack("Tuba",59,127,72,false);
 s->addTrack("Bass",64,111,72,false);
 s->addTrack("Glockenspel",10,115,80,false);
 s->addTrack("Picolo",73,92,30,false);
 s->addTrack("Trumpet",57,127,72,false);
 s->addTrack("French Horn",61,120,72,false);
 s->addTrack("Tuba2",59,125,59,false);
 s->addRenderEvent("Drums - March",this->rndInt(0,INT_MAX),0,0,bars,1,this->createTime(0,0),1.0);
 s->setParam(RenderEvent::FOOT,1);
 s->addRenderEvent("March Chords",this->rndInt(0,INT_MAX),1,0,bars,0,this->createTime(0,0),1.1);
 s->addRenderEvent("March Bass",this->rndInt(0,INT_MAX),1,0,bars,-1,this->createTime(0,0),1.1);
 s->addRenderEvent("March Picolo",this->rndInt(0,INT_MAX),4,0,bars,4,this->createTime(0,0),1.0);
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 0) {
           if(this->rndInt(0,1) == 0) {
               s->addRenderEvent("Drums - March",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1.0);
               s->setParam(RenderEvent::CYMBAL,1);
      }
    }
    else {
           if(s->getPart(i)->getArrHint() == 3) {
       s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),3,this->createTime(0,0),1.0);
      }
      else {
       s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),3,this->createTime(0,0),0.7);
      }
           s->addRenderEvent("Accented Melody",this->rndInt(0,INT_MAX),5,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1.0);
           s->addRenderEvent("Accented Melody",this->rndInt(0,INT_MAX),5,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1.0);
           s->addRenderEvent("Accented Melody",this->rndInt(0,INT_MAX),6,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1.0);
           s->addRenderEvent("Accented Melody",this->rndInt(0,INT_MAX),6,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1.0);
    }
       if(s->getPart(i)->getArrHint() == 3) {
           s->addRenderEvent("Drums - March",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1.0);
           s->setParam(RenderEvent::CYMBAL,1);
           s->setParam(RenderEvent::SNARE,1);
           s->addRenderEvent("Random Bass ( Extended )",this->rndInt(0,INT_MAX),7,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1.0);
           s->setParam(RenderEvent::MODE,1);
           s->addRenderEvent("March Bass",this->rndInt(0,INT_MAX),2,s->getPartStartBar(i),s->getPartEndBar(i),-2,this->createTime(0,0),1.0);
    }
    else {
           s->addRenderEvent("March Bass",this->rndInt(0,INT_MAX),2,s->getPartStartBar(i),s->getPartEndBar(i),-1,this->createTime(0,0),1.0);
           s->addRenderEvent("Drums - March",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.9);
           if(this->rndInt(0,3) != 0) {
       s->setParam(RenderEvent::SNARE,1);
      }
    }
 }
 s->addRenderEvent("Drums - Simple Cymbal",0,0,bars - 1,bars,1,this->createTime(1,0),1.0);
}
