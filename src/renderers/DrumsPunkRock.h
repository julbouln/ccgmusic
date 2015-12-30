#ifndef DRUMSPUNKROCK_H
#define DRUMSPUNKROCK_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class DrumsPunkRock : public Renderer {
public:
 void DoFootAndSnare(RenderPart*,int,int);
 void DoChorusHiHat(RenderPart*,int);
 void DoIntroHiHat(RenderPart*,int);
 void DoTransition(RenderPart*,int,int);
 void render(RenderPart*);
};
#endif // DRUMSPUNKROCK_H
