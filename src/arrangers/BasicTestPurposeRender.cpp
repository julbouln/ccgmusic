#include "BasicTestPurposeRender.h"
 string getScriptName() {
 	return "Basic Test Purpose";
 }

void BasicTestPurposeRender::arrange(Song *s) {
 int bars = s->getBars();
 s->addTrack("Melody",5,127,64,false);
 s->addTrack("Drums",1,127,64,true);
 s->addTrack("Bass", 33, 127, 64,false);

 for(int i = 0;i < s->getParts();++i ){

 s->addRenderEvent("Sine Velocity Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
}
 s->addRenderEvent("Drums - Punk Rock",this->rndInt(0,INT_MAX),1,0,bars,0,this->createTime(0,0),1);
 s->setParam(RenderEvent::FOOT_SNARE, 1);

 s->addRenderEvent("Random Bass ( Extended )", this->rndInt(0,INT_MAX), 2, 0, bars, 0,this->createTime(0, 0), 1);

}
