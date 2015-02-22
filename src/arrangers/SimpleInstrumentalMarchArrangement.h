#ifndef SIMPLEINSTRUMENTALMARCHARRANGEMENT_H
#define SIMPLEINSTRUMENTALMARCHARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class SimpleInstrumentalMarchArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // SIMPLEINSTRUMENTALMARCHARRANGEMENT_H
