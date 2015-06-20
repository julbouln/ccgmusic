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
    metrum = 4;

    structureSeed = 20;
    rythmSeed = 20;
    harmonySeed = 20;
    melodySeed = 20;
    ornamentationSeed = 20;

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

/*
void UniquePart::assignEventsToHarmony()
{
    int bars = this->getBars();
    int metrum = this->getMetrum();
    Time endOfTime = Time(bars - 1, metrum);
    for (size_t i = 0; i < harmonics.size(); i++ )
    {
//        Harmonic *h1 = harmonics.at(i);
        int h1=i;
        Time t1 = harmonics.at(i)->getStartTime();
        Time t2 = endOfTime;
        if (i + 1 < harmonics.size())
        {
//            Harmonic *h2 = harmonics.at(i + 1);
            t2 = harmonics.at(i+1)->getStartTime();
        }
  //      printf("before %s\n",harmonics.at(h1).getEndTime().toString().c_str());
        harmonics.at(h1)->setEndTime(t2);
//        printf("after %s\n",harmonics.at(h1).getEndTime().toString().c_str());

//        for (std::vector<Event *>::iterator e = events.begin(); e != events.end(); ++e)
        for(size_t j=0;j<events.size();j++)
        {
            Event e=events.at(j);
            if (e.intersects(t1, t2, metrum))
            {
                bool hasEvent = eventHarmony.count(j) > 0;
                if (!hasEvent)
                {
                    eventHarmony[j] = h1;
                }
                else
                {
//                    Harmonic *harmonic = eventHarmony.at(j);
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
        if (eventHarmony.count(k) == 0)
        {
            Event e=events.at(k);

            Time start = e.getStart();
            Time end = e.getEnd();
            if (start.getPosition(metrum) >= endOfTime.getPosition(metrum))
            {
//                eventHarmony[k] = harmonics.at(harmonics.size() - 1);
                  eventHarmony[k] = harmonics.size() - 1;
  
            }
            else
            {
                if (end.getPosition(metrum) <= 0)
                {
//                    eventHarmony[k] = harmonics.at(0);
                    eventHarmony[k] = 0;
                }
                else
                {
                    printf("ERROR: not assigned to harmony\n");
                    //               cout  << (this + " event " + e + " not assigned to harmony") << endl;
                }
            }
        }
    }

//    printf("eventHarmony map size %d\n",eventHarmony.size());
}
*/

void UniquePart::assignEventsToHarmony()
{
    int bars = this->getBars();
    int metrum = this->getMetrum();
    Time endOfTime = Time(bars - 1, metrum);
    eventHarmony.resize(events.size(),-1);
    for (size_t i = 0; i < harmonics.size(); i++ )
    {
//        Harmonic *h1 = harmonics.at(i);
        int h1=i;
        Time t1 = harmonics.at(i)->getStartTime();
        Time t2 = endOfTime;
        if (i + 1 < harmonics.size())
        {
//            Harmonic *h2 = harmonics.at(i + 1);
            t2 = harmonics.at(i+1)->getStartTime();
        }
  //      printf("before %s\n",harmonics.at(h1).getEndTime().toString().c_str());
        harmonics.at(h1)->setEndTime(t2);
//        printf("after %s\n",harmonics.at(h1).getEndTime().toString().c_str());

//        for (std::vector<Event *>::iterator e = events.begin(); e != events.end(); ++e)
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
//                    Harmonic *harmonic = eventHarmony.at(j);
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
//                eventHarmony[k] = harmonics.at(harmonics.size() - 1);
                  eventHarmony[k] = harmonics.size() - 1;
  
            }
            else
            {
                if (end.getPosition(metrum) <= 0)
                {
//                    eventHarmony[k] = harmonics.at(0);
                    eventHarmony[k] = 0;
                }
                else
                {
                    printf("ERROR: not assigned to harmony\n");
                    //               cout  << (this + " event " + e + " not assigned to harmony") << endl;
                }
            }
        }
    }

//    printf("eventHarmony map size %d\n",eventHarmony.size());
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
//    pitch=pitch%7;
//    if(pitch < -12)
  //      pitch+=12;

//    printf("UniquePart::setEventPitch index:%d pitch:%d\n",index,pitch);

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
//    Event *event = events.at(index);

    Harmonic *harmonic = harmonics.at(eventHarmony.at(index));
    return harmonic->getBaseNote();
}

void UniquePart::addHarmonic(Time time, int baseNote, vector<int> chordData)
{
//    printf("UniquePart::addHarmonic %s %d(%s)\n",time.toString().c_str(),baseNote, Utils::midiToNote(baseNote-1).c_str());
    harmonics.push_back(new Harmonic(time, baseNote, chordData));
}


// input scale degree / output scale degree
int UniquePart::alignPitchToHarm(int eventIndex, int scaleNote)
{
    int *intervals=MusicScript::progressionIntervals;
    //MusicScript::scales[MusicScript::MAJOR_SCALE];
//    scaleNote=Utils::tone2half(scaleNote-1)+1;
//    Event *event = events.at(eventIndex);
    Harmonic *harmonic = harmonics.at(eventHarmony.at(eventIndex));
    vector<int> scaleDegrees = harmonic->getScaleDegrees();
    int scaleDegree = Utils::positiveMod(scaleNote-1, 7);
//printf("UniquePart::alignPitchToHarm scale degree %d %d\n",scaleNote-1,scaleDegree);

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
    
//    printf("UniquePart::alignPitchToHarm scale result %d %d : %d %d\n",eventIndex,scaleNote-1,scaleDegree,closestNote-1);

//    return closestNote%7;
    return closestNote;
}
void UniquePart::addEvent(Event event)
{
//    printf("UniquePart::addEvent %d\n",event->getPitch());
    events.push_back(event);
}
