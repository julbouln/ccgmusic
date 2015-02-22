#ifndef LIGHTRANDOMIZER_H
#define LIGHTRANDOMIZER_H
#include "Common.h"
#include "MusicScript.h"
#include "Ornamentor.h"
#include "UniquePart.h"
#include "Part.h"
#include "Time.h"
using namespace std;
class LightRandomizer : public Ornamentor {
public:
 void ornament(UniquePart*,Part*);
};
#endif // LIGHTRANDOMIZER_H
