#ifndef MARCHPICOLO_H
#define MARCHPICOLO_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class MarchPicolo : public Renderer {
public:
 void render(RenderPart*);
};
#endif // MARCHPICOLO_H
