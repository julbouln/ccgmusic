#ifndef DRUMSMARCH_H
#define DRUMSMARCH_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class DrumsMarch : public Renderer {
public:
 void DoSnare(RenderPart*);
 void DoFoot(RenderPart*);
 void DoCymbal(RenderPart*);
 void render(RenderPart*);
};
#endif // DRUMSMARCH_H
