#ifndef QUICKINTROBASS_H
#define QUICKINTROBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class QuickIntroBass : public Renderer {
public:
 void render(RenderPart*);
};
#endif // QUICKINTROBASS_H
