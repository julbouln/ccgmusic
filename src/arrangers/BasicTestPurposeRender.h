#ifndef BASICTESTPURPOSERENDER_H
#define BASICTESTPURPOSERENDER_H
#include "Common.h"
#include "MusicScript.h"
#include "Arranger.h"
#include "Song.h"
using namespace std;
class BasicTestPurposeRender : public Arranger {
public:
 string getScriptName();
 void arrange(Song*);
};
#endif // BASICTESTPURPOSERENDER_H
