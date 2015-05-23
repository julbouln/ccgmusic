#include "DrumsLatin.h"
int DrumsLatin::GetVel(Time t) {
 return this->rndInt(110,126);
}
void DrumsLatin::RealizePattern(RenderPart *p,double len,vector<double> pat,int pitch,int vel_off) {
 for(int i = p->getStartBar();i < p->getEndBar();++i ){
       for(double m = 0;m < p->getUniquePart()->getMetrum();m += len    ){
             for(int n = 0;n < pat.size();++n       ){
                   if(pat[n] + m < p->getUniquePart()->getMetrum()) {
                       p->addPercNote(this->createTime(i,m + pat[n]),this->createTime(i,m + pat[n] + 0.125),pitch,this->rndInt(100,120) + vel_off);
          }
       }
    }
 }
}
void DrumsLatin::SpeedUpPattern(vector<double> pat) {
 for(int i = 0;i < pat.size();++i ){
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
     this->SpeedUpPattern(Utils::arrayToVector(foot_pattern,4));
     this->SpeedUpPattern(Utils::arrayToVector(stick_pattern,4));
     this->SpeedUpPattern(Utils::arrayToVector(shaker1_pattern,4));
     this->SpeedUpPattern(Utils::arrayToVector(shaker2_pattern,1));
     this->SpeedUpPattern(Utils::arrayToVector(shaker3_pattern,1));
     this->SpeedUpPattern(Utils::arrayToVector(bebenek1_pattern,1));
     this->SpeedUpPattern(Utils::arrayToVector(bebenek2_pattern,1));
 }
 this->RealizePattern(p,pattern_length,Utils::arrayToVector(foot_pattern,4),this->rndInt(35,36),5);
 this->RealizePattern(p,pattern_length,Utils::arrayToVector(stick_pattern,4),37,5);
 this->RealizePattern(p,pattern_length,Utils::arrayToVector(shaker1_pattern,4),36 + 33,0);
 this->RealizePattern(p,pattern_length,Utils::arrayToVector(shaker2_pattern,1),36 + 33 + 13,-25);
 if(this->rndInt(0,1) == 0) {
  this->RealizePattern(p,shaker3_length,Utils::arrayToVector(shaker3_pattern,1),36 + 6,-30);
 }
 else {
  this->RealizePattern(p,shaker3_length,Utils::arrayToVector(shaker3_pattern,1),36 + 18,-30);
 }
 if(this->rndInt(0,1) == 0) {
     this->RealizePattern(p,bebenek_length,Utils::arrayToVector(bebenek1_pattern,1),36 + 28,-5);
     this->RealizePattern(p,bebenek_length,Utils::arrayToVector(bebenek2_pattern,1),36 + 26,-6);
 }
}
