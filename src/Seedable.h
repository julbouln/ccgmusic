#ifndef SEEDABLE_H
#define SEEDABLE_H
#include "Common.h"
using namespace std;
class Seedable {
public:
 virtual int getSeed() {return 0;};
 virtual void setSeed(int s) {printf("Seedable::setSeed %d should never happen\n",s);};
};
#endif // SEEDABLE_H
