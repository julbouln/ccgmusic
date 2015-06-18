#include "ChromaticEvent.h"

ChromaticEvent::ChromaticEvent(Time begin,Time end,uint8_t chrPitch) : AbstractEvent(begin,end) {
 this->chromaticNote = chrPitch;
}
ChromaticEvent::ChromaticEvent(Time begin,Time end) : AbstractEvent(begin,end) {
 this->chromaticNote = 0;	
}
int ChromaticEvent::getChromaticNote() {
 return chromaticNote;
}
void ChromaticEvent::setChromaticNote(uint8_t pitch) {
 this->chromaticNote = pitch;
}
