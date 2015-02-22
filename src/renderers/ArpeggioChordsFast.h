#ifndef ARPEGGIOCHORDSFAST_H
#define ARPEGGIOCHORDSFAST_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class ArpeggioChordsFast : public Renderer {
 vector<int*> arp;
public:
 ~ArpeggioChordsFast();
 ArpeggioChordsFast();
 void render(RenderPart*);
};
#endif // ARPEGGIOCHORDSFAST_H
