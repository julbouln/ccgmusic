#include "SimpleMelody.h"
void SimpleMelody::render(RenderPart *p) {
 for(int i = 0;i < p->getEvents();++i ){

// 	printf("SimpleMelody addNote %d %d %d/%s\n",i,p->getEventPitch(i),p->getEventPitch(i)/12,Utils::midiToNoteFr(p->getEventPitch(i)).c_str());
    p->addNote(p->getEventStart(i),p->getEventEnd(i),p->getEventPitch(i),127);
 }
}
