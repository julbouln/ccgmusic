#ifndef RANDOMSTATICRYTHM_H
#define RANDOMSTATICRYTHM_H
#include "Common.h"
#include "MusicScript.h"
#include "RythmGenerator.h"
#include "UniquePhrase.h"
#include "Time.h"
using namespace std;
class RandomStaticRythm : public RythmGenerator {
public:
 void Add(UniquePhrase*,Time,Time);
 void generateRythm(UniquePhrase*);
};
#endif // RANDOMSTATICRYTHM_H
