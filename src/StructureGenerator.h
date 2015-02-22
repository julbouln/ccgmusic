#ifndef STRUCTUREGENERATOR_H
#define STRUCTUREGENERATOR_H
#include "Common.h"
#include "MusicScript.h"
#include "Song.h"
using namespace std;
class StructureGenerator : public MusicScript
{
public:
    virtual ~StructureGenerator() {};
    virtual void generateStructure(Song *) {};
};
#endif // STRUCTUREGENERATOR_H
