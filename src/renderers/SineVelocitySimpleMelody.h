#ifndef SINEVELOCITYSIMPLEMELODY_H
#define SINEVELOCITYSIMPLEMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class SineVelocitySimpleMelody : public Renderer {
 int first_pitch;
 int last_pitch;
 double phase;
 double period;
 double vel_from;
 double vel_to;
public:
	SineVelocitySimpleMelody();
 void SetFirstPitch(int);
 int GetNextPitch(int);
 int GetVel(double);
 void render(RenderPart*);
};
#endif // SINEVELOCITYSIMPLEMELODY_H
