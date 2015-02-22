#ifndef SHORTESTWAYCHORDSSIMPLE_H
#define SHORTESTWAYCHORDSSIMPLE_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class ShortestWayChordsSimple : public Renderer {
 int przew;
 int low;
 int high;
public:
 void SetFirstChord(RenderPart*,int);
 int GetDist(RenderPart*,int,int);
 void PlaceNextChord(RenderPart*,Time,Time);
 void render(RenderPart*);
};
#endif // SHORTESTWAYCHORDSSIMPLE_H
