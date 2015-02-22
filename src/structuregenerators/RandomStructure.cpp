#include "RandomStructure.h"
void RandomStructure::generateStructure(Song *song) {
 song->setUniqueParts(this->rndInt(1,4));
 song->setParts(this->rndInt(song->getUniqueParts(),(song->getUniqueParts() * 3)));
 int metrum = this->rndInt(0,2);
 if(metrum == 0) {
     for(int i = 0;i < song->getUniqueParts();++i   ){
     song->getUniquePart(i)->setMetrum(4);
   }
 }
 if(metrum == 1) {
     int m = this->rndInt(2,8);
     for(int i = 0;i < song->getUniqueParts();++i   ){
     song->getUniquePart(i)->setMetrum(m);
   }
 }
 if(metrum == 2) {
     for(int i = 0;i < song->getUniqueParts();++i   ){
     song->getUniquePart(i)->setMetrum(this->rndInt(2,8));
   }
 }
 int *trans = new int[3];
 trans[0] = this->rndInt(0,11);
 trans[1] = (trans[0] + 5) % 12;
 trans[2] = (trans[1] + 5) % 12;
 for(int i = 0;i < song->getParts();++i ){
       Part *p = song->getPart(i);
       p->setUniquePart(this->rndInt(0,song->getUniqueParts() - 1));
       p->setTranspose(trans[this->rndInt(0,2)]);
       p->setTempoMod(1.0);
       p->setScale(this->getRandomScale());
       p->setArrHint(this->rndInt(1,3));
 }
 delete trans;
}
