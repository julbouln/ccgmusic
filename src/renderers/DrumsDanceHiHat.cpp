#include "DrumsDanceHiHat.h"
void DrumsDanceHiHat::render(RenderPart *p) {
  vector<Pattern *> patterns;
  int w = 0;
  bool b42 = false;
  if (this->rndInt(0, 1) == 0) {
    int pit2[] = {42};
    double pat2[] = {0, 0.25, 0.5};
    patterns.push_back(this->newPattern(1, pit2, pat2, 115, 120));
    b42 = true;
  }
  else {
    int pit2[] = {44};
    double pat2[] = {0};
    patterns.push_back(this->newPattern(1, pit2, pat2, 115, 120));
    int pit3[] = {82};
    double pat3[] = {0.5};
    patterns.push_back(this->newPattern(1, pit3, pat3, 115, 120));
  }
  int pit4[] = {44};
  double pat4[] = {0.5 + 0.25 * this->rndInt(0, 1)};
  patterns.push_back(this->newPattern(1, pit4, pat4, 115, 120));
  int pit5[] = {46};
  double *pat5 = new double[1] {0.51 + 0.25 * this->rndInt(0, 1)};
  patterns.push_back(this->newPattern(1, pit5, pat5, 115, 120));
  if (this->rndInt(0, 1) == 0 && !b42) {
    //     pit5 = new int[1]{42};
    pit5[0] = 42;
    if (b42) {
      pit5[0] = 37;
    }
    delete pat5;
    pat5 = new double[3] {0, 0.5, 0.75};
    patterns.push_back(this->newPattern(1.0, pit5, pat5, 80, 90));
  }
  if (p->getTempo() < 90) {
    for (int i = 0; i < patterns.size(); ++i   ) {
      patterns[i]->Length /= 2.0;
      for (int y = 0; y < Utils::arrayLength(patterns[i]->pattern); ++y      ) {
        patterns[i]->pattern[y] /= 2.0;
      }
    }
  }
  if (p->getTempo() > 199) {
    for (int i = 0; i < patterns.size(); ++i   ) {
      patterns[i]->Length *= 2.0;
      for (int y = 0; y < Utils::arrayLength(patterns[i]->pattern); ++y      ) {
        patterns[i]->pattern[y] *= 2.0;
      }
    }
  }
  for (int i = 0; i < w; ++i ) {
    this->realizePattern(p, patterns[i]);
  }

  delete pat5;
  Utils::deleteVector(patterns);
}
