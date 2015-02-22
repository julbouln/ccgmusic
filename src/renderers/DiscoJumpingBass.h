#ifndef DISCOJUMPINGBASS_H
#define DISCOJUMPINGBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class DiscoJumpingBass : public Renderer {
public:
 void render(RenderPart*);
};
#endif // DISCOJUMPINGBASS_H
