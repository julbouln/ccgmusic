#ifndef DRUMSDANCESNAREATTACK_H
#define DRUMSDANCESNAREATTACK_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class DrumsDanceSnareAttack : public Renderer {
public:
 void render(RenderPart*);
};
#endif // DRUMSDANCESNAREATTACK_H
