#include "DrumsLatin.h"
int DrumsLatin::GetVel(Time t) {
 return this->rndInt(110,126);
}
void DrumsLatin::RealizePattern(RenderPart *p,double len,double pat[],int pitch,int vel_off) {
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += len    ){
             for(int n = 0;n < Utils::arrayLength(pat);++n       ){
                   if(pat[n] + m < p->getUniquePart()->getMetrum()) {
                       p->addPercNote(this->createTime(i,m + pat[n]),this->createTime(i,m + pat[n] + 0.125),pitch,this->rndInt(100,120) + vel_off);
          }
       }
    }
 }
}
void DrumsLatin::SpeedUpPattern(double pat[]) {
 for(int i = 0;i < Utils::arrayLength(pat);++i ){
       pat[i] /= 2.0;
 }
}
void DrumsLatin::render(RenderPart *p) {
 double pattern_length = 4;
 double foot_pattern[] = {0,1.5,2.0,3.5};
 double stick_pattern[] = {0,1,2.5,3.5};
 double shaker1_pattern[] = {0.5,1.5,2.5,3.5};
 double shaker2_pattern[] = {1,3};
 double bebenek1_pattern[] = {0};
 double bebenek2_pattern[] = {0.5};
 double shaker3_length = 0.5;
 double bebenek_length = 1.0;
 if(this->rndInt(0,2) == 0) {
  shaker3_length = 1.0;
 }
 double shaker3_pattern[] = {0};
 if(p->getTempo() < 80) {
     pattern_length /= 2;
     shaker3_length /= 2;
     bebenek_length /= 2;
     this->SpeedUpPattern(foot_pattern);
     this->SpeedUpPattern(stick_pattern);
     this->SpeedUpPattern(shaker1_pattern);
     this->SpeedUpPattern(shaker2_pattern);
     this->SpeedUpPattern(shaker3_pattern);
     this->SpeedUpPattern(bebenek1_pattern);
     this->SpeedUpPattern(bebenek2_pattern);
 }
 this->RealizePattern(p,pattern_length,foot_pattern,this->rndInt(35,36),5);
 this->RealizePattern(p,pattern_length,stick_pattern,37,5);
 this->RealizePattern(p,pattern_length,shaker1_pattern,36 + 33,0);
 this->RealizePattern(p,pattern_length,shaker2_pattern,36 + 33 + 13,-25);
 if(this->rndInt(0,1) == 0) {
  this->RealizePattern(p,shaker3_length,shaker3_pattern,36 + 6,-30);
 }
 else {
  this->RealizePattern(p,shaker3_length,shaker3_pattern,36 + 18,-30);
 }
 if(this->rndInt(0,1) == 0) {
     this->RealizePattern(p,bebenek_length,bebenek1_pattern,36 + 28,-5);
     this->RealizePattern(p,bebenek_length,bebenek2_pattern,36 + 26,-6);
 }
}
