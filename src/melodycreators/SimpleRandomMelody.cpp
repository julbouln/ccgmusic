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
/*            switch(p) {
                case -2:
                    p=-3;
                    break;
                case -1:
                    p=-1;
                    break;
                case 1:
                    p=1;
                    break;
                case 2:
                    p=3;
                    break;

            }*/
            note += p;
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

//    printf("SimpleRandomMelody::createMelodyset last note %d(%s)\n",last_note,Utils::midiToNote(60+last_note).c_str());

//    last_note = up->alignPitchToHarm(up->getEvents() - 1, last_note);

    up->setEventPitch(up->getEvents() - 1, last_note);
}
