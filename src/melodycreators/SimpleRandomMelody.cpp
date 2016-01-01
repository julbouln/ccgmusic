#include "SimpleRandomMelody.h"
void SimpleRandomMelody::createMelody(UniquePart *up)
{
    int note = up->getEventBasis(0);

    this->rndInt(0, 1);

    for (int i = 0; i < up->getEvents() - 1; i++ )
    {
        int onote=note;
        note = up->alignPitchToHarm(i, note);

//        printf("SimpleRandomMelody::createMelody set note %d (was %d) %d(%s)\n",i,onote-1,note-1,Utils::midiToNote(60+note-1).c_str());
        note = up->setEventPitch(i, note);

        if (i < up->getEvents() - 2)
        {
            int p= this->rndInt(-2,2);
            note += p;
        }
        if (note < up->getEventBasis(0) - 8 && this->rndInt(0, 2) == 0)
        {
            note = up->getEventBasis(0) + this->rndInt(-2, 4);
        }
        if (note > up->getEventBasis(0) + 8 && this->rndInt(0, 2) == 0)
        {
            note = up->getEventBasis(0) - this->rndInt(-2, 4);
        }

    }
    
//    int last_note = 1;
    int last_note = this->rndInt(1,7);

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

//    printf("SimpleRandomMelody::createMelodyset last note %d(%s)\n",last_note,Utils::midiToNote(60+last_note).c_str());

    last_note = up->alignPitchToHarm(up->getEvents() - 1, last_note);

    up->setEventPitch(up->getEvents() - 1, last_note);
}
