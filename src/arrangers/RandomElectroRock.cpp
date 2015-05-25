#include "RandomElectroRock.h"
 string RandomElectroRock::getScriptName() {
 	return "Random Electro Rock";
 }

string RandomElectroRock::rndMelody() {
	string melody;
	switch(this->rndInt(0,3)) {
 	case 0:
 		melody="Simple Melody";
 		break;
 	case 1:
 		melody="Accented Melody";
 		break;
 	case 2:
 		melody="Chordal Melody";
 		break;
 	case 3:
 		melody="Sine Velocity Simple Melody";
 		break;
/*
 	case 4:
 		melody="Boogie Woogie";
 		break;
 	case 5:
 		melody="Boogie Woogie Swing";
 		break;
 	case 6:
 		melody="Swinging Blues";
 		break; 		
 		*/
 }
 return melody;
}

string RandomElectroRock::rndBass() {
	string bass;

 switch(this->rndInt(0,6)) {
 	case 0:
 		bass="Random Bass";
 		break;
 	case 1:
 		bass="Fast Bass";
 		break;
 	case 2:
 		bass="Latin Bass";
 		break;
 	case 3:
 		bass="Simple Bass";
 		break;
 	case 4:
 		bass="March Bass";
 		break;
 	case 5:
 		bass="Disco Jumping Bass";
 		break;
 	case 6:
 		bass="Random Bass ( Extended )";
 		break;
 }
 return bass;

}

string RandomElectroRock::rndChords() {
	string chords;

 switch(this->rndInt(0,8)) {
 	case 0:
 		chords="Simple Chords";
 		break;
 	case 1:
 		chords="Arpeggio Chords";
 		break;
 	case 2:
 		chords="Simple Chords Smooth";
 		break;
 	case 3:
 		chords="Shortest Way Chords Simple";
 		break;
 	case 4:
 		chords="Shortest Way Chords Smooth";
 		break;
 	case 5:
 		chords="Arpeggio Chords Fast";
 		break;
 	case 6:
 		chords="Latin Chords";
 		break;
 	case 7:
 		chords="Punk Guitar Chords";
 		break;
 	case 8:
 		chords="March Chords";
 		break;

 }
 return chords;
}

int RandomElectroRock::rndStep() {
	return (4*this->rndInt(1,4));
}

void RandomElectroRock::arrange(Song *s) {

 s->addTrack("Melody", GM_RAND_SYNTH_LEAD,127,64,false);
 s->addTrack("Bass", GM_RAND_BASS, 127, 64,false);
 s->addTrack("Drums", 1,127,64,true);
 s->addTrack("Slow Strings",GM_FRETLESS_BASS,127,64,false);
 s->addTrack("Guitar",GM_RAND_GUITAR,127,64,false);
 s->addTrack("Accomp",GM_RAND_SYNTH_EFFECT,127,64,false);

 int snare=this->rndInt(38,40);
 int tom=45;
 int cymbal=49;
 int kick=this->rndInt(35,37);

 int cymbals[]={49,57};
 cymbal=49;
 //cymbals[this->rndInt(0,1)];
 
 int steps=4;//this->rndInt(16,128);

 int metrum=this->rndInt(0,2);
 switch(metrum) {
 	case 0:
 		metrum=1;
 		break;
 	case 1:
 		metrum=2;
 		break;
 	case 2:
 		metrum=4;
 		break;

 }

 int vol=this->rndInt(96,110);

 printf("drum %d %d %d\n",steps,metrum,vol);

 int accomp=this->rndInt(0,s->getParts()-1);
// printf("accomp %d\n",accomp);

 	 string melody=rndMelody();
 string bass=rndBass();
 string chords=rndChords();


// printf("render part %d %d\n",i,s->getPart(i)->getArrHint());
 printf("melody : %s\n",melody.c_str());
 printf("bass : %s\n",bass.c_str());
 printf("chords : %s\n",chords.c_str());

 for(int i = 0;i < s->getParts();++i ){

//melody="Simple Melody";


 //	printf("arrHint %d\n",s->getPart(i)->getArrHint());

 	if (s->getPart(i)->getArrHint() != 0) {
	    if(accomp==i) {
			s->addRenderEvent(melody,this->rndInt(0,INT_MAX),5,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
		}
		else
		{
 			s->addRenderEvent(melody,this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),1);
		}
 	}
/*
 	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	steps=8;
	s->setParam(RenderEvent::PULSES, 4);
    s->setParam(RenderEvent::STEPS, 8);
    s->setParam(RenderEvent::METRUM, metrum);
    s->setParam(RenderEvent::VOL, vol);
    s->setParam(RenderEvent::PITCH, 38);

 	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	steps=8;
	s->setParam(RenderEvent::PULSES, 3);
    s->setParam(RenderEvent::STEPS, 12);
    s->setParam(RenderEvent::METRUM, metrum);
    s->setParam(RenderEvent::VOL, vol);
    s->setParam(RenderEvent::PITCH, 39);
*/
	s->addRenderEvent(bass, this->rndInt(0,INT_MAX), 1, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 0.9);

	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	steps=rndStep();
	s->setParam(RenderEvent::PULSES, this->rndInt(steps/3+1,steps));
    s->setParam(RenderEvent::STEPS, steps);
    s->setParam(RenderEvent::METRUM, metrum);
    s->setParam(RenderEvent::VOL, vol);
    s->setParam(RenderEvent::PITCH, snare);
//    s->setParam(RenderEvent::PITCH, 65);


	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	steps=rndStep();
	s->setParam(RenderEvent::PULSES, this->rndInt(steps/3+1,steps));
    s->setParam(RenderEvent::STEPS, steps);
    s->setParam(RenderEvent::METRUM, metrum);
    s->setParam(RenderEvent::VOL, vol);
    s->setParam(RenderEvent::PITCH, kick);
    
    
/*
	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	steps=rndStep();
	s->setParam(RenderEvent::PULSES, this->rndInt(steps/8+1,steps/4));
    s->setParam(RenderEvent::STEPS, steps);
    s->setParam(RenderEvent::METRUM, metrum);
    s->setParam(RenderEvent::VOL, vol);
    s->setParam(RenderEvent::PITCH, tom);
*/

	s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
	steps=rndStep();
	s->setParam(RenderEvent::PULSES, this->rndInt(steps/3+1,steps));
    s->setParam(RenderEvent::STEPS, steps);
    s->setParam(RenderEvent::METRUM, metrum);
    s->setParam(RenderEvent::VOL, vol);

    s->setParam(RenderEvent::PITCH, 48);


/*
    if(this->rndInt(0,4)>0) {
		s->addRenderEvent("Drums Euclidean", this->rndInt(0,INT_MAX), 2, s->getPartStartBar(i),s->getPartEndBar(i), 0,this->createTime(0, 0), 1);
		steps=rndStep();
		s->setParam(RenderEvent::PULSES, 1);
		s->setParam(RenderEvent::STEPS, steps);
        s->setParam(RenderEvent::METRUM, metrum);
        s->setParam(RenderEvent::VOL, vol);
    	s->setParam(RenderEvent::PITCH, cymbal);
//    	printf("%d\n",cymbal);
	}	
	*/

    if(this->rndInt(0,1)==0) {
//		s->addRenderEvent("Simple Bass",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.5);
	}
		s->addRenderEvent("Simple Bass",this->rndInt(0,INT_MAX),3,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.5);

    if (s->getPart(i)->getArrHint() == 3) {
    	s->addRenderEvent(chords,this->rndInt(0,INT_MAX),4,s->getPartStartBar(i),s->getPartEndBar(i),0,this->createTime(0,0),0.9);
    }
	 }


}
