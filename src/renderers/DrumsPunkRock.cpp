#include "DrumsPunkRock.h"
void DrumsPunkRock::DoFootAndSnare(RenderPart *p) {
  double step = 1.0;
  if (p->getTempo() < 120) {
    step /= 2.0;
  }
  bool type = true;
  for (int i = p->getStartBar(); i < p->getEndBar(); ++i ) {
    for (double m = 0; m < p->getUniquePart()->getMetrum(); m += step) {
      if (type) {
        if (this->rndInt(0, 2) != 0 || (m < step)) {
          p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 36, 127);
          if (this->rndInt(0, 2) != 0) {
            p->addPercNote(this->createTime(i, m + step / 2), this->createTime(i, m + step / 2 + 0.1), 36, 127);
          }
        }
        else {
          p->addPercNote(this->createTime(i, m + step / 2), this->createTime(i, m + step / 2 + 0.1), 36, 127);
        }
      }
      else {
        p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 38, 118);
        if (this->rndInt(0, 2) != 0) {
          p->addPercNote(this->createTime(i, m + step / 2), this->createTime(i, m + step / 2 + 0.1), 36, 127);
        }
      }
      if (type) {
        type = false;
      }
      else {
        type = true;
      }
    }
  }
}
void DrumsPunkRock::DoChorusHiHat(RenderPart *p, int pit) {
  double step = 0.5;
  if (p->getTempo() < 120) {
    step /= 2.0;
  }
  for (int i = p->getStartBar(); i < p->getEndBar(); ++i ) {
    for (double m = 0; m < p->getUniquePart()->getMetrum(); m += step) {
      if (i % 2 == 0) {
        if (m < step) {
          if (this->rndInt(0, 1) == 0) {
            p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 57, 125);
          }
          else {
            p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 49, 125);
          }
        }
        else {
          p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), pit, this->rndInt(95, 105));
        }
      }
      else {
        if (m + step >= p->getUniquePart()->getMetrum() && this->rndInt(0, 1) == 0) {
          if (this->rndInt(0, 1) == 0) {
            p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 57, 118);
          }
          else {
            p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 49, 118);
          }
        }
        else {
          p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), pit, this->rndInt(95, 105));
        }
      }
    }
  }
}
void DrumsPunkRock::DoIntroHiHat(RenderPart *p) {
  double step = 1.0;
  if (p->getTempo() < 120) {
    step /= 2.0;
  }
  int bars = 4;
  if (this->rndInt(0, 1) == 0) {
    bars = 2;
  }
  if (this->rndInt(0, 2) == 0) {
    bars = 1;
  }
  for (int i = p->getStartBar(); i < p->getEndBar(); ++i ) {
    if (i % bars == 0) {
      p->addPercNote(this->createTime(i, -step / 2.0), this->createTime(i, -(step / 2.0) + 0.1), 46, 111);
    }
    for (double m = 0; m < p->getUniquePart()->getMetrum(); m += step    ) {
      p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 42, this->rndInt(109, 113));
    }
  }
}
void DrumsPunkRock::DoTransition(RenderPart *p) {
  double step = 0.25;
  if (p->getTempo() < 100) {
    step /= 2.0;
  }
  for (int i = p->getStartBar(); i < p->getEndBar(); ++i ) {
    double start = this->rndInt(0, 1) * step * 2;
    p->addPercNote(this->createTime(i, start), this->createTime(i, start + 0.1), 36, 127);
    p->addPercNote(this->createTime(i, p->getUniquePart()->getMetrum() / 2), this->createTime(i, p->getUniquePart()->getMetrum() / 2 + 0.1), 36, 127);
    p->addPercNote(this->createTime(i, p->getUniquePart()->getMetrum() - step * 2), this->createTime(i, p->getUniquePart()->getMetrum() - step * 2 + 0.1), 36, 127);
    if (this->rndInt(0, 4) != 0) {
      p->addPercNote(this->createTime(i, start), this->createTime(i, start + 0.1), 58, 117);
    }
    if (this->rndInt(0, 4) != 0) {
      p->addPercNote(this->createTime(i, p->getUniquePart()->getMetrum() / 2), this->createTime(i, p->getUniquePart()->getMetrum() / 2 + 0.1), 49, 111);
    }
    if (this->rndInt(0, 4) != 0) {
      p->addPercNote(this->createTime(i, p->getUniquePart()->getMetrum() - step * 2), this->createTime(i, p->getUniquePart()->getMetrum() - step * 2 + 0.1), 58, 117);
    }
    for (double m = start + this->rndInt(1, 2) * step; m < p->getUniquePart()->getMetrum() / 2; m += step    ) {
      p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 38, this->rndInt(108, 115));
    }
    if (i == p->getEndBar() - 1) {
      int n = 0;
      for (double m = p->getUniquePart()->getMetrum() / 2 + step * this->rndInt(0, 2); m < p->getUniquePart()->getMetrum() - step * this->rndInt(0, 1); m += step      ) {
        if (this->rndInt(0, 5) != 0) {
          p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 47 - n * 2, this->rndInt(108, 115));
          if (n < 3 && this->rndInt(0, 1) == 0) {
            ++n;
          }
        }
      }
    }
    else {
      if (this->rndInt(0, 1) == 0) {
        for (double m = p->getUniquePart()->getMetrum() / 2 + step * 2; m < p->getUniquePart()->getMetrum() - step * this->rndInt(0, 2); m += step        ) {
          p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 38, this->rndInt(108, 115));
        }
      }
      else {
        bool type = false;
        if (this->rndInt(0, 1) == 0) {
          type = true;
        }
        for (double m = p->getUniquePart()->getMetrum() / 2 + step * 2; m < p->getUniquePart()->getMetrum() - step * this->rndInt(0, 2); m += step * 2        ) {
          if (type) {
            p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 38, this->rndInt(108, 115));
            p->addPercNote(this->createTime(i, m + step), this->createTime(i, m + step + 0.1), 38, this->rndInt(108, 115));
            type = false;
          }
          else {
            type = true;
            p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), 45, 127);
          }
        }
      }
    }
  }
}
void DrumsPunkRock::render(RenderPart *p) {
  if (p->getParam(RenderEvent::FOOT_SNARE) > 0) {
    this->DoFootAndSnare(p);
  }
  if (p->getParam(RenderEvent::CHORUS_HIHAT) > 0) {
    this->DoChorusHiHat(p, 46);
  }
  if (p->getParam(RenderEvent::VERSE_HIHAT) > 0) {
    this->DoChorusHiHat(p, 51);
  }
  if (p->getParam(RenderEvent::INTRO_HIHAT) > 0) {
    this->DoIntroHiHat(p);
  }
  if (p->getParam(RenderEvent::TRANSITION) > 0) {
    this->DoTransition(p);
  }
}
