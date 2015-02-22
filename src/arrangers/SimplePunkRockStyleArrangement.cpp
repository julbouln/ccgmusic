#include "SimplePunkRockStyleArrangement.h"
string SimplePunkRockStyleArrangement::getScriptName()
{
    return "Simple Punk Rock Style Arrangement";
}
void SimplePunkRockStyleArrangement::arrange(Song *s)
{
//  printf("SimplePunkRockStyleArrangement::arrange seed:%d\n",this->getSeed());
    int bars = s->getBars();
    s->addTrack("Melody", 86, 127, 64,false);
    s->addTrack("Alt Voice", 63, 127, 64,false);
    s->addTrack("Guitar Left", this->rndInt(29, 31), 127, 20,false);
    s->addTrack("Guitar Right", this->rndInt(29, 31), 127, 100,false);
    s->addTrack("Guitar Center", this->rndInt(29, 31), 127, 64,false);
    s->addTrack("Bass", this->rndInt(35,37), 127, 64,false);
    s->addTrack("Drums", 16, 127, 64,true);
    s->addTrack("Brass", 62, 127, 64,false);
    
    int cnt = 0;
    int chorus_cnt = 0;
    int intro_start = this->rndInt(0, 1);
    int bass_start = this->rndInt(0, 4);
    for (int i = 0; i < s->getParts(); ++i )
    {
//      printf("Part %d %d %d/%d\n",i,s->getPart(i)->getArrHint(),s->getPartStartBar(i), s->getPartEndBar(i));
        if (s->getPart(i)->getArrHint() == 0)
        {
        }
        else
        {
            if (s->getPart(i)->getArrHint() == 1 || s->getPart(i)->getArrHint() == 3)
            {
                s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 0, s->getPartStartBar(i), s->getPartEndBar(i), 2, this->createTime(0, 0), 0.7);
            }
            if (s->getPart(i)->getArrHint() == 2)
            {
                s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 1, s->getPartStartBar(i), s->getPartEndBar(i), 2, this->createTime(0, 0), 0.8);
            }
        }
        if (s->getPart(i)->getArrHint() == 3)
        {
            int seed = this->rndInt(0, 32000);
            s->addRenderEvent("Punk Guitar Chords", seed, 4, s->getPartStartBar(i), s->getPartEndBar(i), 0, this->createTime(0, 0), 1.0);
            s->setParam(RenderEvent::MODE, 3);
            s->addRenderEvent("Simple Melody", this->rndInt(0, 32000), 1, s->getPartStartBar(i), s->getPartEndBar(i), 2, this->createTime(0, 0), 0.8);
            s->addRenderEvent("Fast Bass", this->rndInt(0, 32000), 5, s->getPartStartBar(i), s->getPartEndBar(i), -1, this->createTime(0, 0), 1.0);
            s->addRenderEvent("Drums - Punk Rock", this->rndInt(0, 32000), 6, s->getPartStartBar(i), s->getPartEndBar(i) - 1, 1, this->createTime(0, 0), 1.0);
            s->setParam(RenderEvent::FOOT_SNARE, 1);
            s->setParam(RenderEvent::VERSE_HIHAT, 1);
            s->addRenderEvent("Drums - Punk Rock", this->rndInt(0, 32000), 6, s->getPartEndBar(i) - 1, s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
            s->setParam(RenderEvent::TRANSITION, 1);
            if (chorus_cnt > 1)
            {
                s->addRenderEvent("Punk Guitar Chords", seed, 7, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
                s->setParam(RenderEvent::MODE, 2);
            }
            
            chorus_cnt++;
        }
        else
        {
          
            int bars_cut = this->rndInt(1, 2);
            if (cnt == intro_start)
            {
                s->addRenderEvent("Drums - Punk Rock", this->rndInt(0, 32000), 6, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 1, this->createTime(0, 0), 1.0);
                s->setParam(RenderEvent::INTRO_HIHAT, 1);
            }
            else
            {
                if (cnt > intro_start)
                {
                    if (this->rndInt(0, 4) != 0)
                    {
                        s->addRenderEvent("Drums - Punk Rock", this->rndInt(0, 32000), 6, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 1, this->createTime(0, 0), 1.0);
                        s->setParam(RenderEvent::VERSE_HIHAT, 1);
                    }
                    if (this->rndInt(0, 4) != 0)
                    {
                        s->addRenderEvent("Drums - Punk Rock", this->rndInt(0, 32000), 6, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 1, this->createTime(0, 0), 1.0);
                        s->setParam(RenderEvent::FOOT_SNARE, 1);
                    }
                }
            }
            s->addRenderEvent("Drums - Punk Rock", this->rndInt(0, 32000), 6, s->getPartEndBar(i) - bars_cut, s->getPartEndBar(i), 1, this->createTime(0, 0), 1.0);
            s->setParam(RenderEvent::TRANSITION, 1);
            s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 4, s->getPartEndBar(i) - bars_cut, s->getPartEndBar(i), 0, this->createTime(0, 0), 1.0);
            s->setParam(RenderEvent::MODE, 3);
            if (cnt >= bass_start)
            {
                s->addRenderEvent("Fast Bass", this->rndInt(0, 32000), 5, s->getPartStartBar(i), s->getPartEndBar(i) - 1, -1, this->createTime(0, 0), 1.0);
            }
            s->addRenderEvent("Fast Bass", this->rndInt(0, 32000), 5, s->getPartEndBar(i) - 1, s->getPartEndBar(i), -1, this->createTime(0, 0), 1.0);
            if (cnt == 0)
            {
                s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 4, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 0, this->createTime(0, 0), 1.0);
                s->setParam(RenderEvent::MODE, this->rndInt(1, 2));
            }
            if (cnt == 1)
            {
                s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 4, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 0, this->createTime(0, 0), 1.0);
                s->setParam(RenderEvent::MODE, this->rndInt(1, 2));
                s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 2, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 0, this->createTime(0, 0), 0.9);
                s->setParam(RenderEvent::MODE, this->rndInt(1, 2));
            }
            else
            {
                if (cnt > 1)
                {
                    bool skip = false;
                    if (cnt >= bass_start && cnt > intro_start && this->rndInt(0, 3) == 0)
                    {
                        skip = true;
                    }
                    if (!skip)
                    {
                        s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 4, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 0, this->createTime(0, 0), 1.0);
                        s->setParam(RenderEvent::MODE, this->rndInt(1, 2));
                        s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 2, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 0, this->createTime(0, 0), 0.9);
                        s->setParam(RenderEvent::MODE, this->rndInt(1, 2));
                        s->addRenderEvent("Punk Guitar Chords", this->rndInt(0, 32000), 3, s->getPartStartBar(i), s->getPartEndBar(i) - bars_cut, 0, this->createTime(0, 0), 0.9);
                        s->setParam(RenderEvent::MODE, this->rndInt(1, 2));
                    }
                }
            }
            
            cnt++;
        }
    }
    int intro = this->rndInt(0, 1);
    if (intro == 1)
    {
        s->addRenderEvent("Metronome", this->rndInt(0, 32000), 6, 0, 1, 0, this->createTime(-1, 0), 0.8);
    }
    else
    {
        if (intro == 0)
        {
            s->addRenderEvent("Metronome", this->rndInt(0, 32000), 6, 0, 1, 0, this->createTime(-1, 0), 0.8);
            s->setParam(RenderEvent::PITCH, 51);
        }
    }
    s->addRenderEvent("Drums - Simple Cymbal", 0, 6, bars - 1, bars, 1, this->createTime(1, 0), 1.0);
}
