#ifndef FASTBASS_H
#define FASTBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class FastBass : public Renderer {
 int first_pitch;
 int last_pitch;
public:
 FastBass();
 void SetFirstPitch(int);
 int GetNextPitch(int);
 void render(RenderPart*);
};
#endif // FASTBASS_H
