#include "ChordMapHarmony.h"
void ChordMapHarmony::generateHarmony(UniquePart *up) {
 int chords = 6;
 vector<vector<int> > map;

 int map0[]={2,3,4,5,6};
 int map1[]={3,5};
 int map2[]={4,6};
 int map3[]={5,2,1};
 int map4[]={3,6,1};
 int map5[]={4,2};

 map.push_back(Utils::arrayToVector(map0,5));
 map.push_back(Utils::arrayToVector(map1,2));
 map.push_back(Utils::arrayToVector(map2,2));
 map.push_back(Utils::arrayToVector(map3,3));
 map.push_back(Utils::arrayToVector(map4,3));
 map.push_back(Utils::arrayToVector(map5,2));

 int reset = 4;
 if(this->rndInt(0,2) == 0) {
  reset = 8;
 }
 if(this->rndInt(0,2) == 0) {
  reset = 2;
 }
// this->resetSeed();
 int cur_chord = 1;
 if(this->rndInt(0,3) == 0) {
  cur_chord = this->rndInt(1,6);
 }
 int r = 0;
 for(int i = 0;i < up->getBars() - 2;++i ){
       if(r == 0 || this->rndInt(0,2) != 0) {
           up->addHarmonic(this->createTime(i,0),cur_chord,MusicScript::getChord(MAJOR_TRIAD_CHORD));
           if(this->rndInt(0,1) == 0) {
               if(this->rndInt(0,1) == 0) {
                  if(this->rndInt(0,1)==0) {
                   up->addHarmonic(this->createTime(i,this->rndInt(1,up->getMetrum() - 1)),cur_chord,MusicScript::getChord(MAJOR_SEVENTH_CHORD));
                  }
                  else
                  {
                   up->addHarmonic(this->createTime(i,this->rndInt(1,up->getMetrum() - 1)),cur_chord,MusicScript::getChord(ADD_SIXTH_TRIAD_CHORD));

                  }
                   cur_chord = map[cur_chord - 1][this->rndInt(0,map[cur_chord - 1].size() - 1)];
        }
        else {
                   cur_chord = map[cur_chord - 1][this->rndInt(0,map[cur_chord - 1].size() - 1)];
                   up->addHarmonic(this->createTime(i,this->rndInt(1,up->getMetrum() - 1)),cur_chord,MusicScript::getChord(MAJOR_TRIAD_CHORD));
                   cur_chord = map[cur_chord - 1][this->rndInt(0,map[cur_chord - 1].size() - 1)];
        }
      }
      else {
       cur_chord = map[cur_chord - 1][this->rndInt(0,map[cur_chord - 1].size() - 1)];
      }
    }
       r++;
       if(r >= reset) {
           r = 0;
//           this->resetSeed();
           cur_chord = 1;
           if(this->rndInt(0,3) == 0) {
             cur_chord = this->rndInt(1,6);
          }
    }
 }
 if(this->rndInt(0,1) == 0) {
  up->addHarmonic(this->createTime(up->getBars() - 2,0),5,MusicScript::getChord(MAJOR_TRIAD_CHORD));
 }
 else {
  up->addHarmonic(this->createTime(up->getBars() - 2,0),5,MusicScript::getChord(MAJOR_SEVENTH_CHORD));
 }
 up->addHarmonic(this->createTime(up->getBars() - 1,0),1,MusicScript::getChord(MAJOR_TRIAD_CHORD));

//  Utils::deleteVector(map);

}
