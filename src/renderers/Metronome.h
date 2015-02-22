#ifndef METRONOME_H
#define METRONOME_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
using namespace std;
class Metronome : public Renderer {
public:
 void render(RenderPart*);
};
#endif // METRONOME_H
