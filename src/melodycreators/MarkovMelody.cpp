#include "MarkovMelody.h"


void MarkovMelody::updateChain(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    if(markov[a][b][c][d]<MARKOV_MAX_COUNT){
        markov[a][b][c][d] = markov[a][b][c][d]+MARKOV_MULTIPLIER;
    }
}

uint8_t MarkovMelody::chooseNote(uint8_t a, uint8_t b, uint8_t c){
  
//  count the total hits in the relevant chain 
  int total=0;
  for (uint8_t y=0;y<MARKOV_CHAIN_SIZE;y++){
    total=total+markov[a][b][c][y]; 
  }

// pick and return a new number, based on weighted dice throw 
int running_total=0;
int random_number = this->rndInt(0,total);
for( uint8_t i=0; i<MARKOV_CHAIN_SIZE; i++){
  running_total=running_total+markov[a][b][c][i];
  if (random_number<=running_total){
    return i;
    break;
  }
}
  
}

void MarkovMelody::createMelody(UniquePart *up)
{
    int note = up->getEventBasis(0);

//    printf("INITIAL NOTE %d\n",note);
//    this->rndInt(0, 1);

    for(int q=0;q<MARKOV_CHAIN_SIZE;q++){
        for(int z=0;z<MARKOV_CHAIN_SIZE;z++){
            for(int x=0; x<MARKOV_CHAIN_SIZE; x++){
                for (int y = 0; y< MARKOV_CHAIN_SIZE; y++){
                    markov[q][x][y][z]=note;
                }
            }
        }
    }

    for (int i=0;i<MARKOV_CHAIN_ORDER;i++){
         note_store[i]=this->rndInt(0,MARKOV_CHAIN_SIZE-1); 
    }

    for (int i = 0; i < up->getEvents() - 1; i++ )
    {

        note_store[3] = chooseNote(note_store[0],note_store[1],note_store[2]);

        note=note_store[3];
//        note = up->alignPitchToHarm(i, note);
        note = up->setEventPitch(i, note);

//        printf("ADD NOTE %d\n",note);
        updateChain(note_store[0],note_store[1],note_store[2],note_store[3]);

        for (int i=0;i<MARKOV_CHAIN_SIZE;i++){
         note_store[i] = note_store[i+1]; 
        }


    }
    
}
