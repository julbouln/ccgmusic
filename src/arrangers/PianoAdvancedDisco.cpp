#include "PianoAdvancedDisco.h"
string PianoAdvancedDisco::getScriptName()
{
    return "Piano Advanced Disco";
}
void PianoAdvancedDisco::arrange(Song *s)
{
    int bars = s->getBars();
    s->addTrack("Melody", 6, 127, 64,false);
    s->addTrack("Alt Voice", 5, 127, 64,false);
    s->addTrack("Accomp", 5, 127, 64,false);
    s->addTrack("Chorus Intro", 4, 127, 64,false);
    s->addTrack("Accomp boost", 6, 127, 64,false);
    int intro_seed = this->rndInt(0, 32000);
    for (int i = 0; i < s->getParts(); ++i )
    {
        int end = s->getPartEndBar(i);
        if (i == s->getParts() - 1)
        {
            --end;
        }
        if (s->getPart(i)->getArrHint() == 0)
        {
            s->addRenderEvent("Shortest Way Chords Simple", this->rndInt(0, 32000), this->rndInt(0, 1), s->getPartStartBar(i), s->getPartEndBar(i), this->rndInt(1, 2), this->createTime(0, 0), 0.8);
        }
        if (s->getPart(i)->getArrHint() == 1)
        {
            s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
        }
        if (s->getPart(i)->getArrHint() == 2)
        {
            s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 1, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
        }
        if (s->getPart(i)->getArrHint() == 3)
        {
            s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 1, s->getPartStartBar(i), s->getPartEndBar(i), 2, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Disco Jumping Bass", this->rndInt(0, 32000), 4, s->getPartStartBar(i), end, -1, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Random Bass", this->rndInt(0, 32000), 3, s->getPartStartBar(i), end, this->rndInt(0, 2), this->createTime(0, 0), 0.8);
        }
    }
    s->addRenderEvent("Quick Intro Bass", intro_seed, 3, bars - 1, bars, -1, this->createTime(1, 0), 1.0);
    s->addRenderEvent("Quick Intro Bass", intro_seed, 3, bars - 1, bars, 0, this->createTime(1, 0), 1.0);
    s->addRenderEvent("Simple Chords", this->rndInt(0, 32000), 3, bars - 1, bars, 2, this->createTime(0, 0), 1.0);
    s->addRenderEvent("Simple Chords", this->rndInt(0, 32000), 3, bars - 1, bars, 3, this->createTime(1, 0), 1.0);
    s->addRenderEvent("Disco Jumping Bass", this->rndInt(0, 32000), 2, 0, bars - 1, 0, this->createTime(0, 0), 0.9);
}
