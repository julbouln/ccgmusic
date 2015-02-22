#include "RenderPart.h"
RenderPart::~RenderPart()
{
    Utils::deleteVector(notes);
    Utils::deleteVector(harmonics);
    Utils::deleteVector(chromaticEvents);
}

int RenderPart::getTrackIndex()
{
    return trackIndex;
}
vector<Note *> *RenderPart::getNotes()
{
    return &notes;
}

void RenderPart::setData(Part *part, UniquePart *uniquePart, RenderEvent *re, Song *song)
{
    this->part = part;
    this->uniquePart = uniquePart;

    this->renderEvent = re;
    this->song = song;
    vector<ChromaticEvent *> *chromaticEventList = part->getChromaticEventList();

    for (std::vector<ChromaticEvent *>::iterator ce = chromaticEventList->begin(); ce != chromaticEventList->end(); ++ce)
    {
//          chromaticEvents.push_back(*ce);
        ChromaticEvent *copy = (*ce)->copy();
        chromaticEvents.push_back(copy);
  
    }
    vector<Harmonic *> *harmonicList = uniquePart->getHarmonicList();

    for (std::vector<Harmonic *>::iterator h = harmonicList->begin(); h != harmonicList->end(); ++h)
    {
//          harmonics.push_back(*h);
        Harmonic *copy = (*h)->copy();
        harmonics.push_back(copy);
    }

}
RenderPart::RenderPart(int trackIndex)
{
    this->trackIndex = trackIndex;
}
int RenderPart::getEvents()
{
    return chromaticEvents.size();
}
int RenderPart::getHarmonic(Time t)
{
    int metrum = uniquePart->getMetrum();
    double pos = t.getPosition(metrum);
    for (int i = 0; i < harmonics.size(); ++i )
    {
        Harmonic *h = harmonics.at(i);
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
        return harmonics.size() - 1;
    }
}
Time RenderPart::getEventStart(int index)
{
    return chromaticEvents.at(index)->getStart();
}
Time RenderPart::getEventEnd(int index)
{
    return chromaticEvents.at(index)->getEnd();
}
int RenderPart::getEventPitch(int index)
{
    return 12 * renderEvent->getOctave() + chromaticEvents.at(index)->getChromaticNote();
}
int RenderPart::getHarmonicEvents()
{
    return harmonics.size();
}
int RenderPart::getHarmonicComponents(int index)
{
    Harmonic *harmonic = harmonics.at(index);
    return Utils::arrayLength(harmonic->getOffsets());
}
int RenderPart::getHarmonicEventPitch(int index, int chordNoteIndex)
{
    Harmonic *harmonic = harmonics.at(index);
    int *offsets = harmonic->getOffsets();
    int offsetsLength = Utils::arrayLength(offsets);
    int octaveOffset = 0;
    while (chordNoteIndex < 0)
    {
        chordNoteIndex += offsetsLength;
        --octaveOffset;
    }
    while (chordNoteIndex >= offsetsLength)
    {
        chordNoteIndex -= offsetsLength;
        ++octaveOffset;
    }
    int baseNote = harmonic->getBaseNote();
    int scaleIndex = baseNote + offsets[chordNoteIndex];

    return 12 * renderEvent->getOctave() + octaveOffset * 12 + part->computePitch(scaleIndex);
}
Time RenderPart::getHarmonicEventStart(int index)
{
    Harmonic *harmonic = harmonics.at(index);
    return harmonic->getStartTime();
}
Time RenderPart::getHarmonicEventEnd(int index)
{
    Harmonic *harmonic = harmonics.at(index);
    return harmonic->getEndTime();
}
int RenderPart::alignPitch(int chromaticChordNote, int scaleOffset)
{
    int baseChrScaleNote = part->computePitch(1);
    int *partScaleOffsets = part->getScaleOffsets();
    int *pitchClasses = new int[Utils::arrayLength(partScaleOffsets)];
    for (int i = 0; i < Utils::arrayLength(partScaleOffsets); ++i )
    {
        pitchClasses[i] = (baseChrScaleNote + partScaleOffsets[i]) % 12;
    }
    int inPitchClass = chromaticChordNote % 12;
    int theOriginalScaleIndex = 0;
    if (!Utils::contains(pitchClasses, inPitchClass))
    {
        for (int i = chromaticChordNote - 7; i < chromaticChordNote + 8; ++i   )
        {
        }
    }
    for (int i = 0; i < Utils::arrayLength(pitchClasses); ++i )
    {
        if (inPitchClass == pitchClasses[i])
        {
            theOriginalScaleIndex = i;
            break;
        }
    }
    int newPitchClass = pitchClasses[Utils::positiveMod(theOriginalScaleIndex + scaleOffset, Utils::arrayLength(pitchClasses))];
    int increment = scaleOffset > 0 ? 1 : -1;
    int currentNote = chromaticChordNote;
    
    while ((currentNote % 12) != newPitchClass)
    {
        currentNote += increment;
    }
  
    delete pitchClasses;
    return currentNote;
}
int RenderPart::computePitch(int note)
{
    return note;
}
void RenderPart::addNote(Time start, Time end, int pitch, int volume)
{
    int initialStep = renderEvent->getInitialStep() - part->getStartBar();
    int finalStep = renderEvent->getFinalStep() - part->getStartBar();

    if (start.mBar >= initialStep && start.mBar <= finalStep)
    {
        Note *note=new Note(start, end, pitch, (volume * renderEvent->getVolMult()),trackIndex,false);
        notes.push_back(note);
    }
}
void RenderPart::addPercNote(Time start, Time end, int key, int volume)
{
    int initialStep = renderEvent->getInitialStep() - part->getStartBar();
    int finalStep = renderEvent->getFinalStep() - part->getStartBar();
    if (start.mBar >= initialStep && start.mBar <= finalStep)
    {
        notes.push_back(new Note(start, end, key, (int)(volume * renderEvent->getVolMult()),trackIndex,true));
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
    for (std::vector<Note *>::iterator n = notes.begin(); n != notes.end(); ++n)
    {
        (*n)->translate(bars);
    }
    /*
    for (std::vector<PercussionNote *>::iterator n = percNotes.begin(); n != percNotes.end(); ++n)
    {
        (*n)->translate(bars);
    }*/
}
void RenderPart::translateNotes(Time t)
{
    for (std::vector<Note *>::iterator n = notes.begin(); n != notes.end(); ++n)
    {
        (*n)->translate(t);
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
