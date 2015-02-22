#ifndef SIMPLEMELODY_H
#define SIMPLEMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class SimpleMelody : public Renderer {
public:
 void render(RenderPart*);
};
#endif // SIMPLEMELODY_H
