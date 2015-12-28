#include "RenderPart.h"
RenderPart::~RenderPart()
{
    //    Utils::deleteVector(notes);
    //    Utils::deleteVector(harmonics);
    //   Utils::deleteVector(chromaticEvents);
}

int RenderPart::getTrackIndex()
{
    return trackIndex;
}
vector<RenderNote *> *RenderPart::getNotes()
{
    //    return &notes;
    return song->getNotes();
}

void RenderPart::setData(Part *part, UniquePart *uniquePart, RenderEvent *re, Song *song)
{
    this->part = part;
    this->uniquePart = uniquePart;

    this->renderEvent = re;
    this->song = song;
/*
    vector<ChromaticEvent *> *chromaticEventList = part->getChromaticEventList();

    for (std::vector<ChromaticEvent *>::iterator ce = chromaticEventList->begin(); ce != chromaticEventList->end(); ++ce)
    {
        chromaticEvents.push_back(*ce);
        //        ChromaticEvent *copy = (*ce)->copy();
        //        chromaticEvents.push_back(copy);

    }
    vector<Harmonic *> *harmonicList = uniquePart->getHarmonicList();

    for (std::vector<Harmonic *>::iterator h = harmonicList->begin(); h != harmonicList->end(); ++h)
    {
        harmonics.push_back(*h);
        //        Harmonic *copy = (*h)->copy();
        //        harmonics.push_back(copy);
    }
*/
}
RenderPart::RenderPart(int trackIndex)
{
    this->trackIndex = trackIndex;
}
int RenderPart::getEvents()
{
    return part->getChromaticEvents();
 //   return chromaticEvents.size();
}
int RenderPart::getHarmonic(Time t)
{
    int metrum = uniquePart->getMetrum();
    double pos = t.getPosition(metrum);
    for (size_t i = 0; i < uniquePart->getHarmonicList()->size(); i++ )
//    for (size_t i = 0; i < harmonics.size(); i++ )
    {
//        Harmonic *h = harmonics.at(i);
        Harmonic *h = uniquePart->getHarmonicList()->at(i);
        Interval2D interval = h->toInterval2D(metrum);
        if (interval.contains(pos) && interval.contains(pos + 0.01))
        {
            return i;
        }
    }
    if (pos < 0)
    {
        return 0;
    }
    else
    {
        return uniquePart->getHarmonicList()->size() - 1;
    }
}
Time RenderPart::getEventStart(int index)
{
    return part->getEventStart(index);

//    return chromaticEvents.at(index)->getStart();
}
Time RenderPart::getEventEnd(int index)
{
    return part->getEventEnd(index);

//    return chromaticEvents.at(index)->getEnd();
}
int RenderPart::getEventPitch(int index)
{
    return 12 * renderEvent->getOctave() + part->getNote(index);

//    return 12 * renderEvent->getOctave() + chromaticEvents.at(index)->getChromaticNote();
}
int RenderPart::getHarmonicEvents()
{
    return uniquePart->getHarmonicList()->size();

//    return harmonics.size();
}
int RenderPart::getHarmonicComponents(int index)
{
    Harmonic *harmonic = uniquePart->getHarmonicList()->at(index);
//    Harmonic *harmonic = harmonics.at(index);
    return harmonic->getOffsets().size();
}

// input chord note index / output chromatic note
int RenderPart::getHarmonicEventPitch(int index, int chordNoteIndex)
{
    int originalChordNoteIndex=chordNoteIndex;
    Harmonic *harmonic = uniquePart->getHarmonicList()->at(index);
//    Harmonic *harmonic = harmonics.at(index);
    vector<int> offsets = harmonic->getOffsets();
    int offsetsLength = offsets.size();
    int octaveOffset = 0;
    while (chordNoteIndex < 0)
    {
        chordNoteIndex += offsetsLength;
        octaveOffset--;
    }
    while (chordNoteIndex >= offsetsLength)
    {
        chordNoteIndex -= offsetsLength;
        octaveOffset++;
    }
    int baseNote = harmonic->getBaseNote();
    int scaleIndex = baseNote + offsets[chordNoteIndex];

    int pitch=12 * renderEvent->getOctave() + octaveOffset * 12 + part->computePitch(scaleIndex);

//    printf("RenderPart::getHarmonicEventPitch: index:%d chordNoteIndex:%d (%d) baseNote:%d -> scaleIndex:%d computePitch:%d pitch:%d(%s)\n",index,chordNoteIndex,originalChordNoteIndex,baseNote,scaleIndex,part->computePitch(scaleIndex),pitch,Utils::midiToNote(pitch).c_str());
    return pitch;
}
Time RenderPart::getHarmonicEventStart(int index)
{
    Harmonic *harmonic = uniquePart->getHarmonicList()->at(index);

//    Harmonic *harmonic = harmonics.at(index);
    return harmonic->getStartTime();
}
Time RenderPart::getHarmonicEventEnd(int index)
{
  Harmonic *harmonic = uniquePart->getHarmonicList()->at(index);

//    Harmonic *harmonic = harmonics.at(index);
    return harmonic->getEndTime();
}

// input scale degree / output chromatic note
int RenderPart::alignPitch(int chromaticChordNote, int scaleOffset)
{
    int baseChrScaleNote = part->computePitch(1);
    int *partScaleOffsets = part->getScaleOffsets();
    int partScaleOffsetsLength = 7;
    vector<int> pitchClasses;// = new int[partScaleOffsetsLength];
    for (int i = 0; i < partScaleOffsetsLength; i++ )
    {
        pitchClasses.push_back((baseChrScaleNote + partScaleOffsets[i]) % 12);
    }
    int inPitchClass = chromaticChordNote % 12;
    int theOriginalScaleIndex = 0;
    /*
    if (!Utils::contains(pitchClasses, inPitchClass))
    {
        printf("HAPPEN?\n");
        // Find the closest scale note
        for (int i = chromaticChordNote - 7; i < chromaticChordNote + 8; i++   )
        {
            printf("%d\n",i);
        }
    }
    */

    for (int i = 0; i < partScaleOffsetsLength; i++ )
    {
        if (inPitchClass == pitchClasses[i])
        {
            theOriginalScaleIndex = i;
            break;
        }
    }

    int currentNote = chromaticChordNote;

    int newPitchClass = pitchClasses[Utils::positiveMod(theOriginalScaleIndex + scaleOffset, partScaleOffsetsLength)];
    int increment = scaleOffset > 0 ? 1 : -1;


    while ((currentNote % 12) != newPitchClass)
    {
        currentNote += increment;
//        printf("RenderPart::alignPitch increment %d %d %d %d\n",theOriginalScaleIndex,currentNote,currentNote % 12,newPitchClass);

    }

// printf("RenderPart::alignPitch result %d %d %d %d\n",chromaticChordNote,newPitchClass,scaleOffset,currentNote);

    return currentNote;
}
int RenderPart::computePitch(int note)
{
//    return part->computePitch(note);
    return note;
}
void RenderPart::addNote(Time start, Time end, int pitch, int volume)
{

    int initialStep = renderEvent->getInitialStep() - part->getStartBar();
    int finalStep = renderEvent->getFinalStep() - part->getStartBar();

    if (start.mBar >= initialStep && start.mBar <= finalStep)
    {
//        printf("RenderPart::addNote %s/%s %d %d/%s\n",start.toString().c_str(),end.toString().c_str(),pitch,pitch/12,Utils::midiToNote(pitch).c_str());

        if(pitch < 21)
            printf("ERROR invalid note pitch %d\n",pitch);

        RenderNote *note = new RenderNote(start, end, pitch, (volume * renderEvent->getVolMult()), trackIndex, false);
        song->getNotes()->push_back(note);
    }
}
void RenderPart::addPercNote(Time start, Time end, int key, int volume)
{
    int initialStep = renderEvent->getInitialStep() - part->getStartBar();
    int finalStep = renderEvent->getFinalStep() - part->getStartBar();
    if (start.mBar >= initialStep && start.mBar <= finalStep)
    {
        RenderNote *note = new RenderNote(start, end, key, (int)(volume * renderEvent->getVolMult()), trackIndex, true);
        //        notes.push_back(note);
        song->getNotes()->push_back(note);

    }
}
int RenderPart::getTempo()
{
    return (int)(part->getTempoMod() * song->getTempo());
}
int RenderPart::getArrHint()
{
    return part->getArrHint();
}
int RenderPart::getStartBar()
{
    return 0;
}
int RenderPart::getEndBar()
{
    return uniquePart->getBars();
}
UniquePart *RenderPart::getUniquePart()
{
    return uniquePart;
}
int RenderPart::getParam(int param)
{
    return renderEvent->getParam(param);
}
void RenderPart::translateNotes(int bars)
{

    for (size_t i = 0; i < song->getNotes()->size(); i++) {
        RenderNote *note = song->getNotes()->at(i);
        int initialStep = renderEvent->getInitialStep() - part->getStartBar();
        int finalStep = renderEvent->getFinalStep() - part->getStartBar();
        if (note->getStart().mBar >= initialStep && note->getStart().mBar <= finalStep)
        {

            note->translate(bars);
        }
    }
}
void RenderPart::translateNotes(Time t)
{
    for (size_t i = 0; i < song->getNotes()->size(); i++) {
        RenderNote *note = song->getNotes()->at(i);

        int initialStep = renderEvent->getInitialStep() - part->getStartBar();
        int finalStep = renderEvent->getFinalStep() - part->getStartBar();
        if (note->getStart().mBar >= initialStep && note->getStart().mBar <= finalStep)
        {

            note->translate(t);
//       } else {
  //          printf("exclude note %d\n",note->getStart().mBar);

        }
    }
}
Part *RenderPart::getPart()
{
    return part;
}
bool RenderPart::isDrumPart()
{
    return false;
}
