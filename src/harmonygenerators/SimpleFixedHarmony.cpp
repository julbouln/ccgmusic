#include "SimpleFixedHarmony.h"

vector<int> SimpleFixedHarmony::rndChord() {
	vector<int> chord = MusicScript::getChord(this->rndInt(0, CHORDS_COUNT - 1));
	return chord;
}


void SimpleFixedHarmony::generateHarmony(UniquePart *up) {
//	vector<int> chord = this->rndChord();
	vector<int> chord =  MusicScript::getChord(MAJOR_TRIAD_CHORD);
//	vector<int> chord =  MusicScript::getChord(ADD9_CHORD);

/*
	up->addHarmonic(this->createTime(0, 0), 1, chord);
	up->addHarmonic(this->createTime(1, 0), 5, chord);
	up->addHarmonic(this->createTime(2, 0), 6, MusicScript::getChord(MINOR_TRIAD_CHORD));
	up->addHarmonic(this->createTime(3, 0), 4, chord);

	up->addHarmonic(this->createTime(4, 0), 1, chord);
	up->addHarmonic(this->createTime(5, 0), 5, chord);
	up->addHarmonic(this->createTime(6, 0), 6, MusicScript::getChord(MINOR_TRIAD_CHORD));
	up->addHarmonic(this->createTime(7, 0), 4, chord);
*/

/*
	up->addHarmonic(this->createTime(0, 0), 2, MusicScript::getChord(MINOR_TRIAD_CHORD));
	up->addHarmonic(this->createTime(1, 0), 4, chord);
	up->addHarmonic(this->createTime(2, 0), 5, chord);

	up->addHarmonic(this->createTime(3, 0), 2, MusicScript::getChord(MINOR_TRIAD_CHORD));

	up->addHarmonic(this->createTime(4, 0), 4, chord);
	up->addHarmonic(this->createTime(5, 0), 5, chord);
	up->addHarmonic(this->createTime(6, 0), 2, MusicScript::getChord(MINOR_TRIAD_CHORD));
	up->addHarmonic(this->createTime(7, 0), 4, chord);
*/

//printf("%d\n",up->getBars());

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
