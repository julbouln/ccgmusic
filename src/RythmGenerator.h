#ifndef RYTHMGENERATOR_H
#define RYTHMGENERATOR_H
#include "Common.h"
#include "Seedable.h"
#include "UniquePhrase.h"
#include "MusicScript.h"

using namespace std;
class RythmGenerator : public MusicScript {
public:
 virtual ~RythmGenerator() {};
 virtual void generateRythm(UniquePhrase*) {};
};
#endif // RYTHMGENERATOR_H
