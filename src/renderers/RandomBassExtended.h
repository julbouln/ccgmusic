#ifndef RANDOMBASSEXTENDED_H
#define RANDOMBASSEXTENDED_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class RandomBassExtended : public Renderer {
 int first_pitch;
 int last_pitch;
public:
	RandomBassExtended();
 void SetFirstPitch(int);
 int GetNextPitch(int);
 void render(RenderPart*);
};
#endif // RANDOMBASSEXTENDED_H
