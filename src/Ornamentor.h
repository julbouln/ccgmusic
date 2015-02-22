#ifndef ORNAMENTOR_H
#define ORNAMENTOR_H
#include "Common.h"
#include "Seedable.h"
#include "UniquePart.h"
#include "Part.h"
using namespace std;
class Ornamentor : public MusicScript
{
public:
    virtual ~Ornamentor() {};
    virtual void ornament(UniquePart *, Part *) {};
};
#endif // ORNAMENTOR_H
