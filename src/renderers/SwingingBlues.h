#ifndef SWINGINGBLUES_H
#define SWINGINGBLUES_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class SwingingBlues : public Renderer {
public:
 void render(RenderPart*);
};
#endif // SWINGINGBLUES_H
