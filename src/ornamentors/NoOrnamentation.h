#ifndef NOORNAMENTATION_H
#define NOORNAMENTATION_H
#include "Common.h"
#include "MusicScript.h"
#include "Ornamentor.h"
#include "UniquePart.h"
#include "Part.h"
using namespace std;
class NoOrnamentation : public Ornamentor {
public:
 void ornament(UniquePart*,Part*);
};
#endif // NOORNAMENTATION_H
