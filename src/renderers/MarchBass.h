#ifndef MARCHBASS_H
#define MARCHBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class MarchBass : public Renderer {
public:
 void render(RenderPart*);
};
#endif // MARCHBASS_H
