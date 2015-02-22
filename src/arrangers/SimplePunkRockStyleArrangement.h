#ifndef SIMPLEPUNKROCKSTYLEARRANGEMENT_H
#define SIMPLEPUNKROCKSTYLEARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class SimplePunkRockStyleArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // SIMPLEPUNKROCKSTYLEARRANGEMENT_H
