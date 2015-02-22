#include "SimpleMelody.h"
void SimpleMelody::render(RenderPart *p) {
 for(int i = 0;i < p->getEvents();++i ){
 	//	printf("SimpleMelody::addNote %d start:%d/%f end:%d/%f pitch:%d\n",i,p->getEventStart(i).mBar,p->getEventStart(i).mPos,p->getEventEnd(i).mBar,p->getEventEnd(i).mPos,p->getEventPitch(i));
       p->addNote(p->getEventStart(i),p->getEventEnd(i),p->getEventPitch(i),127);

 }
}
