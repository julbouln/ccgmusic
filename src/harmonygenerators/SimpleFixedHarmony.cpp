#include "SimpleFixedHarmony.h"

vector<int> SimpleFixedHarmony::rndChord() {
	vector<int> chord = MusicScript::getChord(this->rndInt(0, CHORDS_COUNT - 1));
	return chord;
}


void SimpleFixedHarmony::generateHarmony(UniquePart *up) {
//	vector<int> chord = this->rndChord();
	vector<int> chord =  MusicScript::getChord(MAJOR_TRIAD_CHORD);

	up->addHarmonic(this->createTime(0, 0), 1, chord);
	for (int i = 1; i < up->getBars() - 2; i++ ) {
		if (i % 2 == 1) {
			up->addHarmonic(this->createTime(i, 0), 4, chord);
		}
		else {
			up->addHarmonic(this->createTime(i, 0), 1, chord);
		}
	}

	up->addHarmonic(this->createTime(up->getBars() - 2, 0), 5, chord);
	up->addHarmonic(this->createTime(up->getBars() - 1, 0), 1, chord);


}
