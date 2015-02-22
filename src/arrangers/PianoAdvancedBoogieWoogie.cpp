#include "PianoAdvancedBoogieWoogie.h"
string PianoAdvancedBoogieWoogie::getScriptName() {
 return "Piano Advanced Boogie Woogie";
}
int PianoAdvancedBoogieWoogie::ArrangeBoogieWoogie(Song *s) {
 int bars = s->getBars();
 s->addTrack("Melody",this->rndInt(2,4),127,64,false);
 s->addTrack("Alt Voice",this->rndInt(1,4),127,64,false);
 s->addTrack("Accomp",this->rndInt(1,4),127,64,false);
 s->addTrack("Chorus Intro",this->rndInt(1,4),127,64,false);
 string bw = "Boogie Woogie";
 if(this->rndInt(0,1) == 0) {
  bw += " Swing";
 }
 int bw_seed = this->rndInt(0,32000);
 int bw_seed_chorus = this->rndInt(0,32000);
 int bw_seed_alt = this->rndInt(0,32000);
 int chor_off = this->rndInt(0,1);
 int intro_seed = this->rndInt(0,32000);
 string melody = "Simple Melody";
 if(this->rndInt(0,2) == 0) {
  melody = "Accented Melody";
 }
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 0) {
           s->addRenderEvent("Simple Chords",this->rndInt(0,32000),1,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),0.8);
           s->addRenderEvent(bw,bw_seed,2,s->getPartStartBar(i),s->getPartEndBar(i) - 1,-1 + this->rndInt(0,1),this->createTime(0,0),1.0);
    }
       if(s->getPart(i)->getArrHint() == 1) {
           s->addRenderEvent(melody,this->rndInt(0,32000),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
           s->addRenderEvent(bw,bw_seed,2,s->getPartStartBar(i),s->getPartEndBar(i) - 1,-1,this->createTime(0,0),1.0);
    }
       if(s->getPart(i)->getArrHint() == 2) {
           s->addRenderEvent(melody,this->rndInt(0,32000),1,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
           s->addRenderEvent(bw,bw_seed_alt,2,s->getPartStartBar(i),s->getPartEndBar(i) - 1,-1,this->createTime(0,0),1.0);
    }
       if(s->getPart(i)->getArrHint() == 3) {
           s->addRenderEvent("Chordal Melody",this->rndInt(0,32000),0,s->getPartStartBar(i),s->getPartEndBar(i),2,this->createTime(0,0),1);
           s->addRenderEvent(bw,bw_seed_chorus,2,s->getPartStartBar(i),s->getPartEndBar(i) - 1,chor_off,this->createTime(0,0),1.0);
           s->addRenderEvent(bw,bw_seed_chorus,2,s->getPartStartBar(i),s->getPartEndBar(i) - 1,-1,this->createTime(0,0),1.0);
           s->addRenderEvent("Quick Intro Bass",intro_seed,3,s->getPartStartBar(i),s->getPartStartBar(i) + 1,-1,this->createTime(0,0),1.0);
    }
       s->addRenderEvent("Simple Chords",this->rndInt(0,32000),2,s->getPartEndBar(i) - 1,s->getPartEndBar(i),0,this->createTime(0,0),0.8);
       if(i == s->getParts() - 1) {
           s->addRenderEvent("Simple Chords",this->rndInt(0,32000),2,s->getPartEndBar(i) - 1,s->getPartEndBar(i),2,this->createTime(0,0),0.8);
           s->addRenderEvent("Simple Chords Smooth",this->rndInt(0,32000),2,s->getPartEndBar(i) - 1,s->getPartEndBar(i),3,this->createTime(0,s->getUniquePart(s->getPart(i)->getUniquePart())->getMetrum() / 2),0.8);
    }
    else {
           s->addRenderEvent("Simple Chords",this->rndInt(0,32000),2,s->getPartEndBar(i) - 1,s->getPartEndBar(i),1,this->createTime(0,s->getUniquePart(s->getPart(i)->getUniquePart())->getMetrum() / 2),0.75);
    }
 }
 return 1;
}
void PianoAdvancedBoogieWoogie::arrange(Song *s) {
 int style = this->rndInt(0,1);
 int slow;
 slow = this->ArrangeBoogieWoogie(s);
 if(slow > 0) {
     int bars = 0;
     for(int i = 0;i < s->getParts();++i   ){
           double metrum = s->getUniquePart(s->getPart(i)->getUniquePart())->getMetrum();
           bars += s->getUniquePart(s->getPart(i)->getUniquePart())->getBars();
           if(i == s->getParts() - 1) {
               s->addTempoMod(this->createTime(bars - 2,metrum / 3),0.95);
               s->addTempoMod(this->createTime(bars - 2,(metrum / 3) * 2),0.90);
               s->addTempoMod(this->createTime(bars - 1,0),0.8);
      }
      else {
       if(slow > 1) {
                 s->addTempoMod(this->createTime(bars - 2,metrum / 3),0.95);
                 s->addTempoMod(this->createTime(bars - 2,(metrum / 3) * 2),0.90);
                 s->addTempoMod(this->createTime(bars - 1,0),0.85);
                 s->addTempoMod(this->createTime(bars - 1,metrum - 1),0.95);
       }
      }
   }
 }
}
