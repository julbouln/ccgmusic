#ifndef DRUMEUCLIDEAN_H
#define DRUMEUCLIDEAN_H
#include "Common.h"
#include "MusicScript.h"
#include "Renderer.h"
#include "RenderPart.h"
#include "Time.h"
using namespace std;
class DrumsEuclidean : public Renderer {
public:
 int *distribute(int,int);

 void render(RenderPart*);
};
#endif // DRUMEUCLIDEAN_H
