#include "PianoAdvancedClassical.h"
string PianoAdvancedClassical::getScriptName() {
  return "Piano Advanced Classical";
}
int PianoAdvancedClassical::ArrangeClassical1(Song *s) {
  int bars = s->getBars();

  int rnd_piano=this->rndInt(1,4);

    int t, f;
    t = rnd_piano*2;
    f = t - 1;

//    printf("PIANO %d\n",f);

    s->addTrack("Melody", this->rndInt(f, t), 127, 64, false);
    s->addTrack("Alt Voice", this->rndInt(f, t), 127, 64, false);
    int a1 = this->rndInt(30, 90);
    s->addTrack("Accomp", this->rndInt(f, t), 125, a1, false);
    s->addTrack("Bass", this->rndInt(f, t), 127, this->rndInt(30, 90), false);
    s->addTrack("Chords", this->rndInt(f, t), 127, this->rndInt(30, 90), false);
    s->addTrack("Accomp2", this->rndInt(f, t), 125, 64 + (60 - a1), false);
  
  int seeds[5];
  int off[5];
  for (int i = 0; i < 5; i++) {
    seeds[i] = this->rndMax();
    off[i] = this->rndInt(0, 1);
  }
  int bass_seed = this->rndMax();
  int bass_seed_chorus = this->rndMax();
  string melody = "Simple Melody";
  if (this->rndInt(0, 2) == 0) {
    melody = "Accented Melody";
  }
  for (int i = 0; i < s->getParts(); i++) {
    switch(s->getPart(i)->getArrHint()) {
      case MusicScript::Introduction:
        s->addRenderEvent("Shortest Way Chords Simple", this->rndMax(), 4, s->getPartStartBar(i), s->getPartEndBar(i) - 1, 1, this->createTime(0, 0), 0.7);
        s->addRenderEvent("Arpeggio Chords", seeds[4], 5, s->getPartStartBar(i), s->getPartEndBar(i) - 1, 1 + off[0], this->createTime(0, 0), 0.7);
        break;
      case MusicScript::MainVoice:
        s->addRenderEvent(melody, this->rndMax(), 0, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1);
        break;
      case MusicScript::AltVoice:
        s->addRenderEvent(melody, this->rndMax(), 1, s->getPartStartBar(i), s->getPartEndBar(i), 1, this->createTime(0, 0), 1);
        break;
      case MusicScript::Chorus:
        s->addRenderEvent("Chordal Melody", this->rndMax(), 0, s->getPartStartBar(i), s->getPartEndBar(i), 2 + this->rndInt(0, 1), this->createTime(0, 0), 0.95);
        s->addRenderEvent(melody, this->rndMax(), 1, s->getPartStartBar(i), s->getPartEndBar(i), 1 + this->rndInt(0, 1), this->createTime(0, 0), 1);
        s->addRenderEvent("Simple Chords", this->rndMax(), 4, s->getPartStartBar(i), s->getPartEndBar(i) - 1, 0, this->createTime(0, 0), 0.7);
        s->addRenderEvent("Arpeggio Chords", this->rndMax(), 5, s->getPartStartBar(i), s->getPartEndBar(i) - 1, 1 + off[3], this->createTime(0, 0), 0.65);
        break;
    }

    s->addRenderEvent("Arpeggio Chords", seeds[s->getPart(i)->getArrHint()], 2, s->getPartStartBar(i), s->getPartEndBar(i) - 1, off[s->getPart(i)->getArrHint()], this->createTime(0, 0), 0.7);
    s->addRenderEvent("Simple Chords", this->rndMax(), 4, s->getPartEndBar(i) - 1, s->getPartEndBar(i), 1 + (seeds[s->getPart(i)->getArrHint()] % 2), this->createTime(0, 0), 0.8);
    if (s->getPart(i)->getArrHint() == MusicScript::Chorus) {
      s->addRenderEvent("Random Bass ( Extended )", bass_seed_chorus, 3, s->getPartStartBar(i), s->getPartEndBar(i), -1, this->createTime(0, 0), 1.0);
    }
    else {
      s->addRenderEvent("Random Bass ( Extended )", bass_seed, 3, s->getPartStartBar(i), s->getPartEndBar(i), this->rndInt(0, 1), this->createTime(0, 0), 0.9);
    }
  }

  s->addRenderEvent("Simple Chords Smooth", this->rndMax(), 2, bars - 1, bars, 3, this->createTime(0, s->getUniquePart(s->getPart(0)->getUniquePart())->getMetrum() / 2), 0.8);
  return 2;
}
void PianoAdvancedClassical::arrange(Song *s) {
  int style = this->rndInt(0, 1);
  int slow = 0;
  if (style == 0) {
    slow = this->ArrangeClassical1(s);
  }
  if (style == 1) {
    slow = this->ArrangeClassical1(s);
  }
  if (slow > 0) {
    int bars = 0;
    for (int i = 0; i < s->getParts(); i++) {
      double metrum = s->getUniquePart(s->getPart(i)->getUniquePart())->getMetrum();
      bars += s->getUniquePart(s->getPart(i)->getUniquePart())->getBars();
      if (i == s->getParts() - 1) {
        s->addTempoMod(this->createTime(bars - 2, metrum / 3), 0.95);
        s->addTempoMod(this->createTime(bars - 2, (metrum / 3) * 2), 0.90);
        s->addTempoMod(this->createTime(bars - 1, 0), 0.8);
      }
      else {
        if (slow > 1) {
          s->addTempoMod(this->createTime(bars - 2, metrum / 3), 0.95);
          s->addTempoMod(this->createTime(bars - 2, (metrum / 3) * 2), 0.90);
          s->addTempoMod(this->createTime(bars - 1, 0), 0.85);
          s->addTempoMod(this->createTime(bars - 1, metrum - 1), 0.95);
        }
      }
    }
  }
}
