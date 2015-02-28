#include "SongCreator.h"


SongCreator::SongCreator()
{

    structures["Classical Structure Big"] = SongCreator::makeStructure<ClassicalStructureBig>;
    structures["Classical Structure Small"] = SongCreator::makeStructure<ClassicalStructureSmall>;
    structures["Modern Song Structure"] = SongCreator::makeStructure<ModernSongStructure>;
    structures["One Part Simple Structure"] = SongCreator::makeStructure<OnePartSimpleStructure>;
    structures["Random Structure"] = SongCreator::makeStructure<RandomStructure>;

    innerStructures["Fixed Classical"] = SongCreator::makeInnerStructure<FixedClassical>;

    rythms["Random Static Rythm"] = SongCreator::makeRythm<RandomStaticRythm>;
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

    ornamentors["No Ornamentation"] = SongCreator::makeOrnamentor<NoOrnamentation>;
    ornamentors["Light Randomizer"] = SongCreator::makeOrnamentor<LightRandomizer>;
    ornamentors["Simple Ornamentation"] = SongCreator::makeOrnamentor<SimpleOrnamentation>;

    arrangers["Basic Test Purpose"] = SongCreator::makeArranger<BasicTestPurposeRender>;
    arrangers["Piano Simple Arrangement"] = SongCreator::makeArranger<PianoSimpleArrangement>;
    arrangers["Piano Advanced Classical"] = SongCreator::makeArranger<PianoAdvancedClassical>;
    arrangers["Piano Advanced Disco"] = SongCreator::makeArranger<PianoAdvancedDisco>;
    arrangers["Piano Advanced Boogie Woogie"] = SongCreator::makeArranger<PianoAdvancedBoogieWoogie>;
    arrangers["Piano Advanced Swinging Blues"] = SongCreator::makeArranger<PianoAdvancedSwingingBlues>;
    arrangers["Simple Ballad Style Arrangement"] = SongCreator::makeArranger<SimpleBalladStyleArrangement>;
    arrangers["Simple Dance Style Arrangement"] = SongCreator::makeArranger<SimpleDanceStyleArrangement>;
    arrangers["Simple Instrumental March Arrangement"] = SongCreator::makeArranger<SimpleInstrumentalMarchArrangement>;
    arrangers["Simple Latin Style Arrangement"] = SongCreator::makeArranger<SimpleLatinStyleArrangement>;
    arrangers["Simple Punk Rock Style Arrangement"] = SongCreator::makeArranger<SimplePunkRockStyleArrangement>;

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
    //        printf("Structure: script:%s seed:%d\n",structureScript.c_str(),seed);
    delete structureGenerator;

    for (int i = 0; i < song->getUniqueParts(); ++i )
    {
        UniquePart *up = song->getUniquePart(i);
        InnerStructureGenerator *innerStructureGenerator = innerStructures.at(up->getScriptStructure())();
        int innerStructureSeed = up->getScriptStructureSeed();
        innerStructureGenerator->setSeed(innerStructureSeed);
        innerStructureGenerator->generateInnerStructure(up);

        //        printf("InnerStructure: script:%s seed:%d\n",up->getScriptStructure().c_str(), innerStructureSeed);

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
                phrase->setUniquePhrase(uniquePhrase);
                phrase->setBars(uniquePhrase->getBars());
                uniquePhrase->setStartsSentence(k == 0);
                uniquePhrase->setEndsSentence(k == phraseCount - 1);
                uniquePhrase->setStartsPart(j == 0 && k == 0);
                uniquePhrase->setEndsPart(j == sentenceCount - 1 && k == phraseCount - 1);
            }
        }
        int bars = uniquePart->getBars();
        currentBar += bars;
    }

    for (int i = 0; i < song->getUniqueParts(); ++i )
    {
        UniquePart *up = song->getUniquePart(i);

        string script = rythmScripts[Utils::getRandomInt(0, rythmScripts.size() - 1)];
        up->setScriptRhythm(script);

        script = harmonyScripts[Utils::getRandomInt(0, harmonyScripts.size() - 1)];
        up->setScriptHarmony(script);

        script = melodyScripts[Utils::getRandomInt(0, melodyScripts.size() - 1)];
        up->setScriptMelody(script);

        script = ornamentScripts[Utils::getRandomInt(0, ornamentScripts.size() - 1)];
        up->setScriptOrnamentation(script);
    }

    for (int i = 0; i < song->getUniqueParts(); ++i )
    {
        UniquePart *up = song->getUniquePart(i);
        string scriptRhythm = up->getScriptRhythm();

        int rythmSeed = up->getScriptRhythmSeed();
        //        printf("Rhythm: script:%s seed:%d\n", scriptRhythm.c_str(), rythmSeed);

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

    for (int i = 0; i < song->getUniqueParts(); ++i )
    {
        UniquePart *up = song->getUniquePart(i);
        int bars = 0;
        for (int j = 0; j < up->getSentences(); ++j    )
        {
            Sentence *sentence = up->getSentence(j);
            int phrases = sentence->getPhrases();
            for (int k = 0; k < phrases; ++k       )
            {
                Phrase *phrase = sentence->getPhrase(k);
                UniquePhrase *uniquePhrase = phrase->getUniquePhrase();
                for (int l = 0; l < uniquePhrase->getEvents(); ++l)
                {
                    Event *event = uniquePhrase->getEvent(l);
                    Event *copy_event = (Event *)event->copy()->translate(bars);

                    up->addEvent(copy_event);

                }
                bars += phrase->getBars();
            }
        }
    }

    for (int i = 0; i < song->getUniqueParts(); ++i )
    {

        UniquePart *up = song->getUniquePart(i);
        string scriptHarmony = up->getScriptHarmony();

        int harmonySeed = up->getScriptHarmonySeed();

        HarmonyGenerator *harmony = harmonies.at(scriptHarmony)();
        harmony->setSeed(harmonySeed);
        //        printf("Harmony: script:%s seed:%d\n", scriptHarmony.c_str(), harmonySeed);

        harmony->generateHarmony(up);

        delete harmony;
    }


    for (int i = 0; i < song->getUniqueParts(); ++i )
    {
        UniquePart *up = song->getUniquePart(i);
        up->assignEventsToHarmony();
    }

    for (int i = 0; i < song->getUniqueParts(); ++i )
    {
        UniquePart *up = song->getUniquePart(i);
        string scriptMelody = up->getScriptMelody();

        int melodySeed = up->getScriptMelodySeed();
        //        printf("Melody: script:%s seed:%d\n", scriptMelody.c_str(), melodySeed);

        MelodyCreator *melody = melodies.at(scriptMelody)();
        melody->setSeed(melodySeed);
        melody->createMelody(up);
        delete melody;
    }

    for (int i = 0; i < song->getParts(); ++i )
    {
        Part *part = song->getPart(i);
        int uniquePartIndex = part->getUniquePart();
        UniquePart *uniquePart = song->getUniquePart(uniquePartIndex);
        string scriptOrnamentation = uniquePart->getScriptOrnamentation();

        int ornamentationSeed = uniquePart->getScriptOrnamentationSeed();
        //        printf("Ornamentation: script:%s seed:%d\n", scriptOrnamentation.c_str(), ornamentationSeed);

        Ornamentor *ornamentor = ornamentors.at(scriptOrnamentation)();
        ornamentor->setSeed(ornamentationSeed);
        ornamentor->ornament(uniquePart, part);

        delete ornamentor;
    }


    //    std::sort(song->renderEvents.begin(), song->renderEvents.end());

    Arranger *arranger = arrangers.at(arrangementScript)();
    arranger->setSeed(seed);
    arranger->arrange(song);
    vector<Track *> *tracks = song->getTracks();

    this->initMidi(midiDriver);


//    song->sortRenderEvents();

    int currentStartBar = 0;
    int previousStartBar = 0;


    //    vector<RenderPart *> currentRenderParts;

    //    printf("Render events %d\n", song->renderEvents.size());

    for (int j = 0; j < song->getParts(); ++j)
    {
        Part *part = song->getPart(j);

        printf("Part %d %d-%d\n", j, part->getStartBar(), part->getEndBar());

        for (std::vector<RenderEvent *>::iterator re = song->renderEvents.begin(); re != song->renderEvents.end(); ++re)

        {
            if (midiDriver->stopAsap) {
                midiDriver->clear();
                return;
            }

            int i = (*re)->trackId;
            Track *track = tracks->at(i);

            int renderSeed = (*re)->getSeed();

            string scriptName = (*re)->getScriptName();
            int initialStep = (*re)->getInitialStep();
            int finalStep = (*re)->getFinalStep();

            if ((part->getStartBar() >= initialStep && part->getEndBar() <= finalStep)
                    || (initialStep >= part->getStartBar() && finalStep <= part->getEndBar()))
            {


                currentStartBar = part->getStartBar();

                //            printf("RenderParts %d-%d %d-%d/%d-%d\n", currentStep, previousStep, currentStartBar, currentEndBar, previousStartBar, previousEndBar);

                if (currentStartBar > previousStartBar)
                {
                    //                    Utils::deleteVector(currentRenderParts);
                    //                  currentRenderParts.clear();
                    midiDriver->process(false);

                }
                printf("RenderEvent script:%s initialStep:%d finalStep:%d seed:%d\n", scriptName.c_str(), initialStep, finalStep, renderSeed);

                UniquePart *up = song->getUniquePart(part->getUniquePart());
                Time timeOffset = (*re)->getTimeOffset();

                RenderPart *rp = new RenderPart(i);


                //            printf("(%d) %x UniquePart %d events\n", song->getUniqueParts(), up, up->getEvents());

                //                currentRenderParts.push_back(rp);

                Renderer *renderer = renderers.at(scriptName)();

                rp->setData(part, up, (*re), song);

                renderer->setSeed(renderSeed);
                renderer->render(rp);

                timeOffset.mBar += part->getStartBar();

                //                rp->translateNotes(part->getStartBar());
                rp->translateNotes(timeOffset);

                renderNotesToMidi(midiDriver);

                //                            printf("RenderPart track:%d startBar:%d endPart:%d metrum:%d script:%s scale:%d seed:%d\n", i, (*p)->getStartBar(), (*p)->getEndBar(), metrum, scriptName.c_str(), (*p)->getScale(), renderSeed);

                //    midiDriver->process(false);


                delete rp;
                delete renderer;
                previousStartBar = currentStartBar;

            }
        }
    }
    //    printf("RenderParts(final) %d right now\n",previousBar);

    renderNotesToMidi(midiDriver);

    // renderParts.clear();
    //    Utils::deleteVector(currentRenderParts);
    //    currentRenderParts.clear();

    midiDriver->process(true);
    midiDriver->mute();


    delete arranger;
}



void SongCreator::initMidi(MidiDriver *midiDriver)
{
    midiDriver->sendTempo(0, 0, 60000000 / song->getTempo());

    vector<Track *> *tracks = song->getTracks();

    for (int i = 0; i < tracks->size(); ++i )
    {
        Track *track = tracks->at(i);
        int pan = track->getPan();
        int vol = track->getVol();

        int channel = i;

        if (track->isPercussion()) {
            channel = 9;
        } else {
            if (i > 7)
                channel = i + 3;
        }

        midiDriver->setTrackName(i, track->getName());
        midiDriver->sendControlChange(0, i, channel, 0xA, pan);
        midiDriver->sendControlChange(0, i, channel, 0x7, vol);

        midiDriver->sendControlChange(0, i, channel, 0x0, 0x7F);
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
        Time t = Time(part->getStartBar(), 0);
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

void SongCreator::renderNotesToMidi(MidiDriver *midiDriver) {
    int offset = 192;
    int metrum = 4;

    /*    vector<Note *> currentNotes;

        for (std::vector<RenderPart *>::iterator crp = currentRenderParts->begin(); crp != currentRenderParts->end(); ++crp)
        {

            vector<Note *> *cnotes = (*crp)->getNotes();

            for (std::vector<Note *>::iterator cn = cnotes->begin(); cn != cnotes->end(); ++cn) {
                currentNotes.push_back(*cn);
            }


        }
        */
    vector<Note *> *currentNotes = song->getNotes();

    song->sortNotes();
    printf("SongCreator::renderNotesToMidi render %d notes\n", currentNotes->size());



    for (std::vector<Note *>::iterator n = currentNotes->begin(); n != currentNotes->end(); ++n)
    {
        int trackIndex = (*n)->getTrackIndex();
        int channel = trackIndex;
        Time start = (*n)->getStart();
        Time end = (*n)->getEnd();
        long onTime = (long)(192 * (start.mBar + start.mPos / metrum)) + offset;
        long offTime = (long)(192 * (end.mBar + end.mPos / metrum)) + offset;


        int note = Utils::clampIntToInt((*n)->getPitch(), 0, 127);
        int velocity = Utils::clampIntToInt((*n)->getVolume(), 0, 127);


        if ((*n)->isPercussion()) {
            channel = 9;
        } else {
            if (trackIndex > 7)
                channel = trackIndex + 3;
        }

        //                            printf("play Note %ld:%ld %d pitch:%d velocity:%d\n",onTime,offTime,trackIndex,note,velocity);

        midiDriver->sendNoteOn(onTime, trackIndex, channel, note, velocity);
        midiDriver->sendNoteOff(offTime, trackIndex, channel, note, velocity);
        //            midiDriver->process(false);

    }

    //    midiDriver->process(false);
    song->clearNotes();

}
