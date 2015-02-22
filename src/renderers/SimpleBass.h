#ifndef SIMPLEBASS_H
#define SIMPLEBASS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class SimpleBass : public Renderer {
public:
 void render(RenderPart*);
};
#endif // SIMPLEBASS_H
