#ifndef CHROMATICEVENT_H
#define CHROMATICEVENT_H
#include "Common.h"
#include "AbstractEvent.h"
#include "Time.h"
using namespace std;
class ChromaticEvent : public AbstractEvent {
 int8_t chromaticNote;
public:
 ChromaticEvent(Time,Time,int);
 ChromaticEvent(Time,Time);
 ChromaticEvent* copy();
 int getChromaticNote();
 void setChromaticNote(int);
};
#endif // CHROMATICEVENT_H
