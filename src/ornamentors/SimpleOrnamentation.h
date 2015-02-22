#ifndef SIMPLEORNAMENTATION_H
#define SIMPLEORNAMENTATION_H
#include "Common.h"
#include "MusicScript.h"
#include "Ornamentor.h"
#include "UniquePart.h"
#include "Part.h"
#include "Time.h"
using namespace std;
class SimpleOrnamentation : public Ornamentor {
public:
 double getEventLen(UniquePart*,int);
 void ornament(UniquePart*,Part*);
};
#endif // SIMPLEORNAMENTATION_H
