#include "PianoAdvancedDisco.h"
string PianoAdvancedDisco::getScriptName()
{
    return "Piano Advanced Disco";
}
void PianoAdvancedDisco::arrange(Song *s)
{
    int bars = s->getBars();
    s->addTrack("Melody", GM_ELECTRIC_PIANO_2, 127, 64,false);
    s->addTrack("Alt Voice", GM_ELECTRIC_PIANO_1, 127, 64,false);
    s->addTrack("Accomp", GM_ELECTRIC_PIANO_1, 127, 64,false);
    s->addTrack("Chorus Intro", GM_HONKYTONK_PIANO, 127, 64,false);
    s->addTrack("Accomp boost", GM_ELECTRIC_PIANO_2, 127, 64,false);
    int intro_seed = this->rndInt(0, INT_MAX);
    for (int i = 0; i < s->getParts(); ++i )
    {
        int end = s->getPartEndBar(i);
        if (i == s->getParts() - 1)
        {
            --end;
        }
        if (s->getPart(i)->getArrHint() == 0)
        {
            s->addRenderEvent("Shortest Way Chords Simple", this->rndInt(0, INT_MAX), this->rndInt(0, 1), s->getPartStartBar(i), s->getPartEndBar(i), this->rndInt(1, 2), this->createTime(0, 0), 0.8);
        }
        if (s->getPart(i)->getArrHint() == 1)
        {
            s->addRenderEvent("Simple Melody", this->rndInt(0, INT_MAX), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
        }
        if (s->getPart(i)->getArrHint() == 2)
        {
            s->addRenderEvent("Simple Melody", this->rndInt(0, INT_MAX), 1, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
        }
        if (s->getPart(i)->getArrHint() == 3)
        {
            s->addRenderEvent("Simple Melody", this->rndInt(0, INT_MAX), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Simple Melody", this->rndInt(0, INT_MAX), 1, s->getPartStartBar(i), s->getPartEndBar(i), 2, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Disco Jumping Bass", this->rndInt(0, INT_MAX), 4, s->getPartStartBar(i), end, -1, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Random Bass", this->rndInt(0, INT_MAX), 3, s->getPartStartBar(i), end, this->rndInt(0, 2), this->createTime(0, 0), 0.8);
        }
    }
    s->addRenderEvent("Quick Intro Bass", intro_seed, 3, bars - 1, bars, -1, this->createTime(1, 0), 1.0);
    s->addRenderEvent("Quick Intro Bass", intro_seed, 3, bars - 1, bars, 0, this->createTime(1, 0), 1.0);
    s->addRenderEvent("Simple Chords", this->rndInt(0, INT_MAX), 3, bars - 1, bars, 2, this->createTime(0, 0), 1.0);
    s->addRenderEvent("Simple Chords", this->rndInt(0, INT_MAX), 3, bars - 1, bars, 3, this->createTime(1, 0), 1.0);
    s->addRenderEvent("Disco Jumping Bass", this->rndInt(0, INT_MAX), 2, 0, bars - 1, 0, this->createTime(0, 0), 0.9);
}
