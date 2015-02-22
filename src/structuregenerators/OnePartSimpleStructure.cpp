#include "OnePartSimpleStructure.h"
void OnePartSimpleStructure::generateStructure(Song *song) {
 song->setUniqueParts(1);
 song->setParts(1);
 song->getPart(0)->setUniquePart(0);
}
