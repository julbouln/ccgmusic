#ifndef LATINBASS_H
#define LATINBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class LatinBass : public Renderer {
public:
 void render(RenderPart*);
};
#endif // LATINBASS_H
