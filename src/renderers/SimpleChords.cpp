#include "SimpleChords.h"
void SimpleChords::render(RenderPart *p) {
 for(int i = 0;i < p->getHarmonicEvents();i++){
       for(int f = 0;f < p->getHarmonicComponents(i);f++){
       		int pitch=p->getHarmonicEventPitch(i,f);

//       	 	printf("SimpleChords addNote %d %f %d %d %d/%s\n",i,(p->getEventStart(i).mBar+p->getEventStart(i).mPos),f,pitch,pitch/12,Utils::midiToNote(pitch).c_str());

             p->addNote(p->getHarmonicEventStart(i),p->getHarmonicEventEnd(i),pitch,127);
    }
 }
}
