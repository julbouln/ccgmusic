#ifndef DRUMSPUNKROCK_H
#define DRUMSPUNKROCK_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class DrumsPunkRock : public Renderer {
public:
 void DoFootAndSnare(RenderPart*);
 void DoChorusHiHat(RenderPart*,int);
 void DoIntroHiHat(RenderPart*);
 void DoTransition(RenderPart*);
 void render(RenderPart*);
};
#endif // DRUMSPUNKROCK_H
