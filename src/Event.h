#ifndef EVENT_H
#define EVENT_H
#include "Common.h"
#include "AbstractEvent.h"
#include "Time.h"
using namespace std;
class Event : public AbstractEvent {
 int8_t pitch;
public:
 Event(Time,Time,int8_t);
 Event(Time,Time);
 Event* copy();
 int getPitch();
 void setPitch(int8_t);
};
#endif // EVENT_H
