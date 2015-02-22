#ifndef PERCUSSIONNOTE_H
#define PERCUSSIONNOTE_H
#include "Common.h"
#include "Time.h"
using namespace std;
class PercussionNote {
 Time start;
 Time end;
 int key;
 int volume;
 int trackIndex;

public:
 PercussionNote(Time,Time,int,int,int);
 void translate(int);
 void translate(Time);
 Time getStart();
 Time getEnd();
 int getKey();
 int getVolume();
 int getTrackIndex();

 class Comparator {
public:
bool operator()( const PercussionNote *lhs, const PercussionNote *rhs ) {
    Time lstart=(*lhs).start;
    Time rstart=(*rhs).start;
//    printf("sort %f < %f\n",(lstart.mBar + lstart.mPos), (rstart.mBar + rstart.mPos/4));
    return ((double)lstart.mBar + lstart.mPos/4) < ((double)rstart.mBar + rstart.mPos/4);
};
};
};
#endif // PERCUSSIONNOTE_H
