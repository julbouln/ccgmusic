#ifndef RENDERER_H
#define RENDERER_H
#include "Common.h"
#include "Seedable.h"
#include "RenderPart.h"
#include "MusicScript.h"
using namespace std;
class Renderer : public MusicScript {
public:
 virtual ~Renderer() {};
 virtual void render(RenderPart*){};
};
#endif // RENDERER_H
