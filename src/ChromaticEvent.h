#ifndef CHROMATICEVENT_H
#define CHROMATICEVENT_H
#include "Common.h"
#include "AbstractEvent.h"
#include "Time.h"
using namespace std;
class ChromaticEvent : public AbstractEvent {
 uint8_t chromaticNote;
public:
 ChromaticEvent(Time,Time,uint8_t);
 ChromaticEvent(Time,Time);
 int getChromaticNote();
 void setChromaticNote(uint8_t);
};
#endif // CHROMATICEVENT_H
