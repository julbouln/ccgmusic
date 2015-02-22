#ifndef BOOGIEWOOGIESWING_H
#define BOOGIEWOOGIESWING_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class BoogieWoogieSwing : public Renderer {
public:
 void render(RenderPart*);
};
#endif // BOOGIEWOOGIESWING_H
