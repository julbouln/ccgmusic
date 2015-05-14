#ifndef SONGCREATOR_H
#define SONGCREATOR_H
#include "Common.h"
#include "StructureGenerator.h"
#include "InnerStructureGenerator.h"
#include "Renderer.h"
#include "Ornamentor.h"
#include "Arranger.h"
#include "RythmGenerator.h"
#include "HarmonyGenerator.h"
#include "MelodyCreator.h"
#include "RenderPart.h"
#include "Song.h"
#include "ClassicalStructureBig.h"
#include "ClassicalStructureSmall.h"
#include "ModernSongStructure.h"
#include "OnePartSimpleStructure.h"
#include "RandomStructure.h"
#include "FixedClassical.h"

#include "RandomStaticRythm.h"
#include "SimpleRandomRythm.h"
#include "SimpleSwingRythm.h"

#include "AdvancedRandomHarmony.h"
#include "ChordMapHarmony.h"
#include "RandomRiffHarmony.h"
#include "SimpleFixedHarmony.h"
#include "SimpleJazzHarmony.h"
#include "SimpleRandomHarmony.h"

#include "RandomPhrasedMelody.h"
#include "SimpleRandomMelody.h"
#include "WideRandomMelody.h"
#include "MarkovMelody.h"

#include "NoOrnamentation.h"
#include "LightRandomizer.h"
#include "SimpleOrnamentation.h"

#include "BasicTestPurposeRender.h"

#include "PianoSimpleArrangement.h"
#include "PianoAdvancedClassical.h"
#include "PianoAdvancedDisco.h"
#include "PianoAdvancedBoogieWoogie.h"
#include "PianoAdvancedSwingingBlues.h"
#include "SimpleBalladStyleArrangement.h"
#include "SimpleDanceStyleArrangement.h"
#include "SimpleInstrumentalMarchArrangement.h"
#include "SimpleLatinStyleArrangement.h"
#include "SimplePunkRockStyleArrangement.h"
#include "AccentedMelody.h"
#include "ArpeggioChords.h"
#include "ArpeggioChordsFast.h"
#include "BoogieWoogie.h"
#include "BoogieWoogieSwing.h"
#include "ChordalMelody.h"
#include "DiscoJumpingBass.h"
#include "DrumsDanceFootAndSnare.h"
#include "DrumsDanceHiHat.h"
#include "DrumsDanceSnareAttack.h"
#include "DrumsLatin.h"
#include "DrumsMarch.h"
#include "DrumsPunkRock.h"
#include "DrumsSimpleCymbal.h"
#include "FastBass.h"
#include "LatinBass.h"
#include "LatinChords.h"
#include "MarchBass.h"
#include "MarchChords.h"
#include "MarchPicolo.h"
#include "Metronome.h"
#include "PunkGuitarChords.h"
#include "QuickIntroBass.h"
#include "RandomBass.h"
#include "RandomBassExtended.h"
#include "ShortestWayChordsSimple.h"
#include "ShortestWayChordsSmooth.h"
#include "SimpleBass.h"
#include "SimpleChords.h"
#include "SimpleChordsSmooth.h"
#include "SimpleMelody.h"
#include "SineVelocitySimpleMelody.h"
#include "SwingingBlues.h"
#include "UniquePart.h"
#include "Part.h"
#include "Sentence.h"
#include "Phrase.h"
#include "UniquePhrase.h"
#include "Event.h"
#include "Track.h"
#include "RenderEvent.h"
#include "Time.h"
#include "TempoMod.h"
#include "Note.h"

#include "MidiDriver.h"

using namespace std;
class Sequence;
class Collection;
class ScriptGetter;
class SongCreator
{

public:

    typedef StructureGenerator *(*StructureGeneratorCreator)();
    typedef InnerStructureGenerator *(*InnerStructureGeneratorCreator)();
    typedef RythmGenerator *(*RythmGeneratorCreator)();
    typedef HarmonyGenerator *(*HarmonyGeneratorCreator)();
    typedef Ornamentor *(*OrnamentorCreator)();
    typedef Arranger *(*ArrangerCreator)();
    typedef MelodyCreator *(*MelodyCreatorCreator)();

    typedef Renderer *(*RendererCreator)();

    template <typename T>
    static StructureGenerator *makeStructure()
    {
        return new T {};
    };
    template <typename T>
    static InnerStructureGenerator *makeInnerStructure()
    {
        return new T {};
    };
    template <typename T>
    static RythmGenerator *makeRythm()
    {
        return new T {};
    };
    template <typename T>
    static HarmonyGenerator *makeHarmony()
    {
        return new T {};
    };
    template <typename T>
    static Ornamentor *makeOrnamentor()
    {
        return new T {};
    };
    template <typename T>
    static Arranger *makeArranger()
    {
        return new T {};
    };
    template <typename T>
    static MelodyCreator *makeMelodyCreator()
    {
        return new T {};
    };

    template <typename T>
    static Renderer *makeRenderer()
    {
        return new T {};
    };

    map<string, StructureGeneratorCreator> structures;
    map<string, InnerStructureGeneratorCreator> innerStructures;
    map<string, RythmGeneratorCreator> rythms;
    map<string, HarmonyGeneratorCreator> harmonies;

    map<string, RendererCreator> renderers;
    map<string, OrnamentorCreator> ornamentors;
    map<string, ArrangerCreator> arrangers;
    map<string, MelodyCreatorCreator> melodies;


    vector<string> innerStructureScripts;
    vector<string> rythmScripts;
    vector<string> harmonyScripts;
    vector<string> melodyScripts;
    vector<string> ornamentScripts;

//    vector<RenderPart *> renderParts;
    Song *song;

    ~SongCreator();
    SongCreator();
    void createSong(int, int, string, string,MidiDriver *);
    void initMidi(MidiDriver *);
    void renderNotesToMidi(MidiDriver *,int);

    int getRandomSeed();
    long getTick(Time, int, int);
    int getChannelFromTrackIndex(int, set<int>);
   
};
#endif // SONGCREATOR_H
