#include "SimpleFixedHarmony.h"

vector<int> SimpleFixedHarmony::rndChord() {
	vector<int> chord = MusicScript::getChord(this->rndInt(0, CHORDS_COUNT - 1));
	return chord;
}

int SimpleFixedHarmony::progressions[][8]={
	{1,4,1,4,1,4,1,4},
	{4,1,4,5,4,1,4,5},
	{1,5,4,5,1,5,4,5},
	{1,5,6,4,1,5,6,4},
	{1,5,6,3,1,5,6,3},
	{6,5,4,5,6,5,4,5},
	{1,4,6,5,1,4,6,5}
};

void SimpleFixedHarmony::generateHarmony(UniquePart *up) {
//	vector<int> chord = this->rndChord();
//	vector<int> chord =  MusicScript::getChord(MAJOR_TRIAD_CHORD);
	vector<int> chord =  MusicScript::getChord(MAJOR_TRIAD_CHORD);



if(up->getBars()==8) {
	int rndProgression=this->rndInt(0,6);
	for(int i=0;i<8;i++) {
		up->addHarmonic(this->createTime(i, 0), progressions[rndProgression][i], chord);
	}

} 
else
{


	up->addHarmonic(this->createTime(0, 0), MusicScript::I, chord);

	for (int i = 1; i < up->getBars() - 2; i++ ) {
		if (i % 2 == 1) {
			up->addHarmonic(this->createTime(i, 0), MusicScript::IV, chord);
		}
		else {
			up->addHarmonic(this->createTime(i, 0), MusicScript::I, chord);
		}
		
//		up->addHarmonic(this->createTime(i, 0), this->rndInt(1,7), chord);
	}

	up->addHarmonic(this->createTime(up->getBars() - 2, 0), MusicScript::V, chord);
	up->addHarmonic(this->createTime(up->getBars() - 1, 0), MusicScript::I, chord);
}

}
