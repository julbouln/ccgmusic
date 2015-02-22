#ifndef SHORTESTWAYCHORDSSMOOTH_H
#define SHORTESTWAYCHORDSSMOOTH_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class ShortestWayChordsSmooth : public Renderer {
 int przew;
 int low;
 int high;
public:
 void SetFirstChord(RenderPart*,int);
 int GetDist(RenderPart*,int,int);
 void PlaceNextChord(RenderPart*,Time,Time,double);
 void render(RenderPart*);
};
#endif // SHORTESTWAYCHORDSSMOOTH_H
