#ifndef PUNKGUITARCHORDS_H
#define PUNKGUITARCHORDS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class PunkGuitarChords : public Renderer {
 int last_harm;
 int low_pit;
public:
 void render(RenderPart*);
private:
 bool* GenerateAccents(int,double,bool);
 void PlacePunkChord(RenderPart*,Time,Time,int,int,bool,int);
 void DoMode1(RenderPart*);
 void DoMode2(RenderPart*);
 void DoMode3(RenderPart*);
	
};
#endif // PUNKGUITARCHORDS_H
