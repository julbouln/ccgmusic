#ifndef SIMPLEARRANGEMENT_H
#define SIMPLEARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class SimpleArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // SIMPLEARRANGEMENT_H
