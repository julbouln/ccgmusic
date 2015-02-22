#ifndef SIMPLELATINSTYLEARRANGEMENT_H
#define SIMPLELATINSTYLEARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class SimpleLatinStyleArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // SIMPLELATINSTYLEARRANGEMENT_H
