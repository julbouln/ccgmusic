#include "LightInstrumentalMarchArrangement.h"
 string LightInstrumentalMarchArrangement::getScriptName() {
 	return "Light Instrumental March Arrangement";
 }

void LightInstrumentalMarchArrangement::arrange(Song *s) {
 int bars = s->getBars();
 s->addTrack("Timpani", 48,96,64,false);

 s->addTrack("Drums", 1,110,64,true);
 s->addTrack("Bass", 44, 110, 64,false);
 s->addTrack("String", 49,100,64,false);
 s->addTrack("Trumpet",57,127,72,false);
 s->addTrack("French Horn",61,127,72,false);
 s->addTrack("Picolo",73,127,72,false);
 s->addTrack("Pizzicato",46,127,72,false);

 int pizzicato_seed=this->rndInt(0,bars);

 for(int i = 0;i < s->getParts();++i ){
//	s->addRenderEvent("Simple Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);

//	s->addRenderEvent("Drums - March",this->rndInt(0,INT_MAX),1,s->getPartStartBar(i)+this->rndInt(0,s->getPartEndBar(i)/2),s->getPartEndBar(i),1,this->createTime(0,0),1.0);
//    s->setParam(RenderEvent::SNARE,1);

	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 1, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	s->setParam(RenderEvent::PULSES, this->rndInt(16,24));
    s->setParam(RenderEvent::PITCH, this->rndInt(0,1)==0 ? 38 : 40);

	s->addRenderEvent("Random Bass ( Extended )", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);

	s->addRenderEvent("Simple Chords",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);


    if(this->rndInt(0,1) == 0) {
		s->addRenderEvent("Accented Melody",this->rndInt(0,INT_MAX),4,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
		s->addRenderEvent("Accented Melody",this->rndInt(0,INT_MAX),5,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);

	}		
//	s->addRenderEvent("March Picolo",this->rndInt(0,INT_MAX),6,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
	if(i < 2 || i==pizzicato_seed) {
		s->addRenderEvent("Chordal Melody",this->rndInt(0,INT_MAX),7,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
	
	}
	
 }


}
