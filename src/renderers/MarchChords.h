#ifndef MARCHCHORDS_H
#define MARCHCHORDS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class MarchChords : public Renderer {
public:
 void PlaceNextChord(RenderPart*,Time);
 void render(RenderPart*);
};
#endif // MARCHCHORDS_H
