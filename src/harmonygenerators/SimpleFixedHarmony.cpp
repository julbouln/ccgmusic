#include "SimpleFixedHarmony.h"

void SimpleFixedHarmony::generateHarmony(UniquePart *up) {
	vector<int> chords=MusicScript::triadChord(MAJOR_TRIAD_CHORD);

	int baseNote=this->rndInt(1,7);

 up->addHarmonic(this->createTime(0,0),1,chords);
 for(int i = 1;i < up->getBars() - 2;i++ ){
    if(i % 2 == 1) {
     up->addHarmonic(this->createTime(i,0),4,chords);
    }
    else {
     up->addHarmonic(this->createTime(i,0),1,chords);
    }
 }
 up->addHarmonic(this->createTime(up->getBars() - 2,0),5,chords);
 up->addHarmonic(this->createTime(up->getBars() - 1,0),1,chords);

 /*
 for(int i = 0;i < up->getBars();i++ ){
     up->addHarmonic(this->createTime(i,0),1,MusicScript::createTriadChord(chord));

 }
 */

}
