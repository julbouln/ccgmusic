#include "SimpleFixedHarmony.h"
void SimpleFixedHarmony::generateHarmony(UniquePart *up) {
 up->addHarmonic(this->createTime(0,0),1,new int[3]{1,3,5});
 for(int i = 1;i < up->getBars() - 2;++i ){
    if(i % 2 == 1) {
     up->addHarmonic(this->createTime(i,0),4,new int[3]{1,3,5});
    }
    else {
     up->addHarmonic(this->createTime(i,0),1,new int[3]{1,3,5});
    }
 }
 up->addHarmonic(this->createTime(up->getBars() - 2,0),5,new int[3]{1,3,5});
 up->addHarmonic(this->createTime(up->getBars() - 1,0),1,new int[3]{1,3,5});
}
