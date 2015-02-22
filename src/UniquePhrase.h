#ifndef UNIQUEPHRASE_H
#define UNIQUEPHRASE_H
#include "Common.h"
#include "Event.h"
#include "Time.h"
#include "Utils.h"
using namespace std;
class UniquePhrase {
 int metrum;
 int bars;
 vector<Event*> events;
 bool _startsPart;
 bool _endsPart;
 bool _startsSentence;
 bool _endsSentence;
 int id;
public:
 UniquePhrase();
 ~UniquePhrase();
 void setBars(int);
 int getBars();
 void setMetrum(int);
 int getMetrum();
 void setId(int);
 int getId();
 void setStartsPart(bool);
 bool startsPart();
 void setEndsPart(bool);
 bool endsPart();
 void setStartsSentence(bool);
 bool startsSentence();
 void setEndsSentence(bool);
 bool endsSentence();
 void addEvent(Time,Time);
 int getEvents();
 Event* getEvent(int);
};
#endif // UNIQUEPHRASE_H
