#include "Utils.h"

int Utils::getRandomInt(int lowerBound,int upperBound) {
 int diff = upperBound - lowerBound;
 int rnd=rand() % (diff+1) + lowerBound;
// return Utils::clampIntToInt(rnd,lowerBound,upperBound);
 return rnd;
}

double Utils::getRandomDouble() {
  return (double)rand() / RAND_MAX;
};

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

string Utils::midiToNote(int n) {
  switch(n % 12) {
    case 0:
      return "C";
    case 1:
      return "C#";
    case 2:
      return "D";
    case 3:
      return "D#";
    case 4:
      return "E";
    case 5:
      return "F";
    case 6:
      return "F#";
    case 7:
      return "G";
    case 8:
      return "G#";
    case 9:
      return "A";
    case 10:
      return "A#";
    case 11:
      return "B";
  }
}

string Utils::midiToNoteFr(int n) {
  switch(n % 12) {
    case 0:
      return "do";
    case 1:
      return "do#";
    case 2:
      return "re";
    case 3:
      return "re#";
    case 4:
      return "mi";
    case 5:
      return "fa";
    case 6:
      return "fa#";
    case 7:
      return "sol";
    case 8:
      return "sol#";
    case 9:
      return "la";
    case 10:
      return "la#";
    case 11:
      return "si";
  }
}