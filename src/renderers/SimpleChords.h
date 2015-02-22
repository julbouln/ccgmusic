#ifndef SIMPLECHORDS_H
#define SIMPLECHORDS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class SimpleChords : public Renderer {
public:
 void render(RenderPart*);
};
#endif // SIMPLECHORDS_H
