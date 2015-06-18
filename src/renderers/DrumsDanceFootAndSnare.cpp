#include "DrumsDanceFootAndSnare.h"
void DrumsDanceFootAndSnare::render(RenderPart *p) {
 vector<Pattern*> patterns;
 int w = 0;
 int pit1[] = {35,36};
 float pat1[] = {0};
 patterns.push_back(this->newPattern(1,Utils::arrayToVector(pit1,2),Utils::arrayToVector(pat1,1),119,120));
 if(this->rndInt(0,1) == 0) {
     int pit3[] = {35,36};
     float pat3[] = {0.5 + this->rndInt(0,3)};
     patterns.push_back(this->newPattern(4,Utils::arrayToVector(pit3,2),Utils::arrayToVector(pat3,1),115,116));
 }
 if(this->rndInt(0,2) != 0) {
     int p_pit[] = {52,40,41,48,53,55,56,62,64};
     int pit2[] = {p_pit[this->rndInt(0,9 - 1)]};
     float pat2[] = {1 + this->rndInt(-1,1) * 0.5};
     patterns.push_back(this->newPattern(2,Utils::arrayToVector(pit2,1),Utils::arrayToVector(pat2,1),100,110));
     int pit3[] = {38,39};
     float pat3[] = {this->rndInt(0,1)};
     patterns.push_back(this->newPattern(2,Utils::arrayToVector(pit3,2),Utils::arrayToVector(pat3,1),100,110));
 }
 if(p->getTempo() < 90) {
     for(int i = 0;i < patterns.size();i++   ){
           patterns[i]->Length /= 2.0;
           for(int y = 0;y < patterns[i]->pattern.size();y++){
        patterns[i]->pattern[y] /= 2.0;
      }
   }
 }
 if(p->getTempo() > 199) {
     for(int i = 0;i < patterns.size();i++   ){
           patterns[i]->Length *= 2.0;
           for(int y = 0;y < patterns[i]->pattern.size();y++){
        patterns[i]->pattern[y] *= 2.0;
      }
   }
 }
 for(int i = 0;i < patterns.size();i++ ){
   this->realizePattern(p,patterns[i]);
 }

  Utils::deleteVector(patterns);

}
