#include "PianoSimpleArrangement.h"
string PianoSimpleArrangement::getScriptName() {
    return "Piano Simple Arrangement";
}
void PianoSimpleArrangement::arrange(Song *s) {
    int bars = s->getBars();
    s->addTrack("Melody", GM_ACOUSTIC_GRAND_PIANO, 127, 64, false);
    s->addTrack("Alt Voice", GM_BRIGHT_ACOUSTIC_PIANO, 127, 64, false);
    s->addTrack("Chords", GM_ACOUSTIC_GRAND_PIANO, 127, 64, false);
    for (int i = 0; i < s->getParts(); ++i ) {
        switch (s->getPart(i)->getArrHint()) {
        case MusicScript::MainVoice:
            s->addRenderEvent("Simple Melody", this->rndMax(), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1);
            break;
        case MusicScript::AltVoice:
            s->addRenderEvent("Simple Melody", this->rndMax(), 1, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1);
            break;
        case MusicScript::Chorus:
            s->addRenderEvent("Simple Melody", this->rndMax(), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1);
            s->addRenderEvent("Simple Melody", this->rndMax(), 1, s->getPartStartBar(i), s->getPartEndBar(i), 2, this->createTime(0, 0.05), 0.8);
            break;
        default:
            break;

        }
    }
    s->addRenderEvent("Simple Chords", this->rndMax(), 2, 0, bars, 0, this->createTime(0, 0), 0.8);
}
