#ifndef SIMPLESWINGRYTHM_H
#define SIMPLESWINGRYTHM_H
#include "Common.h"
#include "MusicScript.h"
#include "RythmGenerator.h"
#include "UniquePhrase.h"
#include "Time.h"
using namespace std;
class SimpleSwingRythm : public RythmGenerator {
public:
 void Add(UniquePhrase*,Time,Time);
 void generateRythm(UniquePhrase*);
};
#endif // SIMPLESWINGRYTHM_H
