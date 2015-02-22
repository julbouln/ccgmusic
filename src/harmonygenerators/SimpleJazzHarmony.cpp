#include "SimpleJazzHarmony.h"
void SimpleJazzHarmony::generateHarmony(UniquePart *up) {
 int mode = this->rndInt(1,3);
 if(mode == 3) {
  mode = 1;
 }
 int sec_placement = this->rndInt(1,up->getMetrum() - 1);
 if(up->getMetrum() == 2) {
  sec_placement = 1;
 }
 if(up->getMetrum() == 4) {
  sec_placement = 2;
 }
 if(up->getMetrum() == 3) {
  sec_placement = 2;
 }
 if(up->getMetrum() == 5) {
  sec_placement = this->rndInt(2,3);
 }
 if(up->getMetrum() == 6) {
  sec_placement = 3;
 }
 if(up->getMetrum() == 7) {
  sec_placement = this->rndInt(3,4);
 }
 if(up->getMetrum() == 8) {
  sec_placement = 4;
 }
 if(mode == 1) {
     if(this->rndInt(0,1) == 0) {
    up->addHarmonic(this->createTime(0,0),1,new int[4]{1,3,5,7});
   }
   else {
    up->addHarmonic(this->createTime(0,0),3,new int[4]{1,3,5,7});
   }
     for(int i = 1;i < up->getBars() - 2;++i   ){
           int basis = this->rndInt(1,7);
           if(basis == 4) {
               if(this->rndInt(0,1) == 0) {
         up->addHarmonic(this->createTime(i,0),basis,new int[4]{1,3,5,7});
        }
        else {
         up->addHarmonic(this->createTime(i,0),basis,new int[4]{1,3,5,6});
        }
      }
      else {
       up->addHarmonic(this->createTime(i,0),basis,new int[4]{1,3,5,7});
      }
   }
     if(this->rndInt(0,1) == 0) {
    up->addHarmonic(this->createTime(up->getBars() - 2,0),5,new int[4]{1,3,5,7});
   }
   else {
    up->addHarmonic(this->createTime(up->getBars() - 2,0),7,new int[4]{1,3,5,7});
   }
     if(this->rndInt(0,1) == 0) {
    up->addHarmonic(this->createTime(up->getBars() - 1,0),1,new int[3]{1,3,5});
   }
   else {
    up->addHarmonic(this->createTime(up->getBars() - 1,0),1,new int[4]{1,3,5,6});
   }
 }
 else {
     if(this->rndInt(0,1) == 0) {
    up->addHarmonic(this->createTime(0,0),1,new int[4]{1,3,5,7});
   }
   else {
    up->addHarmonic(this->createTime(0,0),3,new int[4]{1,3,5,7});
   }
     for(int i = 0;i < up->getBars() - 1;++i   ){
           if(i != 0) {
               int basis = this->rndInt(1,7);
               if(basis == 4) {
                   if(this->rndInt(0,1) == 0) {
           up->addHarmonic(this->createTime(i,0),basis,new int[4]{1,3,5,7});
          }
          else {
           up->addHarmonic(this->createTime(i,0),basis,new int[4]{1,3,5,6});
          }
        }
        else {
         up->addHarmonic(this->createTime(i,0),basis,new int[4]{1,3,5,7});
        }
      }
           if(i != up->getBars() - 2) {
               int basis = this->rndInt(1,7);
               if(basis == 4) {
                   if(this->rndInt(0,1) == 0) {
           up->addHarmonic(this->createTime(i,sec_placement),basis,new int[4]{1,3,5,7});
          }
          else {
           up->addHarmonic(this->createTime(i,sec_placement),basis,new int[4]{1,3,5,6});
          }
        }
        else {
         up->addHarmonic(this->createTime(i,sec_placement),basis,new int[4]{1,3,5,7});
        }
      }
   }
     if(this->rndInt(0,1) == 0) {
    up->addHarmonic(this->createTime(up->getBars() - 1,0),1,new int[3]{1,3,5});
   }
   else {
    up->addHarmonic(this->createTime(up->getBars() - 1,0),3,new int[4]{1,3,5,7});
   }
 }
}
