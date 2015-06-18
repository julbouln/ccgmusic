#include "DrumsDanceHiHat.h"
void DrumsDanceHiHat::render(RenderPart *p) {
  vector<Pattern *> patterns;
  int w = 0;
  bool b42 = false;
  if (this->rndInt(0, 1) == 0) {
    int pit2[] = {42};
    float pat2[] = {0, 0.25, 0.5};
    patterns.push_back(this->newPattern(1, Utils::arrayToVector(pit2,1), Utils::arrayToVector(pat2,3), 115, 120));
    b42 = true;
  }
  else {
    int pit2[] = {44};
    float pat2[] = {0};
    patterns.push_back(this->newPattern(1, Utils::arrayToVector(pit2,1), Utils::arrayToVector(pat2,1), 115, 120));
    int pit3[] = {82};
    float pat3[] = {0.5};
    patterns.push_back(this->newPattern(1, Utils::arrayToVector(pit3,1), Utils::arrayToVector(pat3,1), 115, 120));
  }
  int pit4[] = {44};
  float pat4[] = {0.5 + 0.25 * this->rndInt(0, 1)};
  patterns.push_back(this->newPattern(1, Utils::arrayToVector(pit4,1), Utils::arrayToVector(pat4,1), 115, 120));
  int pit5[] = {46};
  float pat5[] = {0.51 + 0.25 * this->rndInt(0, 1)};
  patterns.push_back(this->newPattern(1, Utils::arrayToVector(pit5,1), Utils::arrayToVector(pat5,1), 115, 120));
  if (this->rndInt(0, 1) == 0 && !b42) {
    //     pit5 = new int[1]{42};
    pit5[0] = 42;
    if (b42) {
      pit5[0] = 37;
    }
    float pat5b[] = {0, 0.5, 0.75};
    patterns.push_back(this->newPattern(1.0, Utils::arrayToVector(pit5,1), Utils::arrayToVector(pat5b,3), 80, 90));
  }
  if (p->getTempo() < 90) {
    for (int i = 0; i < patterns.size(); i++   ) {
      patterns[i]->Length /= 2.0;
      for (int y = 0; y < patterns[i]->pattern.size();y++) {
        patterns[i]->pattern[y] /= 2.0;
      }
    }
  }
  if (p->getTempo() > 199) {
    for (int i = 0; i < patterns.size(); i++   ) {
      patterns[i]->Length *= 2.0;
      for (int y = 0; y < patterns[i]->pattern.size();y++) {
        patterns[i]->pattern[y] *= 2.0;
      }
    }
  }
  for (int i = 0; i < patterns.size(); i++ ) {
    this->realizePattern(p, patterns[i]);
  }

//  delete pat5;
  Utils::deleteVector(patterns);
}
