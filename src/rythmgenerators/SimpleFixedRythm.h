#ifndef SIMPLEFIXEDRYTHM_H
#define SIMPLEFIXEDRYTHM_H
#include "Common.h"
#include "MusicScript.h"
#include "RythmGenerator.h"
#include "UniquePhrase.h"
#include "Time.h"
using namespace std;
class SimpleFixedRythm : public RythmGenerator {
public:
 void generateRythm(UniquePhrase*);
};
#endif // SIMPLEFIXEDRYTHM_H
