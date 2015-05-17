#include "MusicScript.h"

int MusicScript::triadChords[][3] = {
    {1,3,5}, // MAJOR_TRIAD_CHORD
    {1,5,7}, // MAJ7_TRIAD_CHORD
    {1,2,5}, // SUS2_TRIAD_CHORD
    {1,5,6}, // SUS4_TRIAD_CHORD

};

int MusicScript::quadChords[][4] = {
    {1,3,5,7}, // MAJ7_QUAD_CHORD
    {1,3,5,6}, // MAJ6_QUAD_CHORD

};

int MusicScript::fifthChords[][5] = {
    {1,3,5,6,7}, // MAJ7_FIFTH_CHORD
};


int MusicScript::scales[][7] = {
    { 0, 2, 4, 5, 7, 9, 11 }, // MAJOR_SCALE

    // see http://en.wikipedia.org/wiki/Mode_%28music%29
    { 0, 2, 4, 5, 7, 9, 11 }, // IONIAN_SCALE
    { 0, 2, 3, 5, 7, 9, 10 }, // DORIAN_SCALE 
    { 0, 1, 3, 5, 7, 8, 10 }, // PHRYGIAN_SCALE 
    { 0, 2, 4, 6, 7, 9, 11 }, // LYDIAN_SCALE 
    { 0, 2, 4, 5, 7, 9, 10 }, // MIXOLYDIAN_SCALE 
    { 0, 2, 3, 5, 7, 8, 10 }, // AEOLIEN_SCALE
    { 0, 1, 3, 5, 6, 8, 10 }, // LOCRIAN_SCALE
    
    { 0, 2, 3, 5, 7, 8, 10 }, // NATURAL_MINOR_SCALE
    { 0, 2, 3, 5, 7, 8, 11 }, // HARMONIC_MINOR_SCALE
    { 0, 2, 3, 5, 7, 9, 11 }, // MELODIC_MINOR_SCALE
    { 0, 2, 4, 6, 7, 9, 10 }, // ACCOUSTIC_SCALE

    { 0, 2, 3, 5, 6, 9, 10 }, // BLUES_SCALE
    { 0, 2, 3, 6, 7, 8, 10 }, // GYPSY_SCALE
    { 0, 1, 4, 5, 7, 8, 11 }, // DOUBLE_HARMONIC_SCALE
    { 0, 1, 4, 6, 8, 10, 11 }, // ENIGMATIC_SCALE
    { 0, 1, 4, 5, 7, 8, 11 }, // FLAMENCO_SCALE

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

  };

int* MusicScript::getScaleOffsets(int scale)
{
    int *offsets = scales[scale];

    if (offsets == NULL)
    {
        //    printf("ERROR could not find scale with name %s\n",scaleName.c_str());
        offsets = scales[MAJOR_SCALE];
    }

//    offsets = scales[ENIGMATIC_SCALE];
    return offsets;
}

vector<int> MusicScript::triadChord(int chord)
{
    vector<int> r(MusicScript::triadChords[chord],MusicScript::triadChords[chord]+3);
    return r;
}

vector<int> MusicScript::quadChord(int chord)
{
    vector<int> r(MusicScript::quadChords[chord],MusicScript::quadChords[chord]+4);
    return r;
}

vector<int> MusicScript::fifthChord(int chord)
{
    vector<int> r(MusicScript::fifthChords[chord],MusicScript::fifthChords[chord]+5);
    return r;
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

MusicScript::Pattern *MusicScript::newPattern(double l, int pit[], double pat[], int v1, int v2)
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
            for (int n = 0; n < ARRAY_LENGTH(pat->pattern); ++n)
            {
                if (pat->pattern[n] + m < p->getUniquePart()->getMetrum())
                {
                    for (int q = 0; q < ARRAY_LENGTH(pat->Pitches); ++q)
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
