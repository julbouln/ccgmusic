#include "ModernSongStructure.h"
void ModernSongStructure::generateStructure(Song* s) {
  int intro_mode = this->rndInt(0, 4);
  int start_with = this->rndInt(-2, 1);
  if (start_with < 0) {
    start_with = 0;
  }
  if (intro_mode == 1) {
    start_with = 1;
  }
  if (intro_mode == 2) {
    start_with = 0;
  }
  int bridge_mode = this->rndInt(0, 2);
  int after_bridge = this->rndInt(0, 1);
  int u_parts = 3;
  int bridge = 2;
  int verse = 0;
  int chorus = 1;
  if (intro_mode > 2) {
    verse++;
    chorus++;
    bridge++;
    u_parts++;
  }
  s->setUniqueParts(u_parts);
  int metrum = 4;
  if (this->rndInt(0, 5) == 0) {
    int m = this->rndInt(0, 4);
    switch(m) {
      case 0:
        metrum = 2;
        break;
      case 1:
        metrum = 3;
        break;
      case 2:
        metrum = 4;
        break;
      case 3:
        metrum = 5;
        break;
      case 4:
        metrum = 6;
        break;
    }

//    printf("METRUM %d\n",metrum);
  }
  for (int i = 0; i < u_parts; i++) {
    s->getUniquePart(i)->setMetrum(metrum);
  }
  if (intro_mode == 3) {
    s->getUniquePart(0)->setScriptStructure(s->getUniquePart(1)->getScriptStructure());
    s->getUniquePart(0)->setScriptStructureSeed(s->getUniquePart(1)->getScriptStructureSeed());
  }
  else {
    if (intro_mode == 4) {
      s->getUniquePart(0)->setScriptStructure(s->getUniquePart(2)->getScriptStructure());
      s->getUniquePart(0)->setScriptStructureSeed(s->getUniquePart(2)->getScriptStructureSeed());
    }
  }
  if (bridge_mode == 0) {
    s->getUniquePart(bridge)->setScriptStructure(s->getUniquePart(verse)->getScriptStructure());
    s->getUniquePart(bridge)->setScriptStructureSeed(s->getUniquePart(verse)->getScriptStructureSeed());
  }
  else {
    if (bridge_mode == 1) {
      s->getUniquePart(bridge)->setScriptStructure(s->getUniquePart(chorus)->getScriptStructure());
      s->getUniquePart(bridge)->setScriptStructureSeed(s->getUniquePart(chorus)->getScriptStructureSeed());
    }
  }
  int parts = 7;
  if (intro_mode > 0) {
    ++parts;
  }
  if (start_with > 0) {
    ++parts;
  }
  if (after_bridge == 0) {
    ++parts;
  }
  int mangle_ending = this->rndInt(0, 1);
  if (mangle_ending > 0) {
    ++parts;
  }
  int scale = this->getRandomScale();
  int trans = this->rndInt(0, 11);
  s->setParts(parts);
  for (int i = 0; i < parts; i++) {
    s->getPart(i)->setTempoMod(1.0);
    s->getPart(i)->setScale(scale);
    s->getPart(i)->setTranspose(trans);
  }
  int part = 0;
  if (intro_mode == 1) {
    s->getPart(0)->setUniquePart(0);
    s->getPart(0)->setArrHint(0);
    ++part;
  }
  else {
    if (intro_mode == 2) {
      s->getPart(0)->setUniquePart(1);
      s->getPart(0)->setArrHint(0);
      ++part;
    }
    else {
      if (intro_mode > 2) {
        s->getPart(0)->setUniquePart(0);
        s->getPart(0)->setArrHint(this->rndInt(0, 3));
        ++part;
      }
    }
  }
  int first_verse = part;
  if (start_with > 0) {
    ++first_verse;
  }
  for (int i = 0; i < 2; i++) {
    s->getPart(first_verse + (i * 2))->setUniquePart(verse);
    s->getPart(first_verse + (i * 2))->setArrHint(1);
  }
  if (after_bridge == 0) {
    s->getPart(first_verse + 5)->setUniquePart(verse);
    s->getPart(first_verse + 5)->setArrHint(1);
  }
  s->getPart(first_verse + 4)->setUniquePart(bridge);
  s->getPart(first_verse + 4)->setArrHint(3);
  s->getPart(first_verse + 4)->setTranspose((trans + 5) % 12);
  s->getPart(first_verse + 4)->setScale(this->getRandomScale());
  if (start_with > 0) {
    s->getPart(part)->setUniquePart(chorus);
    s->getPart(part)->setArrHint(3);
  }
  for (int i = 0; i < 2; i++) {
    s->getPart(first_verse + (i * 2) + 1)->setUniquePart(chorus);
    s->getPart(first_verse + (i * 2) + 1)->setArrHint(3);
  }
  if (after_bridge == 0) {
    ++first_verse;
  }
  s->getPart(first_verse + 5)->setUniquePart(chorus);
  s->getPart(first_verse + 5)->setArrHint(3);
  s->getPart(first_verse + 6)->setUniquePart(chorus);
  s->getPart(first_verse + 6)->setArrHint(3);
  if (mangle_ending > 0) {
    trans = (trans + this->rndInt(1, 3)) % 12;
    s->getPart(first_verse + 7)->setUniquePart(chorus);
    s->getPart(first_verse + 7)->setArrHint(3);
    s->getPart(first_verse + 7)->setTranspose(trans);
    s->getPart(first_verse + 6)->setTranspose(trans);
  }
}
