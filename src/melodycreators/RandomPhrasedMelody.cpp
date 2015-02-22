#include "RandomPhrasedMelody.h"
double RandomPhrasedMelody::GetEventLength(UniquePart *up, int e)
{
    Time t1 = up->getEventStart(e);
    Time t2 = up->getEventEnd(e);
    return (t2.mBar - t1.mBar) * up->getMetrum() + (t2.mPos - t1.mPos);
}
void RandomPhrasedMelody::createMelody(UniquePart *up)
{
    int u_phrases = up->getUniquePhrases();
    vector<int *> melody;
    vector<int *> align;
    for (int i = 0; i < u_phrases; ++i )
    {
        UniquePhrase *p = up->getUniquePhrase(i);
        melody.push_back(new int[p->getEvents()]);
        align.push_back(new int[p->getEvents()]);
        for (int m = 0; m < p->getEvents(); ++m    )
        {
            melody[i][m] = this->rndInt(-2, 2);
            align[i][m] = this->rndInt(0, 1);
        }
        melody[i][0] = this->rndInt(2, 8);
    }
    int event = 0;
    int theNote = 0;
    for (int s = 0; s < up->getSentences(); ++s )
    {
        for (int p = 0; p < up->getSentence(s)->getPhrases(); ++p    )
        {
            UniquePhrase *upp = up->getSentence(s)->getPhrase(p)->getUniquePhrase();
            int note = melody[up->getSentence(s)->getPhrase(p)->getUniquePhraseID()][0];
            for (int e = 0; e < upp->getEvents(); ++e       )
            {
                if (event < up->getEvents() - 1)
                {
                    if (align[up->getSentence(s)->getPhrase(p)->getUniquePhraseID()][e] == 1 || this->GetEventLength(up, event) > 1.2)
                    {
                        up->setEventPitch(event, up->alignPitchToHarm(event, note));
                    }
                    else
                    {
                        up->setEventPitch(event, note);
                    }
                    ++event;
                    if (e < upp->getEvents() - 1)
                    {
                        note += melody[up->getSentence(s)->getPhrase(p)->getUniquePhraseID()][e + 1];
                    }
                }
            }
        }
    }
    int last_note = 1;
    if (up->endsSong())
    {
        if (this->rndInt(0, 3) == 0)
        {
            last_note = 5;
        }
    }
    else
    {
        if (this->rndInt(0, 2) != 0)
        {
            last_note = 1 + (this->rndInt(0, 2) * 2);
        }
    }
    while (theNote > 5)
    {
        theNote -= 7;
        last_note += 7;
    }
    while (theNote < -3)
    {
        theNote += 7;
        last_note -= 7;
    }
    if (theNote == 5 && this->rndInt(0, 1) == 0)
    {
        last_note += 7;
    }
//        printf("RandomPhrasedMelody::createMelody %d %d\n",up->getEvents() - 1, last_note);

    up->setEventPitch(up->getEvents() - 1, last_note);
    Utils::deleteVector(melody);
    Utils::deleteVector(align);
}
