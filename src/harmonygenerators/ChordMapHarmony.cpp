#include "ChordMapHarmony.h"
void ChordMapHarmony::generateHarmony(UniquePart *up) {
 int chords = 6;
 vector<int*> map;
 map.push_back(new int[5]{2,3,4,5,6});
 map.push_back(new int[2]{3,5});
 map.push_back(new int[2]{4,6});
 map.push_back(new int[3]{5,2,1});
 map.push_back(new int[3]{3,6,1});
 map.push_back(new int[2]{4,2});

 int reset = 4;
 if(this->rndInt(0,2) == 0) {
  reset = 8;
 }
 if(this->rndInt(0,2) == 0) {
  reset = 2;
 }
 this->resetSeed();
 int cur_chord = 1;
 if(this->rndInt(0,3) == 0) {
  cur_chord = this->rndInt(1,6);
 }
 int r = 0;
 for(int i = 0;i < up->getBars() - 2;++i ){
       if(r == 0 || this->rndInt(0,2) != 0) {
           up->addHarmonic(this->createTime(i,0),cur_chord,new int[3]{1,3,5});
           if(this->rndInt(0,1) == 0) {
               if(this->rndInt(0,1) == 0) {
                   up->addHarmonic(this->createTime(i,this->rndInt(1,up->getMetrum() - 1)),cur_chord,new int[4]{1,3,5,this->rndInt(6,7)});
                   cur_chord = map[cur_chord - 1][this->rndInt(0,Utils::arrayLength(map[cur_chord - 1]) - 1)];
        }
        else {
                   cur_chord = map[cur_chord - 1][this->rndInt(0,Utils::arrayLength(map[cur_chord - 1]) - 1)];
                   up->addHarmonic(this->createTime(i,this->rndInt(1,up->getMetrum() - 1)),cur_chord,new int[3]{1,3,5});
                   cur_chord = map[cur_chord - 1][this->rndInt(0,Utils::arrayLength(map[cur_chord - 1]) - 1)];
        }
      }
      else {
       cur_chord = map[cur_chord - 1][this->rndInt(0,Utils::arrayLength(map[cur_chord - 1]) - 1)];
      }
    }
       ++r;
       if(r >= reset) {
           r = 0;
           this->resetSeed();
           cur_chord = 1;
           if(this->rndInt(0,3) == 0) {
       cur_chord = this->rndInt(1,6);
      }
    }
 }
 if(this->rndInt(0,1) == 0) {
  up->addHarmonic(this->createTime(up->getBars() - 2,0),5,new int[3]{1,3,5});
 }
 else {
  up->addHarmonic(this->createTime(up->getBars() - 2,0),5,new int[4]{1,3,5,7});
 }
 up->addHarmonic(this->createTime(up->getBars() - 1,0),1,new int[3]{1,3,5});

  Utils::deleteVector(map);

}
