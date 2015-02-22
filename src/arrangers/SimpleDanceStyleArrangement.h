#ifndef SIMPLEDANCESTYLEARRANGEMENT_H
#define SIMPLEDANCESTYLEARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class SimpleDanceStyleArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // SIMPLEDANCESTYLEARRANGEMENT_H
