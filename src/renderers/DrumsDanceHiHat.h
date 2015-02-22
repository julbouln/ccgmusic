#ifndef DRUMSDANCEHIHAT_H
#define DRUMSDANCEHIHAT_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class DrumsDanceHiHat : public Renderer {
public:
 void render(RenderPart*);
};
#endif // DRUMSDANCEHIHAT_H
