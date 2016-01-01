#include "SongCreator.h"
#include <unistd.h>

#define RVERBOSE 1

SongCreator::SongCreator()
{

/*
    structures[CLASSICAL_STRUCTURE_BIG] = SongCreator::makeStructure<ClassicalStructureBig>;
    structures[CLASSICAL_STRUCTURE_SMALL] = SongCreator::makeStructure<ClassicalStructureSmall>;
    structures[MODERN_SONG_STRUCTURE] = SongCreator::makeStructure<ModernSongStructure>;
    structures[ONE_PART_SIMPLE_STRUCTURE] = SongCreator::makeStructure<OnePartSimpleStructure>;
    structures[RANDOM_STRUCTURE] = SongCreator::makeStructure<RandomStructure>;
*/    
    
    structures["Classical Structure Big"] = SongCreator::makeStructure<ClassicalStructureBig>;
    structures["Classical Structure Small"] = SongCreator::makeStructure<ClassicalStructureSmall>;
    structures["Modern Song Structure"] = SongCreator::makeStructure<ModernSongStructure>;
    structures["One Part Simple Structure"] = SongCreator::makeStructure<OnePartSimpleStructure>;
    structures["Random Structure"] = SongCreator::makeStructure<RandomStructure>;

    innerStructures["Fixed Classical"] = SongCreator::makeInnerStructure<FixedClassical>;

    rythms["Random Static Rythm"] = SongCreator::makeRythm<RandomStaticRythm>;
    rythms["Simple Fixed Rythm"] = SongCreator::makeRythm<SimpleFixedRythm>;
    rythms["Simple Random Rythm"] = SongCreator::makeRythm<SimpleRandomRythm>;
    rythms["Simple Swing Rythm"] = SongCreator::makeRythm<SimpleSwingRythm>;

    harmonies["Advanced Random Harmony"] = SongCreator::makeHarmony<AdvancedRandomHarmony>;
    harmonies["Chord Map Harmony"] = SongCreator::makeHarmony<ChordMapHarmony>;
    harmonies["Random Riff Harmony"] = SongCreator::makeHarmony<RandomRiffHarmony>;
    harmonies["Simple Fixed Harmony"] = SongCreator::makeHarmony<SimpleFixedHarmony>;
    harmonies["Simple Jazz Harmony"] = SongCreator::makeHarmony<SimpleJazzHarmony>;
    harmonies["Simple Random Harmony"] = SongCreator::makeHarmony<SimpleRandomHarmony>;

    melodies["Random Phrased Melody"] = SongCreator::makeMelodyCreator<RandomPhrasedMelody>;
    melodies["Simple Random Melody"] = SongCreator::makeMelodyCreator<SimpleRandomMelody>;
    melodies["Wide Random Melody"] = SongCreator::makeMelodyCreator<WideRandomMelody>;
    melodies["Markov Melody"] = SongCreator::makeMelodyCreator<MarkovMelody>;

    ornamentors["No Ornamentation"] = SongCreator::makeOrnamentor<NoOrnamentation>;
    ornamentors["Light Randomizer"] = SongCreator::makeOrnamentor<LightRandomizer>;
    //ornamentors["Simple Ornamentation"] = SongCreator::makeOrnamentor<SimpleOrnamentation>;

    arrangers["Basic Test Purpose"] = SongCreator::makeArranger<BasicTestPurposeRender>;
//    arrangers["Piano Simple Arrangement"] = SongCreator::makeArranger<PianoSimpleArrangement>;
    arrangers["Simple Arrangement"] = SongCreator::makeArranger<SimpleArrangement>;
    arrangers["Piano Advanced Classical"] = SongCreator::makeArranger<PianoAdvancedClassical>;
    arrangers["Piano Advanced Disco"] = SongCreator::makeArranger<PianoAdvancedDisco>;
    arrangers["Piano Advanced Boogie Woogie"] = SongCreator::makeArranger<PianoAdvancedBoogieWoogie>;
    arrangers["Piano Advanced Swinging Blues"] = SongCreator::makeArranger<PianoAdvancedSwingingBlues>;
    arrangers["Simple Ballad Style Arrangement"] = SongCreator::makeArranger<SimpleBalladStyleArrangement>;
    arrangers["Simple Dance Style Arrangement"] = SongCreator::makeArranger<SimpleDanceStyleArrangement>;
    arrangers["Simple Instrumental March Arrangement"] = SongCreator::makeArranger<SimpleInstrumentalMarchArrangement>;
    arrangers["Light Instrumental March Arrangement"] = SongCreator::makeArranger<LightInstrumentalMarchArrangement>;
    arrangers["Simple Latin Style Arrangement"] = SongCreator::makeArranger<SimpleLatinStyleArrangement>;
    arrangers["Simple Punk Rock Style Arrangement"] = SongCreator::makeArranger<SimplePunkRockStyleArrangement>;
    arrangers["Random Electro Rock"] = SongCreator::makeArranger<RandomElectroRock>;

    renderers["Accented Melody"] = SongCreator::makeRenderer<AccentedMelody>;
    renderers["Arpeggio Chords"] = SongCreator::makeRenderer<ArpeggioChords>;
    renderers["Arpeggio Chords Fast"] = SongCreator::makeRenderer<ArpeggioChordsFast>;
    renderers["Boogie Woogie"] = SongCreator::makeRenderer<BoogieWoogie>;
    renderers["Boogie Woogie Swing"] = SongCreator::makeRenderer<BoogieWoogieSwing>;
    renderers["Chordal Melody"] = SongCreator::makeRenderer<ChordalMelody>;
    renderers["Disco Jumping Bass"] = SongCreator::makeRenderer<DiscoJumpingBass>;
    renderers["Drums - Dance Foot & Snare"] = SongCreator::makeRenderer<DrumsDanceFootAndSnare>;
    renderers["Drums - Dance Hi-Hat"] = SongCreator::makeRenderer<DrumsDanceHiHat>;
    renderers["Drums - Dance Snare Attack"] = SongCreator::makeRenderer<DrumsDanceSnareAttack>;
    renderers["Drums - Latin"] = SongCreator::makeRenderer<DrumsLatin>;
    renderers["Drums - March"] = SongCreator::makeRenderer<DrumsMarch>;
    renderers["Drums - Punk Rock"] = SongCreator::makeRenderer<DrumsPunkRock>;
    renderers["Drums - Simple Cymbal"] = SongCreator::makeRenderer<DrumsSimpleCymbal>;
    renderers["Fast Bass"] = SongCreator::makeRenderer<FastBass>;
    renderers["Latin Bass"] = SongCreator::makeRenderer<LatinBass>;
    renderers["Latin Chords"] = SongCreator::makeRenderer<LatinChords>;
    renderers["March Bass"] = SongCreator::makeRenderer<MarchBass>;
    renderers["March Chords"] = SongCreator::makeRenderer<MarchChords>;
    renderers["March Picolo"] = SongCreator::makeRenderer<MarchPicolo>;
    renderers["Metronome"] = SongCreator::makeRenderer<Metronome>;
    renderers["Punk Guitar Chords"] = SongCreator::makeRenderer<PunkGuitarChords>;
    renderers["Quick Intro Bass"] = SongCreator::makeRenderer<QuickIntroBass>;
    renderers["Random Bass"] = SongCreator::makeRenderer<RandomBass>;
    renderers["Random Bass ( Extended )"] = SongCreator::makeRenderer<RandomBassExtended>;
    renderers["Drums Euclidean"] = SongCreator::makeRenderer<DrumsEuclidean>;
    renderers["Shortest Way Chords Simple"] = SongCreator::makeRenderer<ShortestWayChordsSimple>;
    renderers["Shortest Way Chords Smooth"] = SongCreator::makeRenderer<ShortestWayChordsSmooth>;
    renderers["Simple Bass"] = SongCreator::makeRenderer<SimpleBass>;
    renderers["Simple Chords"] = SongCreator::makeRenderer<SimpleChords>;
    renderers["Simple Chords Smooth"] = SongCreator::makeRenderer<SimpleChordsSmooth>;
    renderers["Simple Melody"] = SongCreator::makeRenderer<SimpleMelody>;
    renderers["Sine Velocity Simple Melody"] = SongCreator::makeRenderer<SineVelocitySimpleMelody>;
    renderers["Swinging Blues"] = SongCreator::makeRenderer<SwingingBlues>;

    for (map<string, InnerStructureGeneratorCreator>::iterator it = innerStructures.begin(); it != innerStructures.end(); ++it)
        innerStructureScripts.push_back(it->first);

    for (map<string, RythmGeneratorCreator>::iterator it = rythms.begin(); it != rythms.end(); ++it)
        rythmScripts.push_back(it->first);

    for (map<string, HarmonyGeneratorCreator>::iterator it = harmonies.begin(); it != harmonies.end(); ++it)
        harmonyScripts.push_back(it->first);

    for (map<string, MelodyCreatorCreator>::iterator it = melodies.begin(); it != melodies.end(); ++it)
        melodyScripts.push_back(it->first);

    for (map<string, OrnamentorCreator>::iterator it = ornamentors.begin(); it != ornamentors.end(); ++it)
        ornamentScripts.push_back(it->first);

}
SongCreator::~SongCreator()
{

    delete song;
}

int SongCreator::getRandomSeed()
{
    return Utils::getRandomInt(1, INT_MAX);
}
long SongCreator::getTick(Time time, int metrum, int offset)
{
    return (long)(192 * (time.mBar + time.mPos / metrum)) + offset;
}

int SongCreator::getChannelFromTrackIndex(int trackIndex, set<int> drumTrackIndices)
{
    if (drumTrackIndices.count(trackIndex) > 0)
    {
        return 9;
    }
    if (trackIndex > 7)
    {
        return trackIndex + 3;
    }
    return trackIndex;
}


void SongCreator::createSong(int seed, int tempo, string structureScript, string arrangementScript, MidiDriver *midiDriver)
{
    song = new Song();

    song->setTempo(tempo);
    song->setSeed(seed);

    StructureGenerator *structureGenerator = structures.at(structureScript)();
    //structureGenerator.setSong(song);
    structureGenerator->setSeed(seed);
    structureGenerator->generateStructure(song);
    #ifdef RVERBOSE
            printf("Structure: script:%s seed:%d\n",structureScript.c_str(),seed);
    #endif
    delete structureGenerator;

    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);
        InnerStructureGenerator *innerStructureGenerator = innerStructures.at(up->getScriptStructure())();
        int innerStructureSeed = up->getScriptStructureSeed();
        innerStructureGenerator->setSeed(innerStructureSeed);
        innerStructureGenerator->generateInnerStructure(up);
    #ifdef RVERBOSE
        printf("InnerStructure: uniquePart:%d script:%s seed:%d\n",i,up->getScriptStructure().c_str(), innerStructureSeed);
    #endif
        delete innerStructureGenerator;
    }

    int currentBar = 0;
    for (int i = 0; i < song->getParts(); i++)
    {
        Part *part = song->getPart(i);
        int uniquePartId = part->getUniquePart();
        UniquePart *uniquePart = song->getUniquePart(uniquePartId);
        part->setStartBar(currentBar);
        part->setEndBar(currentBar + uniquePart->getBars() - 1);
        int sentenceCount = uniquePart->getSentences();
        for (int j = 0; j < sentenceCount; j++)
        {
            Sentence *sentence = uniquePart->getSentence(j);
            int phraseCount = sentence->getPhrases();
            for (int k = 0; k < phraseCount; k++)
            {
                Phrase *phrase = sentence->getPhrase(k);
                int uniquePhraseID = phrase->getUniquePhraseID();
                UniquePhrase *uniquePhrase = uniquePart->getUniquePhrase(uniquePhraseID);

                // Update the phrase reference to a unique phrase
                phrase->setUniquePhrase(uniquePhrase);
                phrase->setBars(uniquePhrase->getBars());

                // Update the unique phrase position info into the part and
                // sentence
                uniquePhrase->setStartsSentence(k == 0);
                uniquePhrase->setEndsSentence(k == phraseCount - 1);
                uniquePhrase->setStartsPart(j == 0 && k == 0);
                uniquePhrase->setEndsPart(j == (sentenceCount - 1) && k == (phraseCount - 1));
            }
        }
        int bars = uniquePart->getBars();
        currentBar += bars;
    }

    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);

        string script = Utils::sampleUniformObjectDistribution(rythmScripts);
        up->setScriptRhythm(script);

        script = Utils::sampleUniformObjectDistribution(harmonyScripts);
        up->setScriptHarmony(script);

        script = Utils::sampleUniformObjectDistribution(melodyScripts);
        up->setScriptMelody(script);

        script = Utils::sampleUniformObjectDistribution(ornamentScripts);
        up->setScriptOrnamentation(script);
    }

    // Generate rythms
    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);
         string scriptRhythm = up->getScriptRhythm();
//        string scriptRhythm = "Simple Fixed Rythm";

        int rythmSeed = up->getScriptRhythmSeed();
            #ifdef RVERBOSE
            printf("Rhythm uniquePart:%d script:%s seed:%d\n", i, scriptRhythm.c_str(), rythmSeed);
            #endif

        for (int j = 0; j < up->getUniquePhrases(); ++j    )
        {
            RythmGenerator *rythm = rythms.at(scriptRhythm)();
            rythm->setSeed(rythmSeed);

            UniquePhrase *uniquePhrase = up->getUniquePhrase(j);
            rythm->setSong(song);
            rythm->generateRythm(uniquePhrase);
            delete rythm;

        }
    }

    // After the rythm is generated, we have events in the unique phrases
    // that must be copied to the unique part
    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);
        int bars = 0;
        for (int j = 0; j < up->getSentences(); j++)
        {
            Sentence *sentence = up->getSentence(j);
            int phrases = sentence->getPhrases();

            for (int k = 0; k < phrases; k++)
            {
                Phrase *phrase = sentence->getPhrase(k);

                UniquePhrase *uniquePhrase = phrase->getUniquePhrase();
                for (int l = 0; l < uniquePhrase->getEvents(); l++)
                {
//                    Event *event = uniquePhrase->getEvent(l);
//                    Event *copy_event = (Event *)event->copy();
//                    copy_event->translate(bars);
//                    up->addEvent(copy_event);
                   Event event = uniquePhrase->getEvent(l);
                   event.translate(bars);
                   up->addEvent(event);
//
                }
                bars += phrase->getBars();
            }
        }
    }


    

    for (int i = 0; i < song->getUniqueParts(); i++)
    {

        UniquePart *up = song->getUniquePart(i);
        string scriptHarmony = up->getScriptHarmony();
//      string scriptHarmony = "Simple Fixed Harmony";
//        string scriptHarmony = "Random Riff Harmony";

        int harmonySeed = up->getScriptHarmonySeed();

        HarmonyGenerator *harmony = harmonies.at(scriptHarmony)();
        harmony->setSeed(harmonySeed);
        #ifdef RVERBOSE
          printf("Harmony uniquePart:%d script:%s seed:%d\n", i, scriptHarmony.c_str(), harmonySeed);
        #endif
        harmony->generateHarmony(up);

        delete harmony;
    }


    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);
        up->assignEventsToHarmony();
    }

    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);
        string scriptMelody = up->getScriptMelody();
//       string scriptMelody = "Simple Random Melody";
//       string scriptMelody = "Random Phrased Melody";
//       string scriptMelody = "Wide Random Melody";
//       string scriptMelody = "Markov Melody";

        int melodySeed = up->getScriptMelodySeed();
        #ifdef RVERBOSE
            printf("Melody uniquePart:%d script:%s seed:%d\n", i, scriptMelody.c_str(), melodySeed);
        #endif
        MelodyCreator *melody = melodies.at(scriptMelody)();
        melody->setSeed(melodySeed);
        melody->createMelody(up);
        delete melody;
    }

    for (int i = 0; i < song->getParts(); i++)
    {
        Part *part = song->getPart(i);
        int uniquePartIndex = part->getUniquePart();
        UniquePart *uniquePart = song->getUniquePart(uniquePartIndex);
        string scriptOrnamentation = uniquePart->getScriptOrnamentation();
//        string scriptOrnamentation = "No Ornamentation";

        int ornamentationSeed = uniquePart->getScriptOrnamentationSeed();
        #ifdef RVERBOSE
            printf("Ornamentation uniquePart: %d part:%d script:%s seed:%d\n", uniquePartIndex,i,scriptOrnamentation.c_str(), ornamentationSeed);
        #endif
        Ornamentor *ornamentor = ornamentors.at(scriptOrnamentation)();
        ornamentor->setSeed(ornamentationSeed);
        ornamentor->ornament(uniquePart, part);

        delete ornamentor;
    }



    //    std::sort(song->renderEvents.begin(), song->renderEvents.end());

    Arranger *arranger = arrangers.at(arrangementScript)();
    arranger->setSeed(seed);
    arranger->arrange(song);
    delete arranger;

/*
    for (int i = 0; i < song->getUniqueParts(); i++)
    {
        UniquePart *up = song->getUniquePart(i);
     for (int j = 0; j < up->getUniquePhrases(); ++j    )
        {
           
            UniquePhrase *uniquePhrase = up->getUniquePhrase(j);
                uniquePhrase->clearEvents();

        }
    }
*/
    
    for (int i = 0; i < song->getUniqueParts(); i++)
    {
                UniquePart *up = song->getUniquePart(i);

//                printf("Harmonics size %d %d ~ %d\n",i,up->getHarmonicList()->size(),sizeof(Harmonic)*up->getHarmonicList()->size());

//                printf("Events size %d %d ~ %d\n",i,up->getEventList()->size(),sizeof(Event)*up->getEventList()->size());


                up->clearUniquePhrases();

    }

    this->initMidi(midiDriver);


//    song->sortRenderEvents();

    int currentStartBar = 0;
    int previousStartBar = 0;

    //    printf("Render events %d\n", song->renderEvents.size());

    for (std::vector<Part *>::iterator p = song->parts.begin(); p != song->parts.end(); )

//    for (int j = 0; j < song->getParts(); j++)
    {
  //      Part *part = song->getPart(j);

//        printf("Part %d %d-%d\n", j, part->getStartBar(), part->getEndBar());

        for (std::vector<RenderEvent *>::iterator re = song->renderEvents.begin(); re != song->renderEvents.end(); )

        {

            if (midiDriver->getStop()) { // return right now
//                midiDriver->clear();
                return;
            }

            int i = (*re)->trackId;

            int renderSeed = (*re)->getSeed();

            string scriptName = (*re)->getScriptName();
            int initialStep = (*re)->getInitialStep();
            int finalStep = (*re)->getFinalStep();

            if (((*p)->getStartBar() >= initialStep && (*p)->getEndBar() <= finalStep)
                    || (initialStep >= (*p)->getStartBar() && finalStep <= (*p)->getEndBar()))
            {


                currentStartBar = (*p)->getStartBar();

                if (currentStartBar > previousStartBar)
                {
                   
                   midiDriver->wait();
//                   printf("continue for driver queue %d\n",midiDriver->getQueueSize());

                }
                #ifdef RVERBOSE
                    printf("RenderEvent script:%s initialStep:%d finalStep:%d seed:%d\n", scriptName.c_str(), initialStep, finalStep, renderSeed);
                #endif

                UniquePart *up = song->getUniquePart((*p)->getUniquePart());
                int metrum = up->getMetrum();
                Time timeOffset = (*re)->getTimeOffset();

                RenderPart *rp = new RenderPart(i);
                Renderer *renderer = renderers.at(scriptName)();

                rp->setData((*p), up, (*re), song);

                renderer->setSeed(renderSeed);
                renderer->render(rp);

                timeOffset.mBar += (*p)->getStartBar();

                rp->translateNotes(timeOffset);

                renderNotesToMidi(midiDriver,metrum);
//                midiDriver->clear();
//                song->clearNotes();

                delete rp;
                delete renderer;

                RenderEvent *rePtr=(*re);
                re=song->renderEvents.erase(re);
                delete rePtr;

              previousStartBar = currentStartBar;
//                ++re;
            } else {
                ++re;

            }
        }



        // part not needed anymore
        Part *pPtr=(*p);
        p=song->parts.erase(p);
        delete pPtr;
        
//        ++p;
        
    }

}

int SongCreator::trackToChannel(bool is_percussion, int i) {
    // reserved channel 1
        int channel = i+1;
    if (is_percussion) {
            channel = 9;
        } else {
            if (i > 7)
                channel = i + 3 + 1;
        }
        return channel;
}


void SongCreator::initMidi(MidiDriver *midiDriver)
{
    midiDriver->sendTempo(0, 0, 60000000 / song->getTempo());

    vector<Track *> *tracks = song->getTracks();

    for (size_t i = 0; i < tracks->size(); ++i )
    {
        Track *track = tracks->at(i);
        int pan = track->getPan();
        int vol = track->getVol();

        int channel = trackToChannel(track->isPercussion(),i);

        midiDriver->setTrackName(i, track->getName());
        midiDriver->sendControlChange(0, i, channel, 0xA, pan);
        midiDriver->sendControlChange(0, i, channel, 0x7, vol);

//        midiDriver->sendControlChange(0, i, channel, 0x0, 0x7F);
        midiDriver->sendControlChange(0, i, channel, 0x0, 0x0);

//        midiDriver->sendControlChange(0, i, channel, 0x5B, 0x7F);
  //      midiDriver->sendControlChange(0, i, channel, 0x50, 0x04);

  //      midiDriver->sendControlChange(0, i, channel, 0x5D, 0x3F);
    //    midiDriver->sendControlChange(0, i, channel, 0x51, 0x02);
    
        //               midiDriver->sendControlChange(0,i+1,channel,0x20,0x8);

        /*
                       midiDriver->sendControlChange(0,i+1,channel,0x63,0x37);
                       midiDriver->sendControlChange(0,i+1,channel,0x62,0x5F);
                       midiDriver->sendControlChange(0,i+1,channel,0x06,0x45);
        */
        //               printf("ProgamChange track:%s(%d) channel:%d program:%d\n",track->getName().c_str(),i+1,channel,track->getPatch() - 1);
        midiDriver->sendProgramChange(0, i, channel, track->getPatch() - 1);

    }

    int offset = 192;

    for (int i = 0; i < song->getParts(); ++i )
    {
        Part *part = song->getPart(i);
        UniquePart *up = song->getUniquePart(part->getUniquePart());
        int metrum = up->getMetrum();
        double startPosition = (Time(part->getStartBar(), 0)).getPosition(metrum);
        double endPosition = (Time(part->getEndBar(), metrum)).getPosition(metrum);

        long tick = this->getTick(Time(part->getStartBar(), 0), metrum, offset);
        double tempoMod = part->getTempoMod();

        vector<TempoMod *> *mods = song->getTempoMods();
        for (std::vector<TempoMod *>::iterator mod = mods->begin(); mod != mods->end(); ++mod)
        {

            Time modPos = (*mod)->getPos();
            double position = modPos.getPosition(up->getMetrum());
            if (position > startPosition && position < endPosition)
            {
                long modTick = this->getTick((*mod)->getPos(), metrum, offset);

                int tempo = (int)(song->getTempo() * (*mod)->getMod() * tempoMod);

                midiDriver->sendTempo(modTick, 0, 60000000 / tempo);
                //                printf("setTempo: %ld:%d\n", modTick, 60000000 / tempo);

            }
        }
        int tempo = song->getTempo() * tempoMod;
        midiDriver->sendTempo(tick, 0, 60000000 / tempo);
        //        printf("setTempo: %ld:%d\n", tick, 60000000 / tempo);
    }
    //    midiDriver->process(false);

}

void SongCreator::renderNotesToMidi(MidiDriver *midiDriver,int metrum) {
    int offset = 192;

    vector<RenderNote *> *currentNotes = song->getNotes();

    song->sortNotes();
//    printf("SongCreator::renderNotesToMidi render notes %d * %d = %d bytes\n", currentNotes->size(),sizeof(RenderNote),currentNotes->size()*sizeof(RenderNote));


    for (std::vector<RenderNote *>::iterator n = currentNotes->begin(); n != currentNotes->end(); )
    {
            if (midiDriver->getStop()) { // return right now
                break;
            }

        int trackIndex = (*n)->getTrackIndex();
                int channel = trackToChannel((*n)->isPercussion(),trackIndex);

        Time start = (*n)->getStart();
        Time end = (*n)->getEnd();
        long onTime = (long)(192 * (start.mBar + start.mPos / metrum)) + offset;
        long offTime = (long)(192 * (end.mBar + end.mPos / metrum)) + offset;

        int note = Utils::clampIntToInt((*n)->getPitch(), 0, 127);
        if(note < 21 || note > 108) {
            printf("ERROR invalid midi note %d\n",note);
        }
//        printf("add note %d -> %d\n",(*n)->getPitch(),note);
        int velocity = Utils::clampIntToInt((*n)->getVolume(), 0, 127);
//        printf("ADD NOTE %d->%d\n",(*n)->getPitch(),note);


        //                            printf("play Note %ld:%ld %d pitch:%d velocity:%d\n",onTime,offTime,trackIndex,note,velocity);

        midiDriver->sendNoteOn(onTime, trackIndex, channel, note, velocity);
        midiDriver->sendNoteOff(offTime, trackIndex, channel, note, velocity);

        RenderNote *nPtr=(*n);
        n=currentNotes->erase(n);
        delete nPtr;
        
    }

    song->clearNotes();

}
