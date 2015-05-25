#include "SimpleFixedRythm.h"

void SimpleFixedRythm::generateRythm(UniquePhrase *up)
{
     for (int i = 0; i <up->getBars() - 1; i++)
        for (int b = 0; b <up->getMetrum(); b++)
          up->addEvent (this->createTime(i, b), this->createTime(i, b + 1));
             
    up->addEvent (this->createTime(up->getBars() - 1,0), this->createTime(up->getBars () - 1, up->getMetrum ())); 
}
