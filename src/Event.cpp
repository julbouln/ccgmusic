#include "Event.h"
Event::Event(Time begin,Time end,int pitch) : AbstractEvent(begin,end) {
 this->pitch = pitch;
}
Event::Event(Time begin,Time end) : AbstractEvent(begin,end) {
 this->pitch = 0;
}
Event* Event::copy() {
 return new Event(this->getStart(),this->getEnd(),pitch);
}
int Event::getPitch() {
 return pitch;
}
void Event::setPitch(int pitch) {
 this->pitch = pitch;
}
