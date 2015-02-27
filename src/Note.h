#ifndef NOTE_H
#define NOTE_H
#include "Common.h"
#include "Time.h"
using namespace std;
class Note {
 Time start;
 Time end;
 int8_t pitch;
 int8_t volume;
 int8_t trackIndex;
 bool percussion;
public:
 ~Note();
 Note(Time,Time,int8_t,int8_t,int8_t,bool);
 void translate(int);
 void translate(Time);
 Time getStart();
 Time getEnd();
 int8_t getPitch();
 int8_t getVolume();
 int8_t getTrackIndex();
 bool isPercussion();

  class Comparator {
public:
bool operator()( const Note *lhs, const Note *rhs ) {
    Time lstart=(*lhs).start;
    Time rstart=(*rhs).start;
    long offl = (long)(192 * (lstart.mBar + lstart.mPos / 4)) + 192;
      long offr = (long)(192 * (rstart.mBar + rstart.mPos / 4)) + 192;
//      printf("sort %ld < %ld\n",offl,offr);
//    printf("sort %f < %f\n",192+((float)lstart.mBar + lstart.mPos/4), 192+((float)rstart.mBar + rstart.mPos/4));
    return offl < offr;
};
};

};
#endif // NOTE_H
