#include "ArpeggioChords.h"

ArpeggioChords::ArpeggioChords() {
  arp.push_back(new int[4] { 0, 2, 1, 2 });
  arp.push_back(new int[4] { 0, 1, 2, 1 });
  arp.push_back(new int[4] { 0, 1, 2, 3 });
  arp.push_back(new int[4] { 0, 1, 2, 3 });
  arp.push_back(new int[4] { 2, 0, 3, 0 });
  arp.push_back(new int[4] { 2, 0, 1, 0 });
  arp.push_back(new int[6] { 0, 1, 2, 3, 2, 1 });
  arp.push_back(new int[3] { 0, 1, 2 });
  arp.push_back(new int[3] { 0, 2, 3 });
  arp.push_back(new int[3] { 0, 2, 4 });
  arp.push_back(new int[8] { 0, 1, 2, 3, 4, 5, 6, 7 });

/*  { { 0, 2, 1, 2 }, { 0, 1, 2, 1 }, { 0, 1, 2, 3 },
      { 0, 1, 2, 3 }, { 2, 0, 3, 0 }, { 2, 0, 1, 0 },
      { 0, 1, 2, 3, 2, 1 }, { 0, 1, 2 }, { 0, 2, 3 }, { 0, 2, 4 },
      { 0, 1, 2, 3, 4, 5, 6, 7 } } */
}
void ArpeggioChords::render(RenderPart *p) {
 Time t = this->createTime(p->getStartBar(),0);
 double basic_tempo = 1.0;
 int tempo = this->rndInt(0,1);
 if(p->getTempo() > 110) {
     if(tempo == 0) {
    basic_tempo = 1;
   }
     if(tempo == 1) {
    basic_tempo = 0.5;
   }
     if(p->getTempo() > 220) {
    basic_tempo = 1;
   }
 }
 else {
     if(tempo == 0) {
    basic_tempo = 0.5;
   }
     if(tempo == 1) {
    basic_tempo = 0.25;
   }
     if(p->getTempo() < 65) {
    basic_tempo = 0.25;
   }
 }
 double len = basic_tempo;
 int len_mode = this->rndInt(0,3);
 if(len_mode == 0) {
  len = basic_tempo;
 }
 if(len_mode == 1) {
  len = basic_tempo * 1.5;
 }
 if(len_mode == 2) {
  len = basic_tempo * 0.95;
 }
 if(len_mode == 3) {
  len = basic_tempo * 0.85;
 }
 int a = this->rndInt(0,arp.size() - 1);
 int note = 0;
 int old_nhp = -1;
 int reset_on_bar = this->rndInt(0,1);
 int reset_on_chord_change = this->rndInt(0,1);
 while(t.mBar < p->getEndBar()){
     Time t2 = Time(0,0);
     t2.mBar = t.mBar;
     t2.mPos = t.mPos + len;
     int nnhp = p->getHarmonicEventPitch(p->getHarmonic(t),0);
     if(nnhp != old_nhp && reset_on_chord_change == 1) {
         note = 0;
         old_nhp = nnhp;
   }
     p->addNote(t,t2,p->getHarmonicEventPitch(p->getHarmonic(t),arp[a][note]),127);
     note = (note + 1) % Utils::arrayLength(arp[a]);
     t.mPos += basic_tempo;
     if(t.mPos >= p->getUniquePart()->getMetrum()) {
         ++t.mBar;
         t.mPos = 0;
         if(reset_on_bar == 1) {
      note = 0;
     }
   }
 }
}
