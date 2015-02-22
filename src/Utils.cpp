#include "Utils.h"

int Utils::getRandomInt(int lowerBound,int upperBound) {
 int diff = upperBound - lowerBound;
 int rnd=rand() % (diff+1) + lowerBound;
// return Utils::clampIntToInt(rnd,lowerBound,upperBound);
 return rnd;
}

double Utils::getRandomBetween(double lower,double upper) {
  return lower + ((double)rand() / RAND_MAX) * (upper - lower);
}

bool Utils::contains(int arr[],int value) {
 if(arr != NULL) {
     for(int i = 0;i < Utils::arrayLength(arr);++i   ){
           if(arr[i] == value) {
               return true;
      }
   }
 }
 return false;
}

int Utils::positiveMod(int a,int b) {
 int result;
 if(a >= 0) {
     result = a % b;
 }
 else {
     result = (b + a % b) % b;
 }
 return result;
}

int Utils::clampIntToInt(int x,int a,int b) {
 return (x < a ? a : (x > b ? b : x));
}

  string Utils::intToString ( int n )
  {
     stringstream ss;
     ss << n;
     return ss.str();
  }
