#ifndef SIMPLECHORDSSMOOTH_H
#define SIMPLECHORDSSMOOTH_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class SimpleChordsSmooth : public Renderer {
public:
 void render(RenderPart*);
};
#endif // SIMPLECHORDSSMOOTH_H
