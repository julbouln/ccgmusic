#ifndef MELODYCREATOR_H
#define MELODYCREATOR_H
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Seedable.h"
#include "UniquePart.h"
using namespace std;
class MelodyCreator : public MusicScript
{
public:
    virtual ~MelodyCreator() {};
    virtual void createMelody(UniquePart *) {};
};
#endif // MELODYCREATOR_H
