#ifndef LIGHTINSTRUMENTALMARCHARRANGEMENT_H
#define LIGHTINSTRUMENTALMARCHARRANGEMENT_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class LightInstrumentalMarchArrangement : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // LIGHTINSTRUMENTALMARCHARRANGEMENT_H
