#ifndef TEMPOMOD_H
#define TEMPOMOD_H
#include "Common.h"
#include "Time.h"
using namespace std;
class TempoMod {
 Time pos;
 double mod;
public:
 TempoMod(Time,double);
 Time getPos();
 double getMod();
};
#endif // TEMPOMOD_H
