#ifndef BOOGIEWOOGIE_H
#define BOOGIEWOOGIE_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class BoogieWoogie : public Renderer {
public:
 void render(RenderPart*);
};
#endif // BOOGIEWOOGIE_H
