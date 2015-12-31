#include "UniquePart.h"
#include "Song.h"
#include "MusicScript.h"


UniquePart::~UniquePart()
{
    //    printf("delete UniquePart %x\n",this);

//    Utils::deleteVector(uniquePhrases);
    Utils::deleteVector(sentences);
    Utils::deleteVector(harmonics);
//    Utils::deleteVector(events);
}

void UniquePart::clearUniquePhrases() {
    Utils::deleteVector(uniquePhrases);
//    Utils::deleteVector(sentences);

}

UniquePart::UniquePart()
{
    scale = MusicScript::MAJOR_SCALE;
    metrum = 4;

    structureSeed = 1;
    rythmSeed = 1;
    harmonySeed = 1;
    melodySeed = 1;
    ornamentationSeed = 1;

    structureScript = "Fixed Classical";
    rythmScript = "Random Static Rythm";
    harmonyScript = "Simple Random Harmony";
    melodyScript = "Simple Random Melody";
    ornamentationScript = "No Ornamentation";
};
void UniquePart::randomize(Song *song)
{
    //    printf("UniquePart::randomize\n");
    structureSeed = Utils::getRandomInt(1, INT_MAX);
    rythmSeed = Utils::getRandomInt(1, INT_MAX);
    harmonySeed = Utils::getRandomInt(1, INT_MAX);
    melodySeed = Utils::getRandomInt(1, INT_MAX);
    ornamentationSeed = Utils::getRandomInt(1, INT_MAX);

    /* structureScript = Utils::sampleUniformObjectDistribution(rnd,song->getCreator()->getInnerStructureScriptNames());
     rythmScript = Utils::sampleUniformObjectDistribution(rnd,song->getCreator().getRythmScriptNames());
     harmonyScript = Utils::sampleUniformObjectDistribution(rnd,song->getCreator().getHarmonyScriptNames());
     melodyScript = Utils::sampleUniformObjectDistribution(rnd,song->getCreator().getMelodyScriptNames());
     ornamentationScript = Utils::sampleUniformObjectDistribution(rnd,song->getCreator().getOrnamentorScriptNames());
    */
}
/*vector<Event *> *UniquePart::getEventList()
{
    return &events;
}
*/
vector<Harmonic *> *UniquePart::getHarmonicList()
{
    return &harmonics;
}

void UniquePart::assignEventsToHarmony()
{
    int bars = this->getBars();
    int metrum = this->getMetrum();
    Time endOfTime = Time(bars - 1, metrum);
    eventHarmony.resize(events.size(),-1);
    for (size_t i = 0; i < harmonics.size(); i++ )
    {
        int h1=i;
        Time t1 = harmonics.at(i)->getStartTime();
        Time t2 = endOfTime;
        if (i + 1 < harmonics.size())
        {
            t2 = harmonics.at(i+1)->getStartTime();
        }

        harmonics.at(h1)->setEndTime(t2);

        for(size_t j=0;j<events.size();j++)
        {
            Event e=events.at(j);
            if (e.intersects(t1, t2, metrum))
            {
                bool hasEvent = eventHarmony.at(j) > -1;
                if (!hasEvent)
                {
                    eventHarmony[j] = h1;
                }
                else
                {
                    int harmonic=eventHarmony.at(j);
                    double oldOverlap = harmonics.at(harmonic)->toInterval2D(metrum).intersect(e.toInterval2D(metrum)).getLength();
                    double newOverlap = harmonics.at(h1)->toInterval2D(metrum).intersect(e.toInterval2D(metrum)).getLength();
                    if (newOverlap > oldOverlap)
                    {
                        eventHarmony[j] = h1;
                    }
                }
            }
        }
    }

    for(size_t k=0;k<events.size();k++)
    {
        if (eventHarmony.at(k) == -1)
        {
            Event e=events.at(k);

            Time start = e.getStart();
            Time end = e.getEnd();
            if (start.getPosition(metrum) >= endOfTime.getPosition(metrum))
            {
                  eventHarmony[k] = harmonics.size() - 1;  
            }
            else
            {
                if (end.getPosition(metrum) <= 0)
                {
                    eventHarmony[k] = 0;
                }
                else
                {
                    printf("ERROR: not assigned to harmony\n");
                }
            }
        }
    }
}


void UniquePart::setSentences(int count)
{
    for (int i = 0; i < count; i++)
    {
        sentences.push_back(new Sentence());
    }

}
int UniquePart::getSentences()
{
    return sentences.size();
}
Sentence *UniquePart::getSentence(int index)
{
    int toAdd = index - sentences.size() + 1;
    for (int i = 0; i < toAdd; i++)
    {
        sentences.push_back(new Sentence());
    }

    return sentences.at(index);
}
void UniquePart::setUniquePhrases(int count)
{
    for (int i = 0; i < count; i++)
    {
        uniquePhrases.push_back(new UniquePhrase());
    }

}
int UniquePart::getUniquePhrases()
{
    return uniquePhrases.size();
}
UniquePhrase *UniquePart::getUniquePhrase(int index)
{
    int toAdd = index - uniquePhrases.size() + 1;
    for (int i = 0; i < toAdd; i++)
    {
        uniquePhrases.push_back(new UniquePhrase());
    }

    return uniquePhrases.at(index);
}
void UniquePart::setMetrum(int metrum)
{
    this->metrum = metrum;
}
int UniquePart::getMetrum()
{
    return metrum;
}
int UniquePart::getBars()
{
    int bars = 0;
    for (std::vector<Sentence *>::iterator s = sentences.begin(); s != sentences.end(); ++s)
    {
        bars += (*s)->getBars();
    }
    return bars;
}
bool UniquePart::endsSong()
{
    return false;
}
int UniquePart::getEvents()
{
    return events.size();
}
Time UniquePart::getEventStart(int index)
{
    return events.at(index).getStart();
}
Time UniquePart::getEventEnd(int index)
{
    return events.at(index).getEnd();
}
int UniquePart::getEventPitch(int index)
{
    return events.at(index).getPitch();
}

// input scale degree
int UniquePart::setEventPitch(int index, int pitch)
{
    events.at(index).setPitch(pitch);
    return pitch;
}
void UniquePart::setScriptStructure(string scriptName)
{
    structureScript = scriptName;
}
void UniquePart::setScriptRhythm(string scriptName)
{
    rythmScript = scriptName;
}
void UniquePart::setScriptMelody(string scriptName)
{
    melodyScript = scriptName;
}
void UniquePart::setScriptHarmony(string scriptName)
{
    harmonyScript = scriptName;
}
void UniquePart::setScriptOrnamentation(string scriptName)
{
    ornamentationScript = scriptName;
}
string UniquePart::getScriptStructure()
{
    return structureScript;
}
string UniquePart::getScriptRhythm()
{
    return rythmScript;
}
string UniquePart::getScriptMelody()
{
    return melodyScript;
}
string UniquePart::getScriptHarmony()
{
    return harmonyScript;
}
string UniquePart::getScriptOrnamentation()
{
    return ornamentationScript;
}
int UniquePart::getScriptStructureSeed()
{
    return structureSeed;
}
int UniquePart::getScriptRhythmSeed()
{
    return rythmSeed;
}
int UniquePart::getScriptMelodySeed()
{
    return melodySeed;
}
int UniquePart::getScriptHarmonySeed()
{
    return harmonySeed;
}
int UniquePart::getScriptOrnamentationSeed()
{
    return ornamentationSeed;
}
void UniquePart::setScriptStructureSeed(int seed)
{
    structureSeed = seed;
}
void UniquePart::setScriptRhythmSeed(int seed)
{
    rythmSeed = seed;
}
void UniquePart::setScriptMelodySeed(int seed)
{
    melodySeed = seed;
}
void UniquePart::setScriptHarmonySeed(int seed)
{
    harmonySeed = seed;
}
void UniquePart::setScriptOrnamentationSeed(int seed)
{
    ornamentationSeed = seed;
}

// get event scale degree
int UniquePart::getEventBasis(int index)
{
    Harmonic *harmonic = harmonics.at(eventHarmony.at(index));
    return harmonic->getBaseNote();
}

void UniquePart::addHarmonic(Time tm, int baseNote, int chord)
{
    Harmonic *h=new Harmonic(tm, baseNote, chord);
    harmonics.push_back(h);
}


// input scale degree / output scale degree
int UniquePart::alignPitchToHarm(int eventIndex, int scaleNote)
{
    int *intervals=MusicScript::scales[scale];
    Harmonic *harmonic = harmonics.at(eventHarmony.at(eventIndex));

    vector<int> scaleDegrees = harmonic->getScaleDegrees();

    int scaleDegree = Utils::positiveMod(scaleNote-1, 7);

    int closestNote = harmonic->getBaseNote();

   if (Utils::contains(scaleDegrees, scaleDegree))
//    if (Utils::contains(scaleDegrees, intervals[scaleDegree]))
    {
//        printf("UniquePart::alignPitchToHarm first scale contains %d (%d/%d)\n",scaleNote-1,scaleDegree,intervals[scaleDegree]);

        closestNote = scaleNote;
    }
    else
    {
        int closestDistance = INT_MAX;
        for (int i = scaleNote - 7; i < scaleNote + 7; i++ )
        {
            scaleDegree = Utils::positiveMod(i-1, 7);
            //printf("UniquePart::alignPitchToHarm scale degree %d %d\n",i-1,scaleDegree);

             if (Utils::contains(scaleDegrees, scaleDegree))
//            if (Utils::contains(scaleDegrees, intervals[scaleDegree]))
            {

                int distance = abs(i - scaleNote);
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    closestNote = i;
                }
//                printf("UniquePart::alignPitchToHarm scale contains %d (%d/%d) %d\n",i-1,scaleDegree,intervals[scaleDegree],closestDistance);

            }
        }
    }
    
    return closestNote;
}
void UniquePart::addEvent(Event event)
{
//    printf("UniquePart::addEvent %d\n",event->getPitch());
    events.push_back(event);
}

void UniquePart::setScale(int scale) {
//  printf("Part::setScale %d\n", scale);
 this->scale = scale;
}