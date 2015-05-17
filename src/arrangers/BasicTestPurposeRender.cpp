#include "BasicTestPurposeRender.h"
 string BasicTestPurposeRender::getScriptName() {
 	return "Basic Test Purpose";
 }


void BasicTestPurposeRender::arrange(Song *s) {

 s->addTrack("Melody", GM_RAND_PIANO,127,64,false);
 

 for(int i = 0;i < s->getParts();++i ){
// 	printf("render %d\n",i);
	s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);

 }


}
