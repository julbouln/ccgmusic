#include "PianoAdvancedClassical.h"
string PianoAdvancedClassical::getScriptName() {
 return "Piano Advanced Classical";
}
int PianoAdvancedClassical::ArrangeClassical1(Song *s) {
 int bars = s->getBars();
 bool organs = false;
 if(this->rndInt(0,1) == 0) {
     s->addTrack("Melody",2,127,64,false);
     s->addTrack("Alt Voice",1,127,64,false);
     int a1 = this->rndInt(30,90);
     s->addTrack("Accomp",this->rndInt(1,2),125,a1,false);
     s->addTrack("Bass",this->rndInt(1,2),127,this->rndInt(30,90),false);
     s->addTrack("Chords",this->rndInt(1,2),127,this->rndInt(30,90),false);
     s->addTrack("Accomp2",this->rndInt(1,2),125,64 + (60 - a1),false);
 }
 else {
     int t,f;
     f = 7;
     t = 8;
     s->addTrack("Melody",this->rndInt(f,t),127,64,false);
     s->addTrack("Alt Voice",this->rndInt(f,t),127,64,false);
     int a1 = this->rndInt(30,90);
     s->addTrack("Accomp",this->rndInt(f,t),125,a1,false);
     s->addTrack("Bass",this->rndInt(f,t),127,this->rndInt(30,90),false);
     s->addTrack("Chords",this->rndInt(f,t),127,this->rndInt(30,90),false);
     s->addTrack("Accomp2",this->rndInt(f,t),125,64 + (60 - a1),false);
 }
 int *seeds = new int[5];
 int *off = new int[5];
 for(int i = 0;i < 5;++i ){
       seeds[i] = this->rndInt(0,INT_MAX);
       off[i] = this->rndInt(0,1);
 }
 int bass_seed = this->rndInt(0,INT_MAX);
 int bass_seed_chorus = this->rndInt(0,INT_MAX);
 string melody = "Simple Melody";
 if(this->rndInt(0,2) == 0) {
  melody = "Accented Melody";
 }
 for(int i = 0;i < s->getParts();++i ){
       if(s->getPart(i)->getArrHint() == 0) {
           s->addRenderEvent("Shortest Way Chords Simple",this->rndInt(0,INT_MAX),4,s->getPartStartBar(i),s->getPartEndBar(i) - 1,1,this->createTime(0,0),0.7);
           s->addRenderEvent("Arpeggio Chords",seeds[4],5,s->getPartStartBar(i),s->getPartEndBar(i) - 1,1 + off[0],this->createTime(0,0),0.7);
    }
    else {
     if(s->getPart(i)->getArrHint() == 1) {
             s->addRenderEvent(melody,this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
     }
     else {
      if(s->getPart(i)->getArrHint() == 2) {
               s->addRenderEvent(melody,this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),1,this->createTime(0,0),1);
      }
      else {
       if(s->getPart(i)->getArrHint() == 3) {
                 s->addRenderEvent("Chordal Melody",this->rndInt(0,INT_MAX),0,s->getPartStartBar(i),s->getPartEndBar(i),2 + this->rndInt(0,1),this->createTime(0,0),0.95);
                 s->addRenderEvent(melody,this->rndInt(0,INT_MAX),1,s->getPartStartBar(i),s->getPartEndBar(i),1 + this->rndInt(0,1),this->createTime(0,0),1);
                 s->addRenderEvent("Simple Chords",this->rndInt(0,INT_MAX),4,s->getPartStartBar(i),s->getPartEndBar(i) - 1,0,this->createTime(0,0),0.7);
                 s->addRenderEvent("Arpeggio Chords",this->rndInt(0,INT_MAX),5,s->getPartStartBar(i),s->getPartEndBar(i) - 1,1 + off[3],this->createTime(0,0),0.65);
       }
      }
     }
    }
       s->addRenderEvent("Arpeggio Chords",seeds[s->getPart(i)->getArrHint()],2,s->getPartStartBar(i),s->getPartEndBar(i) - 1,off[s->getPart(i)->getArrHint()],this->createTime(0,0),0.7);
       s->addRenderEvent("Simple Chords",this->rndInt(0,INT_MAX),4,s->getPartEndBar(i) - 1,s->getPartEndBar(i),1 + (seeds[s->getPart(i)->getArrHint()] % 2),this->createTime(0,0),0.8);
       if(s->getPart(i)->getArrHint() == 3) {
     s->addRenderEvent("Random Bass ( Extended )",bass_seed_chorus,3,s->getPartStartBar(i),s->getPartEndBar(i),-1,this->createTime(0,0),1.0);
    }
    else {
     s->addRenderEvent("Random Bass ( Extended )",bass_seed,3,s->getPartStartBar(i),s->getPartEndBar(i),this->rndInt(0,1),this->createTime(0,0),0.9);
    }
 }
 if(!organs) {
  s->addRenderEvent("Simple Chords Smooth",this->rndInt(0,INT_MAX),2,bars - 1,bars,3,this->createTime(0,s->getUniquePart(s->getPart(0)->getUniquePart())->getMetrum() / 2),0.8);
 }
 return 2;
}
void PianoAdvancedClassical::arrange(Song *s) {
 int style = this->rndInt(0,1);
 int slow = 0;
 if(style == 0) {
  slow = this->ArrangeClassical1(s);
 }
 if(style == 1) {
  slow = this->ArrangeClassical1(s);
 }
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
