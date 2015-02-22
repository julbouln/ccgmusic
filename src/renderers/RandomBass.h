#ifndef RANDOMBASS_H
#define RANDOMBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class RandomBass : public Renderer {
 int first_pitch;
 int last_pitch;
public:
	RandomBass();
 void SetFirstPitch(int);
 int GetNextPitch(int);
 void render(RenderPart*);
};
#endif // RANDOMBASS_H
