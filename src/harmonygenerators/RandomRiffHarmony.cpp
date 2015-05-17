#include "RandomRiffHarmony.h"

void RandomRiffHarmony::generateHarmony(UniquePart *up) {
 int chords = this->rndInt(2,3);
 int *basis = new int[chords];
 if(this->rndInt(0,1) == 0) {
     basis[chords - 1] = 1;
     if(chords == 2) {
         basis[0] = this->rndInt(3,6);
   }
   else {
         basis[0] = this->rndInt(2,6);
         do{
             basis[1] = this->rndInt(3,6);
     }
     while(basis[0] == basis[1]);
   }
 }
 else {
     basis[0] = 1;
     if(chords == 2) {
         basis[1] = this->rndInt(3,6);
   }
   else {
         basis[2] = this->rndInt(3,6);
         do{
             basis[1] = this->rndInt(2,6);
     }
     while(basis[1] == basis[2]);
   }
 }
 vector<Offset*> pattern;
 for(int i = 0;i < chords;++i ){
       pattern.push_back(new Offset());
 }
 pattern[0]->bar = 0;
 pattern[0]->pos = 0;
 if(chords == 2) {
     if(this->rndInt(0,1) == 0) {
         pattern[1]->bar = 1;
         pattern[1]->pos = 0;
   }
   else {
         pattern[1]->bar = 0;
         pattern[1]->pos = up->getMetrum() - 1;
   }
 }
 else {
     if(this->rndInt(0,1) == 0) {
         pattern[1]->bar = 0;
         if(up->getMetrum() == 2) {
      pattern[1]->pos = 1;
     }
     else {
      if(up->getMetrum() == 3) {
       pattern[1]->pos = 2;
      }
      else {
       if(up->getMetrum() == 4) {
        pattern[1]->pos = 2;
       }
       else {
        if(up->getMetrum() == 5) {
         pattern[1]->pos = 3;
        }
        else {
         pattern[1]->pos = up->getMetrum() - 2;
        }
       }
      }
     }
         pattern[2]->bar = 1;
         pattern[2]->pos = 0;
   }
   else {
         pattern[1]->bar = 0;
         if(up->getMetrum() < 5) {
      pattern[1]->pos = up->getMetrum() - 1;
     }
     else {
      pattern[1]->pos = up->getMetrum() - 2;
     }
         pattern[2]->bar = 1;
         pattern[2]->pos = 1;
   }
 }
 for(int i = 0;i < up->getBars();i += 2 ){
       if(i + 2 >= up->getBars() && up->endsSong() && this->rndInt(0,3) != 0) {
           if(this->rndInt(0,1) == 0) {
       basis[chords - 2] = 5;
      }
           basis[chords - 1] = 1;
    }
       for(int c = 0;c < chords;++c    ){
             up->addHarmonic(this->createTime(i + pattern[c]->bar,pattern[c]->pos),basis[c],MusicScript::triadChord(MAJOR_TRIAD_CHORD));
    }
 }

 delete basis;
 Utils::deleteVector(pattern);
}
