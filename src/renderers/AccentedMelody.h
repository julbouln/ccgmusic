#ifndef ACCENTEDMELODY_H
#define ACCENTEDMELODY_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class AccentedMelody : public Renderer {
public:
 void render(RenderPart*);
};
#endif // ACCENTEDMELODY_H
