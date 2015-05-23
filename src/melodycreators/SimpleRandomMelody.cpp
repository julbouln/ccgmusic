#include "SimpleRandomMelody.h"
void SimpleRandomMelody::createMelody(UniquePart *up)
{
    int note = up->getEventBasis(0);

    this->rndInt(0, 1);

    for (int i = 0; i < up->getEvents() - 1; i++ )
    {
        note = up->alignPitchToHarm(i, note);

//        printf("SimpleRandomMelody::createMelody set note %d %d\n",i,note);
        note = up->setEventPitch(i, note);

        if (i < up->getEvents() - 2)
        {
            note += this->rndInt(-2, 2);
        }

    }
    
    int last_note = 1;

//    int last_note = this->rndInt(0,4);
/*    if(last_note % 2 == 0) {
        last_note+=1;
    }
    */
    while (note > 5)
    {
        note -= 7;
        last_note += 7;
    }
    while (note < -3)
    {
        note += 7;
        last_note -= 7;
    }
    if (note == 5 && this->rndInt(0, 1) == 0)
    {
        last_note += 7;
    }

//    printf("SimpleRandomMelody::createMelodyset last note %d\n",last_note);

//    last_note = up->alignPitchToHarm(up->getEvents() - 1, last_note);

    up->setEventPitch(up->getEvents() - 1, last_note);
}
