#ifndef DRUMSLATIN_H
#define DRUMSLATIN_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "Time.h"
#include "RenderPart.h"
using namespace std;
class DrumsLatin : public Renderer {
public:
 int GetVel(Time);
 void RealizePattern(RenderPart*,double,vector<double>,int,int);
 void SpeedUpPattern(vector<double>);
 void render(RenderPart*);
};
#endif // DRUMSLATIN_H
