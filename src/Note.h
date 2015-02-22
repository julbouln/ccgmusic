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
 Note(Time,Time,int,int,int,bool);
 void translate(int);
 void translate(Time);
 Time getStart();
 Time getEnd();
 int getPitch();
 int getVolume();
 int getTrackIndex();
 bool isPercussion();

  class Comparator {
public:
bool operator()( const Note *lhs, const Note *rhs ) {
    Time lstart=(*lhs).start;
    Time rstart=(*rhs).start;
//    printf("sort %f < %f\n",(lstart.mBar + lstart.mPos), (rstart.mBar + rstart.mPos/4));
    return ((double)lstart.mBar + lstart.mPos/4) < ((double)rstart.mBar + rstart.mPos/4);
};
};

};
#endif // NOTE_H
