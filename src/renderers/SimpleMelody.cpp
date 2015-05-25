#include "SimpleMelody.h"
void SimpleMelody::render(RenderPart *p) {
 for(int i = 0;i < p->getEvents();i++){
 	int pitch=p->getEventPitch(i);
// 	printf("SimpleMelody addNote %d %f %d %d/%s\n",i,(p->getEventStart(i).mBar+p->getEventStart(i).mPos),pitch,pitch/12,Utils::midiToNote(pitch).c_str());
    p->addNote(p->getEventStart(i),p->getEventEnd(i),pitch,127);
 }
}
