#include "TempoMod.h"
TempoMod::TempoMod(Time pos,double mod) {
 this->pos = pos;
 this->mod = mod;
}
Time TempoMod::getPos() {
 return pos;
}
double TempoMod::getMod() {
 return mod;
}
