#ifndef CHORDALMELODY_H
#define CHORDALMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class ChordalMelody : public Renderer {
public:
 double GetNoteLength(RenderPart*,int);
 int abs(int);
 double fabs(double);
 void render(RenderPart*);
};
#endif // CHORDALMELODY_H
