#ifndef DRUMSSIMPLECYMBAL_H
#define DRUMSSIMPLECYMBAL_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class DrumsSimpleCymbal : public Renderer {
public:
 void render(RenderPart*);
};
#endif // DRUMSSIMPLECYMBAL_H
