#ifndef ARRANGER_H
#define ARRANGER_H
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Song.h"
using namespace std;


class Arranger : public MusicScript
{
public:
    virtual ~Arranger() {};
    virtual void arrange(Song *) {};
};
#endif // ARRANGER_H
