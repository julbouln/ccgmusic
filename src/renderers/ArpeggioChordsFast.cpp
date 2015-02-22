#include "ArpeggioChordsFast.h"

ArpeggioChordsFast::~ArpeggioChordsFast() {
  Utils::deleteVector(arp);
}

ArpeggioChordsFast::ArpeggioChordsFast() {
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

}
void ArpeggioChordsFast::render(RenderPart *p) {
 Time t = this->createTime(p->getStartBar(),0);
 double basic_tempo;
 if(p->getTempo() > 140) {
     basic_tempo = 0.5;
 }
 else {
     basic_tempo = 0.25;
 }
 double len = basic_tempo;
 int len_mode = this->rndInt(0,2);
 if(len_mode == 0) {
  len = basic_tempo;
 }
 if(len_mode == 1) {
  len = basic_tempo * 0.5;
 }
 if(len_mode == 2) {
  len = basic_tempo * 0.75;
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
     p->addNote(t,t2,p->getHarmonicEventPitch(p->getHarmonic(t),arp[a][note]),this->rndInt(100,125));
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
