#ifndef MARKOVMELODY_H
#define MARKOVMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "MelodyCreator.h"
#include "UniquePart.h"
#include "Time.h"
#include "UniquePhrase.h"

// number of possible states 
#define MARKOV_CHAIN_SIZE 6
// number of orders of chain - this code suggests 
#define MARKOV_CHAIN_ORDER 3
#define MARKOV_MAX_COUNT 256
#define MARKOV_MULTIPLIER 2; // how much is added each time, defines strength of chain 


using namespace std;
class MarkovMelody : public MelodyCreator {
public:
 void createMelody(UniquePart*);
 uint8_t chooseNote(uint8_t a, uint8_t b, uint8_t c);
 void updateChain(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

private:
	// one more dimension than the chain size 
	// if max_count > 256, use int, otherwise use byte 
	uint8_t markov[MARKOV_CHAIN_SIZE][MARKOV_CHAIN_SIZE][MARKOV_CHAIN_SIZE][MARKOV_CHAIN_SIZE];

	//Holder for notes in play, 
	uint8_t note_store[MARKOV_CHAIN_SIZE+1];


};
#endif // MARKOVMELODY_H
