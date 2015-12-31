#include "SimpleArrangement.h"
string SimpleArrangement::getScriptName() {
    return "Simple Arrangement";
}

void SimpleArrangement::arrange(Song *s) {
    int inst_pairs[17][2]={
        {GM_ACOUSTIC_GRAND_PIANO,GM_BRIGHT_ACOUSTIC_PIANO},
        {GM_ELECTRIC_PIANO_1,GM_ELECTRIC_PIANO_2},
        {GM_HARPSICHORD,GM_CLAVINET},
        {GM_GUITAR_HARMONICS,GM_GUITAR_HARMONICS},
        {GM_ACOUSTIC_GUITARNYLON,GM_ELECTRIC_GUITARMUTED},
        {GM_ACOUSTIC_GUITARSTEEL,GM_ELECTRIC_GUITARMUTED},
        {GM_ELECTRIC_GUITARJAZZ,GM_ELECTRIC_GUITARMUTED},
        {GM_ELECTRIC_GUITARCLEAN,GM_ELECTRIC_GUITARMUTED},
        {GM_ROCK_ORGAN,GM_PERCUSSIVE_ORGAN},
        {GM_SYN_STRINGS_1,GM_SYN_STRINGS_2},
        {GM_CHURCH_ORGAN,GM_REED_ORGAN},
        {GM_VIOLIN,GM_VIOLA},
        {GM_TRUMPET,GM_TROMBONE},
        {GM_SOPRANO_SAX,GM_ALTO_SAX},
        {GM_SITAR,GM_SITAR},
        {GM_BANJO,GM_BANJO},
        {GM_FLUTE,GM_PAN_FLUTE},
    };

    int inst1,inst2;
    int rnd_inst=this->rndInt(0,16);
    if(this->rndInt(0,1)==0) {
    inst1=inst_pairs[rnd_inst][0];
    inst2=inst_pairs[rnd_inst][1];
    }
    else {
    inst2=inst_pairs[rnd_inst][0];
    inst1=inst_pairs[rnd_inst][1];

    }

//    printf("INSTRUMENTS %d %d\n",inst1,inst2);

    int bars = s->getBars();
    s->addTrack("Melody", inst1, 127, 64, false);
    s->addTrack("Alt Voice", inst2, 127, 64, false);
    s->addTrack("Chords", inst1, 127, 64, false);
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
