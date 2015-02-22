#ifndef SIMPLEBALLADSTYLEARRANGEMENT_H
#define SIMPLEBALLADSTYLEARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class SimpleBalladStyleArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // SIMPLEBALLADSTYLEARRANGEMENT_H
