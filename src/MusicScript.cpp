 #include "MusicScript.h"

int MusicScript::chords[][8] = {
{1, 3, 5,-1,-1,-1,-1, 3}, // MAJOR_TRIAD_CHORD "135"
{1, 3, 5, 6,-1,-1,-1, 4}, // ADD_SIXTH_TRIAD_CHORD "1356"
{1, 3, 5, 7,-1,-1,-1, 4}, // MAJOR_SEVENTH_CHORD "1357"

};

int MusicScript::scales[][7] = {
    { 0, 2, 4, 5, 7, 9, 11 }, // MAJOR_SCALE

    // see http://en.wikipedia.org/wiki/Mode_%28music%29
/*    { 0, 2, 4, 5, 7, 9, 11 }, // IONIAN_SCALE
    { 0, 2, 3, 5, 7, 9, 10 }, // DORIAN_SCALE 
    { 0, 1, 3, 5, 7, 8, 10 }, // PHRYGIAN_SCALE 
    */
    { 0, 2, 4, 6, 7, 9, 11 }, // LYDIAN_SCALE 
/*    { 0, 2, 4, 5, 7, 9, 10 }, // MIXOLYDIAN_SCALE 
    { 0, 2, 3, 5, 7, 8, 10 }, // AEOLIEN_SCALE
    { 0, 1, 3, 5, 6, 8, 10 }, // LOCRIAN_SCALE
  */  
    { 0, 2, 3, 5, 7, 8, 10 }, // NATURAL_MINOR_SCALE
    { 0, 2, 3, 5, 7, 8, 11 }, // HARMONIC_MINOR_SCALE
    { 0, 2, 3, 5, 7, 9, 11 }, // MELODIC_MINOR_SCALE
    
/*    { 0, 2, 4, 6, 7, 9, 10 }, // ACCOUSTIC_SCALE */

/*
    { 0, 2, 3, 5, 6, 9, 10 }, // BLUES_SCALE

    { 0, 1, 3, 5, 7, 8, 11 }, // NEAPOLITAN_MINOR_SCALE
    { 0, 1, 4, 5, 7, 9, 11 }, // NEAPOLITAN_MAJOR_SCALE
    { 0, 1, 3, 5, 7, 9, 10 }, // NEAPOLITAN_DORIAN_SCALE
    { 0, 1, 4, 5, 7, 9, 10 }, // NEAPOLITAN_MIXOLYDIAN_SCALE

    { 0, 1, 4, 5, 6, 9, 10 }, // ORIENTAL_SCALE
    { 0, 2, 4, 5, 6, 9, 10 }, // ARABIAN_SCALE
    { 0, 1, 4, 5, 7, 8, 11 }, // EGYPTIAN_SCALE
    { 0, 1, 4, 5, 6, 8, 11 }, // PERSIAN_SCALE

    { 0, 2, 3, 6, 7, 8, 11 }, // HUNGARIAN_MINOR
    { 0, 3, 4, 6, 7, 9, 10 }, // HUNGARIAN_MAJOR
*/    

  };

int* MusicScript::getScaleOffsets(int scale)
{
    int *offsets = scales[scale];

    if (offsets == NULL)
    {
        //    printf("ERROR could not find scale with name %s\n",scaleName.c_str());
        offsets = scales[MAJOR_SCALE];
    }

    offsets = scales[MAJOR_SCALE];
//    offsets = scales[AEOLIEN_SCALE];
    return offsets;
}

vector<int> MusicScript::getChord(int chord) {
    return Utils::arrayToVector(MusicScript::chords[chord],MusicScript::chords[chord][7]);
}


MusicScript::~MusicScript()
{
}

MusicScript::MusicScript()
{
    srand(this->seed);
}

void MusicScript::setSeed(int seed)
{
    this->seed = seed;
    srand(this->seed);
}
int MusicScript::getSeed()
{
    return seed;
}
void MusicScript::resetSeed()
{
    srand(this->seed);
}
int MusicScript::rndInt(int lower, int upper)
{
    int rnd=Utils::getRandomInt(lower, upper);
    return rnd;
}
double MusicScript::rndFloat(double lower, double upper)
{
    return Utils::getRandomBetween(lower, upper);
}
Time MusicScript::createTime(int bar, double pos)
{
    return Time(bar, pos);
}
int MusicScript::getRandomScale()
{
    int result = this->rndInt(0, SCALES_COUNT-1);
    return result;
}


int MusicScript::getSongTempo()
{
    return song->getTempo();
}


int MusicScript::getRandom(int patches[])
{
    return patches[this->rndInt(0, ARRAY_LENGTH(patches) - 1)];
}

MusicScript::Pattern *MusicScript::newPattern(double l,  vector<int> pit, vector<double> pat, int v1, int v2)
{
    Pattern *p = new Pattern();
    p->Length = l;
    p->Pitches = pit;
    p->pattern = pat;
    p->velfrom = v1;
    p->velto = v2;
    return p;
}
void MusicScript::realizePattern(RenderPart *p, Pattern *pat)
{
    for (int i = p->getStartBar(); i < p->getEndBar(); ++i )
    {
        for (double m = 0; m < p->getUniquePart()->getMetrum(); m += pat->Length)
        {
            for (int n = 0; n < pat->pattern.size(); ++n)
            {
                if (pat->pattern[n] + m < p->getUniquePart()->getMetrum())
                {
                    for (int q = 0; q < pat->Pitches.size(); ++q)
                    {
                        p->addPercNote(this->createTime(i, m + pat->pattern[n]), this->createTime(i, m + pat->pattern[n] + 0.1), pat->Pitches[q], this->rndInt(pat->velfrom, pat->velto));
                    }
                }
            }
        }
    }
}
void MusicScript::setSong(Song *song)
{
    this->song = song;
}
