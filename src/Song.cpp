#include "Song.h"
Song::Song()
{
    this->seed = 10;
    srand(this->seed);
    this->tempo = 120;
}

Song::~Song()
{
    Utils::deleteVector(tracks);
    Utils::deleteVector(uniqueParts);
    Utils::deleteVector(parts);
    Utils::deleteVector(tempoMods);
    Utils::deleteVector(renderEvents);

}

Song::Song(SongCreator *creator)
{
    this->creator = creator;
    this->seed = 10;
    srand(this->seed);
    this->tempo = 120;
}

vector<Note *> *Song::getNotes()
{
    return &notes;
}

void Song::clearNotes()
{
    Utils::deleteVector(notes);
    notes.clear();
}

void Song::sortNotes()
{
    std::sort(notes.begin(), notes.end(), Note::Comparator());
}


SongCreator *Song::getCreator()
{
    return creator;
}
int Song::getTempo()
{
    return tempo;
}
void Song::setTempo(int tempo)
{
    this->tempo = tempo;
}
void Song::setSeed(int seed)
{
    this->seed = seed;
    srand(this->seed);

}
vector<Track *> *Song::getTracks()
{
    return &tracks;
}



void Song::setUniqueParts(int count)
{
    this->setSeed(seed);

        for (int i = uniqueParts.size(); i < count-uniqueParts.size(); i++)
        {
            UniquePart *up=new UniquePart();
            up->randomize(this);
            uniqueParts.push_back(up);

        }

}
int Song::getUniqueParts()
{
    return uniqueParts.size();
}
UniquePart *Song::getUniquePart(int index)
{

    while(index > uniqueParts.size()-1) {
        UniquePart *up=new UniquePart();
        up->randomize(this);
        uniqueParts.push_back(up);
    }
//    printf("Song::getUniquePart %d/%d\n", index,uniqueParts.size());
    return uniqueParts.at(index);
}
void Song::setParts(int count)
{
    for (int i = 0; i < count; i++)
    {
        parts.push_back(new Part());
    }
}
int Song::getParts()
{
    return parts.size();
}
Part *Song::getPart(int index)
{
    return parts.at(index);
}
int Song::getBars()
{
    int bars = 0;
    for (std::vector<Part *>::iterator part = parts.begin(); part != parts.end(); ++part)
    {
        int upIndex = (*part)->getUniquePart();
        UniquePart *up = uniqueParts.at(upIndex);
        bars += up->getBars();
    }
    return bars;
}
int Song::getPartStartBar(int index)
{
    Part *part = parts.at(index);
    return part->getStartBar();
}
int Song::getPartEndBar(int index)
{
    Part *part = parts.at(index);
    return part->getEndBar();
}
void Song::addTrack(string name, int patch, int vol, int pan, bool percussion)
{
    tracks.push_back(new Track(name, patch, vol, pan, percussion));
}

void Song::addRenderEvent(RenderEvent *event) {
    latestRenderEvent = event;
    renderEvents.push_back(event);    
}

void Song::addRenderEvent(string scriptName, int seed, int trackIndex, int initialBar, int finalBar, int8_t octave, Time timeOffset, float volMult)
{
    RenderEvent *event = new RenderEvent(scriptName, seed, initialBar, finalBar, octave, timeOffset, volMult, trackIndex);

    addRenderEvent(event);
}

void Song::setParam(int param, int value)
{
    latestRenderEvent->setParam(param, value);
}
void Song::addTempoMod(Time pos, double val)
{
    tempoMods.push_back(new TempoMod(pos, val));
}
vector<TempoMod *> *Song::getTempoMods()
{
    return &tempoMods;
}

void Song::sortRenderEvents() {
    std::sort(renderEvents.begin(), renderEvents.end(), RenderEvent::Comparator());
}