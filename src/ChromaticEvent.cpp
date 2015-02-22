#include "ChromaticEvent.h"

ChromaticEvent::ChromaticEvent(Time begin,Time end,int chrPitch) : AbstractEvent(begin,end) {
 this->chromaticNote = chrPitch;
}
ChromaticEvent::ChromaticEvent(Time begin,Time end) : AbstractEvent(begin,end) {
 this->chromaticNote = 0;	
}
ChromaticEvent* ChromaticEvent::copy() {
 return new ChromaticEvent(this->getStart(),this->getEnd(),chromaticNote);
}
int ChromaticEvent::getChromaticNote() {
 return chromaticNote;
}
void ChromaticEvent::setChromaticNote(int pitch) {
 this->chromaticNote = pitch;
}
