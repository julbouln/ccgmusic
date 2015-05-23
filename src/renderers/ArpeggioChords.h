#ifndef ARPEGGIOCHORDS_H
#define ARPEGGIOCHORDS_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class ArpeggioChords : public Renderer {
	vector<vector<int> > arp;
public:
 ArpeggioChords();
 void render(RenderPart*);
};
#endif // ARPEGGIOCHORDS_H
